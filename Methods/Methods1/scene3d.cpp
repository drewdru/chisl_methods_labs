#include <QtGui>      // подключаем модуль QtGui
#include <math.h>     // подключаем математическую библиотеку
#include "scene3d.h"  // подключаем заголовочный файл scene3D.h
#include "glext.h"    // подключаем заголовочный файл glext.h

///* в версии 1.2 */
//#ifndef GL_CLAMP_TO_EDGE
//#define GL_CLAMP_TO_EDGE 0x812F
//#endif

///* в версии 1.3 */
//#ifndef GL_MULTISAMPLE
//#define GL_MULTISAMPLE  0x809D
//#endif

const GLfloat pi=3.141593, k=pi/180; // глобальная переменная

GLint viewport[4]; // декларируем матрицу поля просмотра

GLfloat VertexArray[6][3];  // декларируем массив вершин
GLfloat TextureArray[6][2]; // декларируем массив текстурных координат
GLuint IndexArray[8][3];    // декларируем массив индексов вершин
GLuint textureID[2];        // декларируем массив текстурных объектов (id текстур)

GLint signs[2]={1, 1}; // массив знаков +1 или -1 (понадобятся при трансляции)
bool motionParameters[2]={1, 1}; // массив параметров, определяющих движение
int textureParameters[2]={0, 1}; // массив индексов массива текстурных ID

// конструктор класса Scene3D:
Scene3D::Scene3D(QWidget* parent/*= 0*/) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
   // начальные значения
   xRot1=-90.0f; yRot1=0.0f; zRot1=0.0f; zTra1=0.0f;
   xRot2=-90.0f; yRot2=0.0f; zRot2=0.0f; zTra2=0.0f;

   timer = new QTimer(this); // создаём таймер
   // связываем сигналы и слоты:
   connect(timer, SIGNAL(timeout()), this, SLOT(change()));
   timer->start(10); // запускаем таймер

   // синхронизация кадров с дисплеем:
   QGLFormat frmt; // создать формат по умолчанию
   frmt.setSwapInterval(1); // установить синхронизацию в формат
   setFormat(frmt); // установить формат в контекст
}

Scene3D::~Scene3D() // деструктор
{

}

void Scene3D::initializeGL() // инициализация
{
   // цвет для очистки буфера изображения - будет просто фон окна
   qglClearColor(Qt::black);
   // устанавливаем режим проверки глубины пикселей
   glEnable(GL_DEPTH_TEST);
   // устанавливаем режим, когда строятся только внешние поверхности
   glEnable(GL_CULL_FACE);
   // установливаем режим двумерных текстур
   glEnable(GL_TEXTURE_2D);
   // включаем мультивыборку
   glEnable(GL_MULTISAMPLE);

   getVerTexArrays(); // определить массив вершин и текстурных координат
   getIndexArray();   // определить массив индексов вершин
   genTextures();     // создать текстуры

   // активизируем массив вершин
   glEnableClientState(GL_VERTEX_ARRAY);
   // активизируем массив текстурных координат
   glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Scene3D::resizeGL(int nWidth, int nHeight) // окно виджета
{
   // устанавливаем текущей проекционную матрицу
   glMatrixMode(GL_PROJECTION);
   // присваиваем проекционной матрице единичную матрицу
   glLoadIdentity();

   // отношение высоты окна виджета к его ширине
   ratio=(GLfloat)nHeight/(GLfloat)nWidth;

   // мировое окно
   if (nWidth>=nHeight)
      // параметры видимости ортогональной проекции:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   // поле просмотра
   glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);

   // извлекаем матрицу поля просмотра в viewport
   glGetIntegerv(GL_VIEWPORT, viewport);
}

