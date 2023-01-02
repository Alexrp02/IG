/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QComboBox>
#include <QDoubleSpinBox>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _window::setSliders () {
    lightSlider = new QSlider(Qt::Horizontal);
    lightSlider->setMinimum(0) ;
    lightSlider->setMaximum(1000) ;
    lightSlider->setFixedWidth(100) ;
    lightSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QObject::connect(lightSlider, &QSlider::valueChanged, [&](int value){
        // This lambda function will be called whenever the slider value changes
        // Update the variable with the new value
        GL_widget->light_angle = (float)value/1000*2*M_PI;
        GL_widget->Light_position[0] = cos((float)value/1000*2*M_PI)*2;
        GL_widget->Light_position[2] = sin((float)value/1000*2*M_PI)*2;
        GL_widget->update() ;
    });

    handsSlider = new QSlider(Qt::Horizontal);
    handsSlider->setMinimum(10) ;
    handsSlider->setMaximum(60) ;
    handsSlider->setFixedWidth(100) ;
    handsSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QObject::connect(handsSlider, &QSlider::valueChanged, [&](int value){
        // This lambda function will be called whenever the slider value changes
        // Update the variable with the new value
        GL_widget->Robot.brazo.antebrazo.mano.apertura = value ;
        GL_widget->update() ;
    });

    angleSlider = new QSlider(Qt::Horizontal);
    angleSlider->setMinimum(0) ;
    angleSlider->setMaximum(360) ;
    angleSlider->setFixedWidth(100) ;
    angleSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QObject::connect(angleSlider, &QSlider::valueChanged, [&](int value){
        // This lambda function will be called whenever the slider value changes
        // Update the variable with the new value
        GL_widget->Robot.brazo.angle = value ;
        GL_widget->update() ;
    });

    armsSlider = new QSlider(Qt::Horizontal);
    armsSlider->setMinimum(-100) ;
    armsSlider->setMaximum(0) ;
    armsSlider->setFixedWidth(100) ;
    armsSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QObject::connect(armsSlider, &QSlider::valueChanged, [&](int value){
        // This lambda function will be called whenever the slider value changes
        // Update the variable with the new value
        GL_widget->Robot.brazo.antebrazo.translacion = (float)value/100 ;
        GL_widget->update() ;
    });
}

