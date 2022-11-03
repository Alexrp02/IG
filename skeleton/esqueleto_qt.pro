HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  hierarchical.h \
  object3d.h \
  axis.h \
  ply_object.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h

SOURCES += \
  basic_object3d.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  hierarchical.cc \
  object3d.cc \
  axis.cc \
  ply_object.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets

DISTFILES += \
    ply_models/airplane.ply \
    ply_models/ant.ply \
    ply_models/armadillo.ply \
    ply_models/beethoven.ply \
    ply_models/big_dodge.ply \
    ply_models/big_porsche.ply \
    ply_models/bunny.ply \
    ply_models/cow.ply \
    ply_models/footbones.ply \
    ply_models/happy.ply \
    ply_models/sandal.ply