void Scene3D::paintGL() // рисование
{
   // очищаем буферы изображения и глубины
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // устанавливаем матрицу моделирования текущей
   glMatrixMode(GL_MODELVIEW);
   // загружаем единичную матрицу в матрицу моделирования
   glLoadIdentity();

   // помещаем матрицу моделирования в стек матриц
   glPushMatrix();
      glTranslatef(-1.0f/ratio, zTra1, 0.0f); // трансляция
      glRotatef(xRot1, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
      glRotatef(yRot1, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
      glRotatef(zRot1, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
      // выбираем текстуру для наложения:
      glBindTexture(GL_TEXTURE_2D, textureID[textureParameters[0]]);
      drawFigure(); // нарисовать фигуру
   // извлекаем матрицу моделирования из стека матриц
   glPopMatrix();

   // помещаем матрицу моделирования в стек матриц
   glPushMatrix();
      glTranslatef(1.0f/ratio, zTra2, 0.0f); // трансляция
      glRotatef(xRot2, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
      glRotatef(yRot2, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
      glRotatef(zRot2, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
      // выбираем текстуру для наложения:
      glBindTexture(GL_TEXTURE_2D, textureID[textureParameters[1]]);
      drawFigure(); // нарисовать фигуру
   // извлекаем матрицу моделирования из стека матриц
   glPopMatrix();
}

void Scene3D::mousePressEvent(QMouseEvent* pe) // нажатие клавиши мыши
{
   // при нажатии пользователем кнопки мыши переменной mousePosition будет
   QPoint mousePosition = pe->pos(); // присвоена координата указателя мыши

   this->selectFigures(mousePosition); // выбрать фигуру
}

void Scene3D::genTextures() // создаём текстуры
{
   // создаём, связываем, загружаем, возвращаем уникальный номер:
   textureID[0]=bindTexture(QPixmap(QString(":/textures/HumanWarrior.png")), GL_TEXTURE_2D);
   // далее параметры текстурного объекта
   // при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   // при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   // цвет текселя полностью замещает цвет фрагмента фигуры
   // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

   // создаём, связываем, загружаем, возвращаем уникальный номер:
   textureID[1]=bindTexture(QPixmap(QString(":/textures/OrcMage.png")), GL_TEXTURE_2D);
   // далее параметры текстурного объекта
   // при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   // при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   // цвет текселя полностью замещает цвет фрагмента фигуры
   // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void Scene3D::getVerTexArrays() // определить массив вершин и текстурных координат
{
   GLfloat R=1.0f; // радиус сферы
   GLfloat alpha=pi/2;

   // вычисляем точки
   //0 точка
   VertexArray[0][0]=0.0f; // x
   VertexArray[0][1]=0.0f; // y
   VertexArray[0][2]=R;    // z

   TextureArray[0][0]=0.5f; // x (s)
   TextureArray[0][1]=1.0f; // y (t)

   //1 точка
   VertexArray[1][0]=R*sin(alpha)*sin(0);
   VertexArray[1][1]=R*sin(alpha)*cos(0);
   VertexArray[1][2]=R*cos(alpha);

   TextureArray[1][0]=1.0f;
   TextureArray[1][1]=0.0f;

   //2 точка
   VertexArray[2][0]=R*sin(alpha)*sin(pi/2);
   VertexArray[2][1]=R*sin(alpha)*cos(pi/2);
   VertexArray[2][2]=R*cos(alpha);

   TextureArray[2][0]=0.0f;
   TextureArray[2][1]=0.0f;

   //3 точка
   VertexArray[3][0]=R*sin(alpha)*sin(pi);
   VertexArray[3][1]=R*sin(alpha)*cos(pi);
   VertexArray[3][2]=R*cos(alpha);

   TextureArray[3][0]=1.0f;
   TextureArray[3][1]=0.0f;

   //4 точка
   VertexArray[4][0]=R*sin(alpha)*sin(3*pi/2);
   VertexArray[4][1]=R*sin(alpha)*cos(3*pi/2);
   VertexArray[4][2]=R*cos(alpha);

   TextureArray[4][0]=0.0f;
   TextureArray[4][1]=0.0f;

   //5 точка
   VertexArray[5][0]=0.0f;
   VertexArray[5][1]=0.0f;
   VertexArray[5][2]=-R;

   TextureArray[5][0]=0.5f;
   TextureArray[5][1]=1.0f;
}

void Scene3D::getIndexArray() // определить массив индексов
{
   // 0 треугольник
   IndexArray[0][0]=0; // индекс (номер) 1-ой вершины
   IndexArray[0][1]=2; // индекс (номер) 2-ой вершины
   IndexArray[0][2]=1; // индекс (номер) 3-ей вершины

   // 1 треугольник
   IndexArray[1][0]=0;
   IndexArray[1][1]=3;
   IndexArray[1][2]=2;

   // 2 треугольник
   IndexArray[2][0]=0;
   IndexArray[2][1]=4;
   IndexArray[2][2]=3;

   // 3 треугольник
   IndexArray[3][0]=0;
   IndexArray[3][1]=1;
   IndexArray[3][2]=4;

   // 4 треугольник
   IndexArray[4][0]=5;
   IndexArray[4][1]=1;
   IndexArray[4][2]=2;

   // 5 треугольник
   IndexArray[5][0]=5;
   IndexArray[5][1]=2;
   IndexArray[5][2]=3;

   // 6 треугольник
   IndexArray[6][0]=5;
   IndexArray[6][1]=3;
   IndexArray[6][2]=4;

   // 7 треугольник
   IndexArray[7][0]=5;
   IndexArray[7][1]=4;
   IndexArray[7][2]=1;
}

void Scene3D::drawFigure() // построить фигуру
{
   // указываем, откуда нужно извлечь данные о массиве вершин
   glVertexPointer(3, GL_FLOAT, 0, VertexArray);
   // указываем, откуда нужно извлечь данные о массиве текстурных координат
   glTexCoordPointer(2, GL_FLOAT, 0, TextureArray);
   // используя массивы вершин и индексов, строим поверхности
   glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, IndexArray);
}


void Scene3D::selectFigures(QPoint mp) // выбрать фигуру
{
   GLuint selectBuffer[4]; // буфер выбора (буфер совпадений)
   GLint hits; // счетчик соответствий
   glSelectBuffer(4, selectBuffer); // использовать указанный буфер выбора

   glMatrixMode(GL_PROJECTION); // матрица проекции стала активной
   glPushMatrix(); // поместить текущую матрицу в стек матриц
   glRenderMode(GL_SELECT); // переход в режим выбора
   glLoadIdentity(); // загрузить единичную матрицу

   // новый объём под указателем мыши
   //gluPickMatrix((GLdouble)mp.x(), (GLdouble)(viewport[3]-mp.y()), 1.0, 1.0, viewport);
   // мировое окно
   if (width()>=height())
      // параметры видимости ортогональной проекции:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   glMatrixMode(GL_MODELVIEW); // модельно-видовая матрица стала активной
   glLoadIdentity();           // загружается единичная матрица моделирования

   glInitNames(); // инициализируется и очищается стек имён
   glPushName(0); // в стек имён помещается значение 0
   // (обязательно должен храниться хотя бы один элемент)

   glPushMatrix(); // поместить матрицу моделирования в стек матриц
      glTranslatef(-1.0f/ratio, zTra1, 0.0f); // трансляция
      glRotatef(xRot1, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
      glRotatef(yRot1, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
      glRotatef(zRot1, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
      glLoadName(1); // загрузить имя на вершину стека имён
      drawFigure(); // нарисовать фигуру
   glPopMatrix(); // извлечь матрицу моделирования из стека матриц

   glPushMatrix(); // поместить в стек матрицу моделирования
      glTranslatef(1.0f/ratio, zTra2, 0.0f); // трансляция
      glRotatef(xRot2, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
      glRotatef(yRot2, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
      glRotatef(zRot2, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
      glLoadName(2); // загрузить имя на вершину стека имён
      drawFigure(); // нарисовать фигуру
   glPopMatrix(); // взять из стека матрицу моделирования

   // glPopName(); // вытащить имя из стека имён

   // число совпадений и переход в режим рисования
   hits=glRenderMode(GL_RENDER);

   if (hits>0) // есть совпадания и нет ошибок
   {
      int figureName=selectBuffer[3]; // имя фигуры

      // изменение параметров движения
      if (motionParameters[figureName-1])
         motionParameters[figureName-1]=0;
         // углы и величина трансляции не изменяется
      else
         motionParameters[figureName-1]=1;
         // углы и величина трансляция изменяются
   }

   glMatrixMode(GL_PROJECTION); // матрица проекции стала активной
   glPopMatrix(); // извлечь матрицу из стека матриц
}

// слот - изменение углов поворота и величины трансляции
void Scene3D::change()
{
   if (motionParameters[0]) // изменение для первой фигуры
   {
      xRot1 -=0.05f;
      yRot1 -=0.05f;
      zRot1 +=0.05f;

      if ((xRot1>360)||(xRot1<-360)) xRot1=0.0f;
      if ((yRot1>360)||(yRot1<-360)) yRot1=0.0f;
      if ((zRot1>360)||(zRot1<-360)) zRot1=0.0f;

      if (abs(zTra1)>0.5f) signs[0] *=-1;
      zTra1 -=signs[0]*0.005f;
   }

   if (motionParameters[1]) // изменение для второй фигуры
   {
      xRot2 +=0.05f;
      yRot2 +=0.05f;
      zRot2 -=0.05f;

      if ((xRot2>360)||(xRot2<-360)) xRot2=0.0f;
      if ((yRot2>360)||(yRot2<-360)) yRot2=0.0f;
      if ((zRot2>360)||(zRot2<-360)) zRot2=0.0f;

      if (abs(zTra2)>0.5f) signs[1] *=-1;
      zTra2 +=signs[1]*0.005f;
   }

   updateGL(); // обновить изображение
}

void Scene3D::changeTex() // слот - поменять текстуры местами
{
   if (textureParameters[0]==0)
   {
      textureParameters[0]=1;
      textureParameters[1]=0;
   }
   else
   {
      textureParameters[0]=0;
      textureParameters[1]=1;
   }

   updateGL(); // обновить изображение
}

void Scene3D::stopTmr() // слот - остановить таймер
{
   timer->stop();
}

void Scene3D::startTmr() // слот - запустить таймер
{
   timer->start();
}