_window::_window()
{

    QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QWidget *Central_widget = new QWidget(this);

    QFrame *Framed_widget= new QFrame(Central_widget);
    Framed_widget->setSizePolicy(Q);
    Framed_widget->setFrameStyle(QFrame::Panel);
    Framed_widget->setLineWidth(3);


    GL_widget = new _gl_widget(this);
    GL_widget->setSizePolicy(Q);

    QHBoxLayout *Horizontal_frame = new QHBoxLayout();
    Horizontal_frame->setContentsMargins(1,1,1,1);

    Horizontal_frame->addWidget(GL_widget);
    Framed_widget->setLayout(Horizontal_frame);

    // Create the side menu widget and add it to a vertical layout
    QWidget *sideMenuWidget = new QWidget();
    QVBoxLayout *sideMenuLayout = new QVBoxLayout(sideMenuWidget);

    // Create the sliders and the listeners
    setSliders() ;

    //Now create the label for the sliders
    QLabel *lightLabel = new QLabel("Magenta light position:");
    QLabel *handsLabel = new QLabel("Hands opening:");
    QLabel *angleLabel = new QLabel("Arms rotation:");
    QLabel *armsLabel = new QLabel("Arms opening:");
    //Create a checkbox for animation
    checkbox = new QCheckBox(tr("Animation"), this);
    gouradCheckbox = new QCheckBox(tr("Gourad lighting"), this);
    textureCheckbox = new QCheckBox(tr("Texture"), this);
    lightingCheckbox = new QCheckBox(tr("Lighting"), this);


    // Connect the checkbox's stateChanged signal to the slot function
    QObject::connect(checkbox, &QCheckBox::stateChanged, [&](int state) {
        // Update the value based on the checkbox's state
        GL_widget->animation = (state == Qt::Checked) ;
        GL_widget->update() ;
    });
    QObject::connect(gouradCheckbox, &QCheckBox::stateChanged, [&](int state) {
        // Update the value based on the checkbox's state
        GL_widget->GOURAD = (state == Qt::Checked) ;
        GL_widget->update() ;
    });
    QObject::connect(lightingCheckbox, &QCheckBox::stateChanged, [&](int state) {
        // Update the value based on the checkbox's state
        GL_widget->lighting = (state == Qt::Checked) ;
        GL_widget->update() ;
    });
    QObject::connect(textureCheckbox, &QCheckBox::stateChanged, [&](int state) {
        // Update the value based on the checkbox's state
        GL_widget->texturing = (state == Qt::Checked) ;
        GL_widget->update() ;
    });

    // Create a combo box
    comboBox = new QComboBox();

    // Add options to the combo box
    comboBox->addItem("Tetrahedron");
    comboBox->addItem("Cube");
    comboBox->addItem("Cone");
    comboBox->addItem("Cylinder");
    comboBox->addItem("Sphere");
    comboBox->addItem("PLY Object");
    comboBox->addItem("Robot");
    comboBox->addItem("Dashboard");

    // Connect the currentIndexChanged signal of the combo box to a slot
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [=](int index){
        // This lambda function will be called when the selected option changes
        // You can access the selected option using the index variable
        // For example:
        switch (index) {
        case 0 :
            GL_widget->Object = _gl_widget_ne::OBJECT_TETRAHEDRON ;
            break;
        case 1 :
            GL_widget->Object = _gl_widget_ne::OBJECT_CUBE ;
            break;
        case 2 :
            GL_widget->Object = _gl_widget_ne::OBJECT_CONE ;
            break;
        case 3 :
            GL_widget->Object = _gl_widget_ne::OBJECT_CYLINDER ;
            break;
        case 4 :
            GL_widget->Object = _gl_widget_ne::OBJECT_SPHERE ;
            break;
        case 5 :
            GL_widget->Object = _gl_widget_ne::OBJECT_PLY ;
            break;
        case 6 :
            GL_widget->Object = _gl_widget_ne::OBJECT_HIERARCHICAL ;
            break;
        case 7 :
            GL_widget->Object = _gl_widget_ne::OBJECT_DASHBOARD ;
            break;
        }
        GL_widget->update() ;
    });
    //Set the side menu to align the content to the top
    sideMenuLayout->setAlignment(Qt::AlignTop);

    // Set the border of the side menu layout to a black line and background to be white
    sideMenuWidget->setStyleSheet(".QWidget{border: 2px solid black;"
                                  "background-color:white;}");

    QWidget *valuesWidget = new QWidget() ;
    QVBoxLayout *valuesWidgetLayout = new QVBoxLayout(valuesWidget);
    QHBoxLayout *angleLayout = new QHBoxLayout(valuesWidget) ;
    QLabel *arms = new QLabel("Arms angle Step") ;
    armsNumber = new QDoubleSpinBox() ;
    armsNumber->setSingleStep(1) ;
    armsNumber->setValue(1) ;
    angleLayout->addWidget(arms) ;
    angleLayout->addWidget(armsNumber) ;
    valuesWidgetLayout->addLayout(angleLayout) ;
    QObject::connect(armsNumber, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [&](double value){

        GL_widget->angleStep = value ;

    });

    QLabel *translation = new QLabel("Arms translation Step") ;
    armsTranslationNumber = new QDoubleSpinBox() ;
    QHBoxLayout *translationLayout = new QHBoxLayout(valuesWidget) ;
    armsTranslationNumber->setSingleStep(0.01) ;
    armsTranslationNumber->setValue(0.01) ;
    translationLayout->addWidget(translation) ;
    translationLayout->addWidget(armsTranslationNumber) ;
    valuesWidgetLayout->addLayout(translationLayout) ;
    QObject::connect(armsTranslationNumber, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [&](double value){

        GL_widget->translationStep = value ;

    });

    QLabel *hands = new QLabel("Arms hands Step") ;
    handsNumber = new QDoubleSpinBox() ;
    QHBoxLayout *handsLayout = new QHBoxLayout(valuesWidget) ;
    handsNumber->setSingleStep(1) ;
    handsNumber->setValue(1) ;
    handsLayout->addWidget(hands) ;
    handsLayout->addWidget(handsNumber) ;
    valuesWidgetLayout->addLayout(handsLayout) ;
    QObject::connect(handsNumber, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [&](double value){

        GL_widget->handsOpeningStep = value ;

    });

    QLabel *head = new QLabel("Arms head Step") ;
    headNumber = new QDoubleSpinBox() ;
    QHBoxLayout *headLayout = new QHBoxLayout(valuesWidget) ;
    headNumber->setSingleStep(0.1) ;
    headNumber->setValue(0.5) ;
    headLayout->addWidget(head) ;
    headLayout->addWidget(headNumber) ;
    valuesWidgetLayout->addLayout(headLayout) ;
    QObject::connect(headNumber, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [&](double value){

        GL_widget->headRotationStep = value ;

    });

    //Add the two components to the side menu
    sideMenuLayout->addWidget(lightLabel) ;
    sideMenuLayout->addWidget(lightSlider) ;
    sideMenuLayout->addWidget(handsLabel) ;
    sideMenuLayout->addWidget(handsSlider);
    sideMenuLayout->addWidget(angleLabel) ;
    sideMenuLayout->addWidget(angleSlider);
    sideMenuLayout->addWidget(armsLabel) ;
    sideMenuLayout->addWidget(armsSlider);
    sideMenuLayout->addWidget(checkbox);
    sideMenuLayout->addWidget(lightingCheckbox);
    sideMenuLayout->addWidget(gouradCheckbox);
    sideMenuLayout->addWidget(textureCheckbox);
    sideMenuLayout->addWidget(comboBox);
    sideMenuLayout->addWidget(valuesWidget) ;


    QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

    Horizontal_main->addWidget(Framed_widget);
    Horizontal_main->addWidget(sideMenuWidget) ;

    Central_widget->setLayout(Horizontal_main);
    setCentralWidget(Central_widget);

    // actions for file menu
    QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
    Exit->setShortcut(tr("Ctrl+Q"));
    Exit->setToolTip(tr("Exit the application"));
    connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

    // menus
    QMenu *File_menu=menuBar()->addMenu(tr("&File"));
    File_menu->addAction(Exit);
    File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

    setWindowTitle(tr("Práctica 1"));

    resize(800,800);
}
