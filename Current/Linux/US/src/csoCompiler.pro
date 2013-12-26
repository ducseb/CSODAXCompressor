TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

SOURCES	+= main.cpp

FORMS	= formmain.ui

IMAGES	= img/compresser.png \
	img/iconprogramme.png \
	img/parcourir.png

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}
RC_FILE = csoCompiler.rcFORMS	= formmain.ui
RC_FILE = csoCompiler.rc
FORMS	= formmain.ui
