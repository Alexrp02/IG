/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "qcheckbox.h"
#include "window.h"
#include <QTimer>
#include<cmath>
#include<math.h>
#include<QImageReader>

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
    light_angle = 0 ;
    timer = new QTimer(this) ;
    connect(timer, SIGNAL(timeout()), this, SLOT(idle_event())) ;
    timer->start(0) ;
    giro = false ;
    material = 0 ;
    lighting = false ;
    light0=true;
    light1=true;
    texturing = false ;
    animation = false ;
    translacion=false ;
    handsOpeningStep = 1 ;
    translationStep = 0.01 ;
    headRotationStep = 0.5 ;
    angleStep = 1 ;
    orthoZoom = 12 ;
    apertura = false ;
    setMinimumSize(300, 300);
    setFocusPolicy(Qt::StrongFocus);
}

void _gl_widget::idle_event() {
    if (!animation) return ;
    if (light_angle >= 2*M_PI) light_angle-=2*M_PI;
    light_angle +=0.02;
    Light_position[0] = cos((float)light_angle)*2;
    Light_position[2] = sin((float)light_angle)*2;
    if(Robot.brazo.antebrazo.translacion<=-1+translationStep)
        translacion = false ;
    else if(Robot.brazo.antebrazo.translacion>=0-translationStep)
        translacion = true ;
    translacion ? Robot.brazo.antebrazo.translacion -= translationStep : Robot.brazo.antebrazo.translacion += translationStep ; ;
    Window->armsSlider->setValue(Robot.brazo.antebrazo.translacion*100) ;
    if (Robot.brazo.angle <= 0) Robot.brazo.angle+= 360 ;
    Robot.brazo.angle -= angleStep;
    Window->angleSlider->setValue(Robot.brazo.angle) ;

    if (Robot.brazo.antebrazo.mano.apertura >= 60)
        apertura = false ;
    else if (Robot.brazo.antebrazo.mano.apertura <= 10)
        apertura = true ;
    apertura ? Robot.brazo.antebrazo.mano.apertura+= handsOpeningStep : Robot.brazo.antebrazo.mano.apertura-= handsOpeningStep ; ;
    Window->handsSlider->setValue(Robot.brazo.antebrazo.mano.apertura) ;
    if(Robot.cabeza.rotacion >= 30)
        giro=true;
    else if (Robot.cabeza.rotacion <= -30)
        giro = false ;

    giro ? Robot.cabeza.rotacion -= headRotationStep : Robot.cabeza.rotacion += headRotationStep ;
    //    Dedo.x += 1 ;
    update() ;
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch(Keyevent->key()){
    case Qt::Key_1:Object=OBJECT_TETRAHEDRON; Window->comboBox->setCurrentIndex(0) ;break;
    case Qt::Key_2:Object=OBJECT_CUBE; Window->comboBox->setCurrentIndex(1) ;break;
    case Qt::Key_3:Object=OBJECT_CONE; Window->comboBox->setCurrentIndex(2) ;break;
    case Qt::Key_4:Object=OBJECT_CYLINDER; Window->comboBox->setCurrentIndex(3) ;break;
    case Qt::Key_5:Object=OBJECT_SPHERE; Window->comboBox->setCurrentIndex(4) ;break;
    case Qt::Key_6:Object=OBJECT_PLY; Window->comboBox->setCurrentIndex(5) ;break;
    case Qt::Key_7:Object=OBJECT_HIERARCHICAL; Window->comboBox->setCurrentIndex(6) ;break;
    case Qt::Key_8:Object=OBJECT_DASHBOARD; Window->comboBox->setCurrentIndex(7) ;break;

    case Qt::Key_A:animation=!animation;Window->checkbox->setChecked(!Window->checkbox->isChecked());break;
    case Qt::Key_Q:
        if(Robot.brazo.antebrazo.translacion>-1+0.01)
            Robot.brazo.antebrazo.translacion -= 0.01;
        break;
    case Qt::Key_W:
        if(Robot.brazo.antebrazo.translacion<0-0.01)
            Robot.brazo.antebrazo.translacion += 0.01 ;
        break;

    case Qt::Key_S:
        if (Robot.brazo.angle <= -360) Robot.brazo.angle+= 360 ;
        Robot.brazo.angle -= 3; break;
    case Qt::Key_D:
        if (Robot.brazo.angle >= 360) Robot.brazo.angle-= 360 ;
        Robot.brazo.angle += 3 ; break;

    case Qt::Key_Z:
        if (Robot.brazo.antebrazo.mano.apertura <= 60)
            Robot.brazo.antebrazo.mano.apertura+= 1 ;
        break;
    case Qt::Key_X:
        if (Robot.brazo.antebrazo.mano.apertura >= 10)
            Robot.brazo.antebrazo.mano.apertura-= 1 ;
        break;
    case Qt::Key_E:angleStep+=1; Window->armsNumber->setValue(angleStep);break;
    case Qt::Key_R:if(angleStep!=0) angleStep-=1; Window->armsNumber->setValue(angleStep);break;

    case Qt::Key_T:translationStep+=0.01; Window->armsTranslationNumber->setValue(translationStep);break;
    case Qt::Key_Y:if(translationStep!=0)translationStep-=0.01; Window->armsTranslationNumber->setValue(translationStep);break;

    case Qt::Key_U:handsOpeningStep+=1; Window->handsNumber->setValue(handsOpeningStep);break;
    case Qt::Key_I:if(handsOpeningStep!=0)handsOpeningStep-=1; Window->handsNumber->setValue(handsOpeningStep);break;
    case Qt::Key_P:Draw_point=!Draw_point;break;
    case Qt::Key_L:Draw_line=!Draw_line;break;
    case Qt::Key_F1:texturing=false ;lighting=false ; Draw_fill=!Draw_fill;break;
    case Qt::Key_F2:texturing=false ;lighting=false ;Draw_chess=!Draw_chess;break;
    case Qt::Key_F3:texturing=false ;lighting=true ; GOURAD = false ;break;
    case Qt::Key_F4:texturing=false ;lighting=true ; GOURAD = true ;break;
    case Qt::Key_F5:texturing=true;lighting = false;GOURAD = false ;break;
    case Qt::Key_F6:texturing=true;lighting = true;GOURAD = false ;break;
    case Qt::Key_F7:texturing=true;lighting = true;GOURAD = true ;break;

    case Qt::Key_J:light0=!light0;break;
    case Qt::Key_K:light1=!light1;break;

    case Qt::Key_C:ortho=false;break;
    case Qt::Key_V:ortho=true;break;

    case Qt::Key_M:material = (material+1)%3;break;

    case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
    case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
    case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
    case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
    case Qt::Key_PageUp:Observer_distance*=1.2; orthoZoom*=1.2;break;
    case Qt::Key_PageDown:Observer_distance/=1.2;orthoZoom/=1.2;break;

    }
    Window->gouradCheckbox->setChecked(GOURAD) ;
    Window->lightingCheckbox->setChecked(lighting) ;
    Window->textureCheckbox->setChecked(texturing) ;
    update();
}

