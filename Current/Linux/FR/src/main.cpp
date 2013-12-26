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

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    formMain w;
    w.a=&a;
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
	}
	if(param.contains(".DAX") || param.contains(".dax"))
	{
                 w.panneaux->showPage(w.panneaux->page(1));
	    w.leSrcDecomp->setText(param);
	}
    }
    //Chargement du fichier option
     QFile fichierOption("option.txt");
      if( fichierOption.open(IO_ReadOnly))
    {
	  QTextStream fluxLecture( &fichierOption);
	  QString chaineALire;
	  QString convert;
	chaineALire= fluxLecture.readLine();
	chaineALire=fluxLecture.readLine();
	   if(chaineALire=="0.32 BETA")
	   {
	        chaineALire=fluxLecture.readLine();
	        w.dirOpenSave=chaineALire;
		chaineALire=fluxLecture.readLine();
		int itemDrivePSPLetter = chaineALire.toInt();
		w.leSaveFolder->setText(w.dirOpenSave);
		w.bDriveLetter->setCurrentItem(itemDrivePSPLetter);
		w.bDriveLetter_2->setCurrentItem(itemDrivePSPLetter);
	   }
	   else if(chaineALire=="0.33 BETA" || chaineALire=="0.34 BETA")
	   {
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
	   }
	   
	   
      }
      else
      {
	  w.bDriveLetter->setCurrentItem(0);
	  w.dirOpenSave="";
      }
     w.show();

   a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
	 
    return a.exec();
}
