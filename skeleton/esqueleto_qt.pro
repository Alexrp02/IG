HEADERS = \
  antebrazo.h \
  brazo.h \
  cabeza.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cuerpo.h \
  cylinder.h \
  dedo.h \
  mano.h \
  object3d.h \
  axis.h \
  ojo.h \
  ply_object.h \
  robot.h \
  rueda.h \
  sphere.h \
  hierarchical.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h

SOURCES = \
  antebrazo.cc \
  basic_object3d.cc \
  brazo.cc \
  cabeza.cc \
  cone.cc \
  cube.cc \
  cuerpo.cc \
  cylinder.cc \
  dedo.cc \
  mano.cc \
  object3d.cc \
  axis.cc \
  ojo.cc \
  ply_object.cc \
  robot.cc \
  rueda.cc \
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