void _gl_widget::wheelEvent(QWheelEvent *wheelEvent) {
    int numDegrees = wheelEvent->delta() / 8;
    int numSteps = numDegrees / 15;
    float zoomFactor = 1.0 + numSteps * 0.1;
    Observer_distance /= zoomFactor ;
    orthoZoom /= zoomFactor ;
    update() ;
}

void _gl_widget::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton)
        lastMousePos = event->pos();
}

void _gl_widget::mouseMoveEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton)
    {
        // Calculate the rotation angle based on the mouse movement
        QPoint delta = event->pos() - lastMousePos;

        // Update the observer angle with the rotation
        Observer_angle_x += (float) delta.y() / 4 ;
        Observer_angle_y += (float) delta.x() / 4 ;

        // Save the current mouse position for the next mouseMoveEvent
        lastMousePos = event->pos();
        update() ;
    }
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void _gl_widget::change_light()
{
    glMatrixMode(GL_MODELVIEW) ;
    glPushMatrix() ;
    glEnable(GL_DEPTH_TEST);
    if (lighting) {
        glEnable(GL_LIGHTING) ;
        light0 ? glEnable(GL_LIGHT0) : glDisable(GL_LIGHT0) ;
        light1 ? glEnable(GL_LIGHT1) : glDisable(GL_LIGHT1) ;
        glDisable(GL_COLOR_MATERIAL);
        //Select the ShadeModel we want
        if (!GOURAD) glShadeModel(GL_FLAT);
        else glShadeModel(GL_SMOOTH) ;
        glLightfv(GL_LIGHT0, GL_POSITION, Light_position2) ;
        glLightfv(GL_LIGHT1, GL_POSITION, Light_position) ;
        // Set the diffuse light component
        GLfloat diffuseLight[] = {1, 0, 1, 1};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
        GLfloat diffuseLight0[] = {1, 1, 1, 1};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);

        GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0};
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

        // Set the specular light component
        GLfloat specularLight[] = {0.5, 0, 0.5, 1};
        glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
        GLfloat specularLight0[] = {0, 0, 0, 0};
        glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);

        GLfloat spotDirection[] = {0,0,0} ;
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection) ;
    }else {
        glDisable(GL_LIGHTING) ;
        glEnable(GL_COLOR_MATERIAL);
    }
    glPopMatrix() ;

}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
    // Front_plane>0  Back_plane>PlanoDelantero)
    if(!ortho)
        glFrustum(-x_size,x_size,-y_size,y_size,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
    else
        glOrtho(-x_size*orthoZoom,x_size*orthoZoom,-y_size*orthoZoom,y_size*orthoZoom,FRONT_PLANE_PERSPECTIVE/2,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-Observer_distance);
    glRotatef(Observer_angle_x,1,0,0);
    glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
    Axis.draw_line();
    if (Draw_point){
        glPointSize(5);
        glColor3fv((GLfloat *) &BLACK);
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
        case OBJECT_CUBE:Cube.draw_point();break;
        case OBJECT_PLY:Ply.draw_point();break;
        case OBJECT_CONE:Cone.draw_point();break;
        case OBJECT_CYLINDER:Cylinder.draw_point();break;
        case OBJECT_SPHERE:Sphere.draw_point();break;
        case OBJECT_HIERARCHICAL:Robot.draw("POINT");break;
        case OBJECT_DASHBOARD:Tablero.draw_point();break;
        default:break;
        }
    }

    if (Draw_line){
        glLineWidth(3);
        glColor3fv((GLfloat *) &MAGENTA);
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
        case OBJECT_CUBE:Cube.draw_line();break;
        case OBJECT_PLY:Ply.draw_line();break;
        case OBJECT_CONE:Cone.draw_line();break;
        case OBJECT_CYLINDER:Cylinder.draw_line();break;
        case OBJECT_SPHERE:Sphere.draw_line();break;
        case OBJECT_HIERARCHICAL:Robot.draw("LINE");break;
        case OBJECT_DASHBOARD:Tablero.draw_line();break;
        default:break;
        }
    }

    if (Draw_fill){
        glColor3fv((GLfloat *) &BLUE);
        if(lighting) {
            glEnable(GL_LIGHTING) ;
            if (material == 0) {
                GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
                GLfloat material_specular[] = { 0.1, 0.1, 0.1, 1.0 };
                GLfloat material_ambient[] = {0.2, 0.2, 0.2, 1} ;
                GLfloat material_emission[] = {0, 0, 0, 1} ;
                GLfloat material_shininess = 64;
                glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
                glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
                glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
                glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
                glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
            }else if (material == 1) {
                GLfloat material_diffuse[] = { 0.4, 0.6, 0.4, 1.0 };
                GLfloat material_specular[] = { 0.3, 0.1, 0.05, 1.0 };
                GLfloat material_ambient[] = {0, 0, 0, 1} ;
                GLfloat material_emission[] = {0.1, 0.1, 0.1, 1} ;
                GLfloat material_shininess = 0;
                glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
                glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
                glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
                glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
                glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
            }else {
                GLfloat material_diffuse[] = { 0.8, 0.6, 0.25, 1.0 };
                GLfloat material_specular[] = { 1, 1, 0, 1.0 };
                GLfloat material_ambient[] = {0.2, 0.2, 0.2, 1} ;
                GLfloat material_emission[] = {0, 0, 0, 1} ;
                GLfloat material_shininess = 128;
                glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
                glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
                glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
                glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
                glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
            }


        }else {
            glDisable(GL_LIGHTING) ;
        }

        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
        case OBJECT_CUBE:Cube.draw_fill();break;
        case OBJECT_PLY:Ply.draw_fill();break;
        case OBJECT_CONE:Cone.draw_fill();break;
        case OBJECT_CYLINDER:Cylinder.draw_fill();break;
        case OBJECT_SPHERE:texturing ? Sphere.draw_texture() : Sphere.draw_fill();break;
        case OBJECT_HIERARCHICAL:Robot.draw("FILL");break;
        case OBJECT_DASHBOARD:texturing ? Tablero.draw_texture() : Tablero.draw_fill();break;
        default:break;
        }
    }

    if (Draw_chess){
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
        case OBJECT_CUBE:Cube.draw_chess();break;
        case OBJECT_PLY:Ply.draw_chess();break;
        case OBJECT_CONE:Cone.draw_chess();break;
        case OBJECT_CYLINDER:Cylinder.draw_chess();break;
        case OBJECT_SPHERE:Sphere.draw_chess();break;
        case OBJECT_HIERARCHICAL:Robot.draw("CHESS");break;
        case OBJECT_DASHBOARD:Tablero.draw_chess();break;
        default:break;
        }
    }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
    clear_window();
    change_projection();
    change_observer();
    change_light() ;
    draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
    const float ar = (float) Height1 / (float) Width1;
    y_size = X_MAX*ar ;
    change_projection() ;
    glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
    const GLubyte* strm;

    strm = glGetString(GL_VENDOR);
    std::cerr << "Vendor: " << strm << "\n";
    strm = glGetString(GL_RENDERER);
    std::cerr << "Renderer: " << strm << "\n";
    strm = glGetString(GL_VERSION);
    std::cerr << "OpenGL Version: " << strm << "\n";

    if (strm[0] == '1'){
        std::cerr << "Only OpenGL 1.X supported!\n";
        exit(-1);
    }

    strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::cerr << "GLSL Version: " << strm << "\n";

    int Max_texture_size=0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
    std::cerr << "Max texture size: " << Max_texture_size << "\n";

    glClearColor(1.0,1.0,1.0,1.0);
    //  glPushMatrix() ;
    //  glLoadIdentity() ;

    //  glPopMatrix() ;
    //  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0) ;

    Observer_angle_x=0;
    Observer_angle_y=0;
    Observer_distance=DEFAULT_DISTANCE;

    GOURAD = false ;
    x_size = X_MAX ;
    y_size = Y_MAX ;
    Draw_point=false;
    Draw_line=true;
    Draw_fill=false;
    Draw_chess=false;
    COLOR = false ;
    Tablero.read_texture(Tablero.texture_name) ;
    Sphere.read_texture(Sphere.texture_name) ;
}

