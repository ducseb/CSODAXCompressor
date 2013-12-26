#include <qapplication.h>
#include "formmain.h"
#include <qstring.h>
#include <qlineedit.h>
#include <qtabwidget.h> 
#include <qwidget.h>
#include <qfile.h>
#include <qcombobox.h>
#include <qtextstream.h> 
#include <qplatinumstyle.h> 

#include <qvariant.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qcombobox.h>
#include <qgroupbox.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qthread.h>
#include <qfile.h>
#include <qmessagebox.h> 
#include <qdialog.h>
#include <qprogressbar.h>
#include <qwidget.h>
#include <qtabwidget.h> 
#include <qcolor.h>


int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    QString path="";
    //qWarning(argv[0]);
    QString pathComplet(argv[0]);
    path=pathComplet.section("csoCompiler.exe",0,0);
    //qWarning(path);
     QTranslator translator( 0 );
     QString pathLangue=path+"lang.txt";
     QFile fichierLang(pathLangue);
     QString langue;
      if(  fichierLang.open(IO_ReadOnly))
    {
	  QTextStream fluxLectureFichierlang( &fichierLang);
	  langue=fluxLectureFichierlang.readLine();	  
	  if(langue=="FRANCAIS")
	  {
	      QString tempoLangue=path+"csoCompiler_fr";
	      translator.load( tempoLangue, "." );
	      a.installTranslator( &translator );
	  }
	  else
	  {
	     QString tempoLangue=path+"csoCompiler_en";
	      translator.load( tempoLangue, "." );
	      a.installTranslator( &translator );
	  }
      }
      else
      {
	      QString tempoLangue=path+"csoCompiler_en";
	      translator.load( tempoLangue, "." );
	      a.installTranslator( &translator );
      }
     
      formMain w;
      w.path=path;
     QString pathOption=path+"option.txt";
         qWarning(pathOption);
     QFile fichierOption(pathOption);
      if( fichierOption.open(IO_ReadOnly))
    {
	QTextStream fluxLecture( &fichierOption);
	QString chaineALire;
	QString convert;
	chaineALire= fluxLecture.readLine();
	chaineALire=fluxLecture.readLine();
	chaineALire=fluxLecture.readLine();
	 w.dirOpenSave=chaineALire;
               chaineALire=fluxLecture.readLine();
		int itemDrivePSPLetter = chaineALire.toInt();
		w.leSaveFolder->setText(w.dirOpenSave);
		w.bDriveLetter->setCurrentItem(itemDrivePSPLetter);
		w.bDriveLetter_2->setCurrentItem(itemDrivePSPLetter);
		chaineALire=fluxLecture.readLine();
		int itemStyle = chaineALire.toInt();
		w.cbStyle->setCurrentItem(itemStyle);
		a.setStyle(w.cbStyle->currentText());
		w.compressType="FILE";
		if(w.cbStyle->currentText()=="motif")
		{
		    QPalette pal;
		    QColorGroup cg;
		    cg.setColor( QColorGroup::Foreground, QColor("white") );
		    cg.setColor( QColorGroup::Button, QColor( 74, 49, 0) );
		    cg.setColor( QColorGroup::Light, QColor( 111, 74, 0) );
		    cg.setColor( QColorGroup::Midlight, QColor( 92, 61, 0) );
		    cg.setColor( QColorGroup::Dark, QColor( 37, 25, 0) );
		    cg.setColor( QColorGroup::Mid, QColor( 49, 33, 0) );
		    cg.setColor( QColorGroup::Text,  QColor("white"));
		    cg.setColor( QColorGroup::BrightText, QColor("white"));
		    cg.setColor( QColorGroup::ButtonText, QColor("white") );
		    cg.setColor( QColorGroup::Base,  QColor("black"));
		    cg.setColor( QColorGroup::Background, QColor("black"));
		    cg.setColor( QColorGroup::Shadow, QColor("black"));
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText, QColor("white"));
		    cg.setColor( QColorGroup::Link, QColor("black"));
		    cg.setColor( QColorGroup::LinkVisited, QColor("black"));
		    pal.setActive( cg );
		    cg.setColor( QColorGroup::Foreground,  QColor("white"));
		    cg.setColor( QColorGroup::Button, QColor( 74, 49, 0) );
		    cg.setColor( QColorGroup::Light, QColor( 111, 74, 0) );
		    cg.setColor( QColorGroup::Midlight, QColor( 85, 57, 0) );
		    cg.setColor( QColorGroup::Dark, QColor( 37, 25, 0) );
		    cg.setColor( QColorGroup::Mid, QColor( 49, 33, 0) );
		    cg.setColor( QColorGroup::Text,  QColor("white"));
		    cg.setColor( QColorGroup::BrightText,  QColor("white"));
		    cg.setColor( QColorGroup::ButtonText,  QColor("white") );
		    cg.setColor( QColorGroup::Base, QColor("black"));
		    cg.setColor( QColorGroup::Background, QColor("black"));
		    cg.setColor( QColorGroup::Shadow, QColor("black"));
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText,  QColor("white") );
		    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
		    pal.setInactive( cg );
		    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::Button, QColor( 74, 49, 0) );
		    cg.setColor( QColorGroup::Light, QColor( 111, 74, 0) );
		    cg.setColor( QColorGroup::Midlight, QColor( 85, 57, 0) );
		    cg.setColor( QColorGroup::Dark, QColor( 37, 25, 0) );
		    cg.setColor( QColorGroup::Mid, QColor( 49, 33, 0) );
		    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::BrightText,  QColor("white"));
		    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::Base, QColor("black"));
		    cg.setColor( QColorGroup::Background, QColor("black"));
		    cg.setColor( QColorGroup::Shadow, QColor("black"));
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText,  QColor("white"));
		    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
                               pal.setDisabled( cg );
			       w.setPalette(pal);
	    }
		else if (w.cbStyle->currentText()=="cde")
		{
		    QPalette pal;
		    QColorGroup cg;
		    cg.setColor( QColorGroup::Foreground, QColor("black") );
		    cg.setColor( QColorGroup::Button, QColor( 255, 255, 127) );
		    cg.setColor( QColorGroup::Light, QColor( 255, 255, 254) );
		    cg.setColor( QColorGroup::Midlight, QColor( 255, 255, 190) );
		    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 63) );
		    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 85) );
		    cg.setColor( QColorGroup::Text, QColor("black") );
		    cg.setColor( QColorGroup::BrightText, QColor("white") );
		    cg.setColor( QColorGroup::ButtonText, QColor("black") );
		    cg.setColor( QColorGroup::Base, QColor("white") );
		    cg.setColor( QColorGroup::Background, QColor( 170, 255, 127) );
		    cg.setColor( QColorGroup::Shadow, QColor("black") );
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		    cg.setColor( QColorGroup::Link, QColor("black") );
		    cg.setColor( QColorGroup::LinkVisited, QColor("black") );
		    pal.setActive( cg );
		    cg.setColor( QColorGroup::Foreground, QColor("black") );
		    cg.setColor( QColorGroup::Button, QColor( 255, 255, 127) );
		    cg.setColor( QColorGroup::Light, QColor( 255, 255, 254) );
		    cg.setColor( QColorGroup::Midlight, QColor( 255, 255, 165) );
		    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 63) );
		    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 85) );
		    cg.setColor( QColorGroup::Text, QColor("black") );
		    cg.setColor( QColorGroup::BrightText, QColor("white") );
		    cg.setColor( QColorGroup::ButtonText, QColor("black") );
		    cg.setColor( QColorGroup::Base, QColor("white") );
		    cg.setColor( QColorGroup::Background, QColor( 170, 255, 127) );
		    cg.setColor( QColorGroup::Shadow, QColor("black") );
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
		    pal.setInactive( cg );
		    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::Button, QColor( 255, 255, 127) );
		    cg.setColor( QColorGroup::Light, QColor( 255, 255, 254) );
		    cg.setColor( QColorGroup::Midlight, QColor( 255, 255, 165) );
		    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 63) );
		    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 85) );
		    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::BrightText, QColor("white") );
		    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
		    cg.setColor( QColorGroup::Base, QColor("white") );
		    cg.setColor( QColorGroup::Background, QColor( 170, 255, 127) );
		    cg.setColor( QColorGroup::Shadow, QColor("black") );
		    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
		    pal.setDisabled( cg );
                               w.setPalette(pal);
	   }
		else if (w.cbStyle->currentText()=="motifplus")
		{
				QPalette pal;
				QColorGroup cg;
				cg.setColor( QColorGroup::Foreground, QColor("white") );
			    cg.setColor( QColorGroup::Button, QColor( 182, 128, 128) );
			    cg.setColor( QColorGroup::Light, QColor( 255, 197, 197) );
			    cg.setColor( QColorGroup::Midlight, QColor( 218, 162, 162) );
			    cg.setColor( QColorGroup::Dark, QColor( 91, 64, 64) );
			    cg.setColor( QColorGroup::Mid, QColor( 121, 85, 85) );
			    cg.setColor( QColorGroup::Text, QColor("white") );
			    cg.setColor( QColorGroup::BrightText, QColor("white") );
			    cg.setColor( QColorGroup::ButtonText, QColor("white") );
			    cg.setColor( QColorGroup::Base, QColor("black") );
			    cg.setColor( QColorGroup::Background, QColor( 85, 0, 0) );
			    cg.setColor( QColorGroup::Shadow, QColor("black") );
			    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			    cg.setColor( QColorGroup::Link, QColor("black") );
			    cg.setColor( QColorGroup::LinkVisited, QColor("black") );
			    pal.setActive( cg );
			    cg.setColor( QColorGroup::Foreground, QColor("white") );
			    cg.setColor( QColorGroup::Button, QColor( 182, 128, 128) );
			    cg.setColor( QColorGroup::Light, QColor( 255, 197, 197) );
			    cg.setColor( QColorGroup::Midlight, QColor( 209, 147, 147) );
			    cg.setColor( QColorGroup::Dark, QColor( 91, 64, 64) );
			    cg.setColor( QColorGroup::Mid, QColor( 121, 85, 85) );
			    cg.setColor( QColorGroup::Text, QColor("white") );
			    cg.setColor( QColorGroup::BrightText, QColor("white") );
			    cg.setColor( QColorGroup::ButtonText, QColor("white") );
			    cg.setColor( QColorGroup::Base, QColor("black") );
			    cg.setColor( QColorGroup::Background, QColor( 85, 0, 0) );
			    cg.setColor( QColorGroup::Shadow, QColor("black") );
			    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
			    pal.setInactive( cg );
			    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
			    cg.setColor( QColorGroup::Button, QColor( 182, 128, 128) );
			    cg.setColor( QColorGroup::Light, QColor( 255, 197, 197) );
			    cg.setColor( QColorGroup::Midlight, QColor( 209, 147, 147) );
			    cg.setColor( QColorGroup::Dark, QColor( 91, 64, 64) );
			    cg.setColor( QColorGroup::Mid, QColor( 121, 85, 85) );
			    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
			    cg.setColor( QColorGroup::BrightText, QColor("white") );
			    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
			    cg.setColor( QColorGroup::Base, QColor("black") );
			    cg.setColor( QColorGroup::Background, QColor( 85, 0, 0) );
			    cg.setColor( QColorGroup::Shadow, QColor("black") );
			    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			    cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
			    pal.setDisabled( cg );
			    w.setPalette(pal);
			   
		
		
	   }
	   else if(w.cbStyle->currentText()=="platinum")
	{
			QPalette pal;
			QColorGroup cg;
			cg.setColor( QColorGroup::Foreground, QColor("black") );
			cg.setColor( QColorGroup::Button, QColor( 85, 170, 255) );
			cg.setColor( QColorGroup::Light, QColor( 212, 234, 255) );
			cg.setColor( QColorGroup::Midlight, QColor( 148, 202, 255) );
			cg.setColor( QColorGroup::Dark, QColor( 42, 85, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 57, 113, 170) );
			cg.setColor( QColorGroup::Text, QColor("black") );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor("black") );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor("white") );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor("black") );
			cg.setColor( QColorGroup::LinkVisited, QColor("black") );
			pal.setActive( cg );
			cg.setColor( QColorGroup::Foreground, QColor("black") );
			cg.setColor( QColorGroup::Button, QColor( 85, 170, 255) );
			cg.setColor( QColorGroup::Light, QColor( 212, 234, 255) );
			cg.setColor( QColorGroup::Midlight, QColor( 123, 189, 255) );
			cg.setColor( QColorGroup::Dark, QColor( 42, 85, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 57, 113, 170) );
			cg.setColor( QColorGroup::Text, QColor("black") );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor("black") );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor("white") );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
			pal.setInactive( cg );
			cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::Button, QColor( 85, 170, 255) );
			cg.setColor( QColorGroup::Light, QColor( 212, 234, 255) );
			cg.setColor( QColorGroup::Midlight, QColor( 123, 189, 255) );
			cg.setColor( QColorGroup::Dark, QColor( 42, 85, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 57, 113, 170) );
			cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor("white") );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
                                        pal.setDisabled( cg );
			w.setPalette(pal);
	    }
		
		else if(w.cbStyle->currentText()=="sgi")
		{
		        QPalette pal;
			QColorGroup cg;
			cg.setColor( QColorGroup::Foreground, QColor("black") );
			cg.setColor( QColorGroup::Button, QColor("white") );
			cg.setColor( QColorGroup::Light, QColor("white") );
			cg.setColor( QColorGroup::Midlight, QColor("white") );
			cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
			cg.setColor( QColorGroup::Text, QColor("black") );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor("black") );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor( 165, 175, 212) );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor("black") );
			cg.setColor( QColorGroup::LinkVisited, QColor("black") );
			pal.setActive( cg );
			cg.setColor( QColorGroup::Foreground, QColor("black") );
			cg.setColor( QColorGroup::Button, QColor("white") );
			cg.setColor( QColorGroup::Light, QColor("white") );
			cg.setColor( QColorGroup::Midlight, QColor("white") );
			cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
			cg.setColor( QColorGroup::Text, QColor("black") );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor("black") );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor( 165, 175, 212) );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
			pal.setInactive( cg );
			cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::Button, QColor("white") );
			cg.setColor( QColorGroup::Light, QColor("white") );
			cg.setColor( QColorGroup::Midlight, QColor("white") );
			cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
			cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
			cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::BrightText, QColor("white") );
			cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
			cg.setColor( QColorGroup::Base, QColor("white") );
			cg.setColor( QColorGroup::Background, QColor( 165, 175, 212) );
			cg.setColor( QColorGroup::Shadow, QColor("black") );
			cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
			cg.setColor( QColorGroup::HighlightedText, QColor("white") );
			cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
			cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
    pal.setDisabled( cg );
    
			w.setPalette(pal);
	    }
		
		else if(w.cbStyle->currentText()=="compact")
		{
		     QPalette pal;
		     QColorGroup cg;
		     cg.setColor( QColorGroup::Foreground, QColor("white") );
		     cg.setColor( QColorGroup::Button, QColor( 82, 56, 98) );
		     cg.setColor( QColorGroup::Light, QColor( 123, 84, 147) );
		     cg.setColor( QColorGroup::Midlight, QColor( 102, 70, 122) );
		     cg.setColor( QColorGroup::Dark, QColor( 41, 28, 49) );
		     cg.setColor( QColorGroup::Mid, QColor( 54, 37, 65) );
		     cg.setColor( QColorGroup::Text, QColor("white") );
		     cg.setColor( QColorGroup::BrightText, QColor("white") );
		     cg.setColor( QColorGroup::ButtonText, QColor("white") );
		     cg.setColor( QColorGroup::Base, QColor("black") );
		     cg.setColor( QColorGroup::Background, QColor("black") );
		     cg.setColor( QColorGroup::Shadow, QColor("black") );
		     cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		     cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		     cg.setColor( QColorGroup::Link, QColor("black") );
		     cg.setColor( QColorGroup::LinkVisited, QColor("black") );
		     pal.setActive( cg );
		     cg.setColor( QColorGroup::Foreground, QColor("white") );
		     cg.setColor( QColorGroup::Button, QColor( 82, 56, 98) );
		     cg.setColor( QColorGroup::Light, QColor( 123, 84, 147) );
		     cg.setColor( QColorGroup::Midlight, QColor( 94, 64, 112) );
		     cg.setColor( QColorGroup::Dark, QColor( 41, 28, 49) );
		     cg.setColor( QColorGroup::Mid, QColor( 54, 37, 65) );
		     cg.setColor( QColorGroup::Text, QColor("white") );
		     cg.setColor( QColorGroup::BrightText, QColor("white") );
		     cg.setColor( QColorGroup::ButtonText, QColor("white") );
		     cg.setColor( QColorGroup::Base, QColor("black") );
		     cg.setColor( QColorGroup::Background, QColor("black") );
		     cg.setColor( QColorGroup::Shadow, QColor("black") );
		     cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		     cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		     cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		     cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
		     pal.setInactive( cg );
		     cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
		     cg.setColor( QColorGroup::Button, QColor( 82, 56, 98) );
		     cg.setColor( QColorGroup::Light, QColor( 123, 84, 147) );
		     cg.setColor( QColorGroup::Midlight, QColor( 94, 64, 112) );
		     cg.setColor( QColorGroup::Dark, QColor( 41, 28, 49) );
		     cg.setColor( QColorGroup::Mid, QColor( 54, 37, 65) );
		     cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
		     cg.setColor( QColorGroup::BrightText, QColor("white") );
		     cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
		     cg.setColor( QColorGroup::Base, QColor("black") );
		     cg.setColor( QColorGroup::Background, QColor("black") );
		     cg.setColor( QColorGroup::Shadow, QColor("black") );
		     cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
		     cg.setColor( QColorGroup::HighlightedText, QColor("white") );
		     cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
		     cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
		     pal.setDisabled( cg );
			w.setPalette(pal);
	    }
	   
	   
	   
	   
      }
      else
      {
	  w.bDriveLetter->setCurrentItem(0);
	  w.dirOpenSave="";
      }
      
      if(langue=="FRANCAIS")
      {
	  w.cbLng->setCurrentItem(0);
      }
      else
      {
	 w.cbLng->setCurrentItem(1);
      }
      
      
      
      if(argc>1)
    {
	QString param(argv[1]);
	
	if(param.contains(".ISO") || param.contains(".iso"))
	{
	    param=param.replace("\\","/");
	    w.leSrc->setText(param);
	    if(param.contains(".ISO"))
	    {
	             QString fichierDest=param.section(".ISO",0,0);
		fichierDest+=".cso";
		w.leDest->setText(fichierDest);
	    }
	    if(param.contains(".iso"))
	    {
		 QString fichierDest=param.section(".iso",0,0);
		  fichierDest+=".cso";
		 w.leDest->setText(fichierDest);
	    }
	}
	if(param.contains(".CSO") || param.contains(".cso"))
	{
	    w.panneaux->showPage(w.panneaux->page(1));
	    w.leSrcDecomp->setText(param);
	    QString fichierDest=param.section(".cso",0,0);
	fichierDest+=".iso";
             w.leDstDecomp->setText(fichierDest);
	     w.decompressMethod();
	}
	if(param.contains(".DAX") || param.contains(".dax"))
	{
                 w.panneaux->showPage(w.panneaux->page(1));
	    w.leSrcDecomp->setText(param);
	     QString fichierDest=param.section(".dax",0,0);
	     fichierDest+=".iso";
                  w.leDstDecomp->setText(fichierDest);
		     w.decompressMethod();
	}
    }
     w.show();

   a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
	 
    return a.exec();
}
