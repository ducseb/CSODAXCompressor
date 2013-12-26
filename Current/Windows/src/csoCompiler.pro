SOURCES	+= main.cpp
unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}
RC_FILE = csoCompiler.rcFORMS	= formmain.ui
RC_FILE = csoCompiler.rc
FORMS	= formmain.ui
IMAGES	= img/compresser.png \
	img/iconprogramme.png \
	img/parcourir.png
TEMPLATE	=app
CONFIG	+= qt warn_on release
LANGUAGE	= C++
TRANSLATIONS    = csoCompiler_fr.ts \
				   csoCompiler_en.ts \
