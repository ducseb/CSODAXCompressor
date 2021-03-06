#############################################################################
# Makefile for building: csoCompiler
# Generated by qmake (1.07a) (Qt 3.3.5) on: Sat Jul 29 12:21:17 2006
# Project:  csoCompiler.pro
# Template: app
# Command: $(QMAKE) -o Makefile csoCompiler.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -O2 -march=i586 -mtune=i686 -fmessage-length=0 -Wall -D_FORTIFY_SOURCE=2 -g -fno-strict-aliasing -Wall -W -O2 -march=i586 -mtune=i686 -fmessage-length=0 -Wall -D_FORTIFY_SOURCE=2 -g -fno-strict-aliasing  -DQT_NO_DEBUG -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_THREAD_SUPPORT
CXXFLAGS = -pipe -O2 -march=i586 -mtune=i686 -fmessage-length=0 -Wall -D_FORTIFY_SOURCE=2 -g -fno-strict-aliasing -Wall -W -O2 -march=i586 -mtune=i686 -fmessage-length=0 -Wall -D_FORTIFY_SOURCE=2 -g -fno-strict-aliasing  -DQT_NO_DEBUG -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_THREAD_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/lib/qt3/mkspecs/default -I. -I/usr/include -I$(QTDIR)/include -I.ui/ -I. -I.moc/
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L/usr/lib/ -L$(QTDIR)/lib/ -L/usr/X11R6/lib/ -lqt-mt -lXext -lX11 -lm
AR       = ar cqs
RANLIB   = 
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = .obj/

####### Files

HEADERS = 
SOURCES = main.cpp
OBJECTS = .obj/main.o \
		.obj/formmain.o \
		.obj/qmake_image_collection.o
FORMS = formmain.ui
UICDECLS = .ui/formmain.h
UICIMPLS = .ui/formmain.cpp
SRCMOC   = .moc/moc_formmain.cpp
OBJMOC = .obj/moc_formmain.o
DIST	   = csoCompiler.pro
QMAKE_TARGET = csoCompiler
DESTDIR  = 
TARGET   = csoCompiler

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: csoCompiler.pro  /usr/lib/qt3/mkspecs/default/qmake.conf /usr/lib/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile csoCompiler.pro
qmake: 
	@$(QMAKE) -o Makefile csoCompiler.pro

dist: 
	@mkdir -p .obj/csoCompiler && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/csoCompiler/ && $(COPY_FILE) --parents img/compresser.png img/iconprogramme.png img/parcourir.png .obj/csoCompiler/ && $(COPY_FILE) --parents formmain.ui.h .obj/csoCompiler/ && ( cd `dirname .obj/csoCompiler` && $(TAR) csoCompiler.tar csoCompiler && $(GZIP) csoCompiler.tar ) && $(MOVE) `dirname .obj/csoCompiler`/csoCompiler.tar.gz . && $(DEL_FILE) -r .obj/csoCompiler

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:
	-$(DEL_FILE) $(UICIMPLS) $(UICDECLS)

yaccclean:
lexclean:
clean: mocclean uiclean
	-$(DEL_FILE) $(OBJECTS)
		-$(DEL_FILE) .ui/qmake_image_collection.cpp
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/main.o: main.cpp .ui/formmain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.ui/formmain.h: formmain.ui 
	$(UIC) formmain.ui -o .ui/formmain.h

.ui/formmain.cpp: .ui/formmain.h formmain.ui formmain.ui.h 
	$(UIC) formmain.ui -i formmain.h -o .ui/formmain.cpp

.obj/formmain.o: .ui/formmain.cpp formmain.ui.h \
		.ui/formmain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/formmain.o .ui/formmain.cpp

.obj/moc_formmain.o: .moc/moc_formmain.cpp  .ui/formmain.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_formmain.o .moc/moc_formmain.cpp

.moc/moc_formmain.cpp: $(MOC) .ui/formmain.h
	$(MOC) .ui/formmain.h -o .moc/moc_formmain.cpp

.obj/qmake_image_collection.o: .ui/qmake_image_collection.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/qmake_image_collection.o .ui/qmake_image_collection.cpp

.ui/qmake_image_collection.cpp: img/compresser.png \
		img/iconprogramme.png \
		img/parcourir.png
	$(UIC)  -embed csoCompiler img/compresser.png img/iconprogramme.png img/parcourir.png -o .ui/qmake_image_collection.cpp

####### Install

install:  

uninstall:  

