/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
#include <qfiledialog.h> 
#include <iostream.h>
#include <qmessagebox.h> 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <qeventloop.h> 
#include <qfiledialog.h> 
#include <qtextstream.h> 
#include <qfile.h>
#include <qftp.h> 
#include <qprogressdialog.h>
#include <qdir.h> 


//Version du logiciel
QString version="0.37 BETA";

QString formMain::ecrire( int number )
{
    QString language=cbLng->currentText();
    if(language=="FRANCAIS")
    {
	QString pathLangue=path+"fr.txt";

		QFile fichierOption(pathLangue);
		if( fichierOption.open(IO_ReadOnly))
		{
			QTextStream fluxLecture( &fichierOption);
			QString chaineALire;
			QString convert;
			chaineALire = fluxLecture.readLine();
			for(int i=0;i<number;i++)
			{
				chaineALire=fluxLecture.readLine();
			}
			
			int nbSubString=0;
			nbSubString=chaineALire.contains("\n")+1;
			QStringList listString = QStringList::split("\n",chaineALire);
			QString recomp="";
			if(listString.size()==1)
			{
			    recomp=listString[0];
			}
			else
			{
			    for(int i=0;i<=listString.size();i++)
			    {
				if(i<listString.size())recomp+=listString[i]+"\n";
				if(i=listString.size())recomp+=listString[i];
				
			     }
			    
			}

			return recomp;
		    }
    }
    else if(language=="ENGLISH")
    {
	QString pathLangue=path+"en.txt";


		QFile fichierOption(pathLangue);
		if( fichierOption.open(IO_ReadOnly))
		{
			QTextStream fluxLecture( &fichierOption);
			QString chaineALire;
			QString convert;
			chaineALire= fluxLecture.readLine();
			for(int i=0;i<number;i++)
			{
				chaineALire=fluxLecture.readLine();
			}
			
			int nbSubString=0;
			nbSubString=chaineALire.contains("\n")+1;
			QStringList listString = QStringList::split("\n",chaineALire);
			QString recomp="";
			if(listString.size()==1)
			{
			    recomp=listString[0];
			}
			else
			{
			    for(int i=0;i<=listString.size();i++)
			    {
				if(i<listString.size())recomp+=listString[i]+"\n";
				if(i=listString.size())recomp+=listString[i];
				
			     }
			    
			}
			
			return recomp;
		
		    }
     }
	return "";
}




 bool formMain::copieDeFichier(QString source,QString destination)
   {
      
       QFile sourceFile(source);
       QFile destinationFile(destination);

       if(sourceFile.open(IO_ReadOnly) && destinationFile.open(IO_WriteOnly))
       {
	   lblStatut->setText(ecrire(1));
	   uint dataLength = 4096;
	   char *data = new char[dataLength];
	   ulong completed = 0;
	   ulong compteur=0;
	   QString octet;
	   long tailleSource=sourceFile.size()/4096;
	   int ratio = 0;
	   QMessageBox::information(this,ecrire(2),(ecrire(3)+octet.setNum(tailleSource)));
	   lblTailleCopie->setText(ecrire(4)+octet.setNum(tailleSource));
	   while(!sourceFile.atEnd())
	   {
	       completed += sourceFile.readBlock(data, dataLength);
	       destinationFile.writeBlock(data, dataLength);
	       compteur++;
	       
	       lblStatut->setText(ecrire(5)+octet.setNum(compteur));
	        a->eventLoop()->processEvents(QEventLoop::AllEvents); 
	   }
	     sourceFile.close();
	   destinationFile.close();
	  delete[] data;
	    lblStatut->setText(ecrire(6));
	  return true;
	   
       }
       else
       {
	  return false;
       }
   }
   
   
   

void formMain::parcourSrc()
{
    QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "ISO File (*.iso)",
                    this,
                    "open file dialog",
                    ecrire(7));
    leSrc->setText(nomSrc);
    QString fichierDest=nomSrc.section(".iso",0,0);
    
    if(cbCompressType->currentText()=="CSO")
    {
	fichierDest+=".cso";
	leDest->setText(fichierDest);
    }
     if(cbCompressType->currentText()=="DAX")
    {
	 fichierDest+=".dax";
	leDest->setText(fichierDest);
     }
     if(cbCompressType->currentText()=="JSO")
    {
	 fichierDest+=".jso";
	leDest->setText(fichierDest);
     }
 }

void formMain::parcourDest()
{
    if(cbCompressType->currentText()=="CSO")
    {
	QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "CSO File (*.cso)",
                    this,
                    "save file dialog",
                    ecrire(8) );
	leDest->setText(nomDest);
    }
    if(cbCompressType->currentText()=="DAX")
    {
		QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Dax File (*.dax)",
                    this,
                    "save file dialog",
                    ecrire(9) );
	leDest->setText(nomDest);
    }
    if(cbCompressType->currentText()=="JSO")
    {
		QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "JSO File (*.jso)",
                    this,
                    "save file dialog",
                    ecrire(10) );
	leDest->setText(nomDest);
    }
    
}


void formMain::compress()
{
     if(cbCompressType->currentText()=="CSO")
    {
    QString nomSrc=leSrc->text();
    QString nomDest=leDest->text();
    QString tauxCompress=cbCompressLevel->currentText();
    QString chaine = "ciso "+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
    int reponse=QMessageBox::question ( this,ecrire(11),ecrire(12),QMessageBox::Yes,QMessageBox::No,0);
      if(reponse==QMessageBox::Yes)
      {
	  system(chaine);
	  QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus=ecrire(13)+octet.setNum(tailleSource)+ecrire(13)+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this,ecrire(15),CompressStatus,QMessageBox::Ok,0,0);
      }
      if(reponse==QMessageBox::No)
      {
	  QMessageBox::information ( this,ecrire(16),ecrire(17),QMessageBox::Ok,0,0);
      }
    
    }
     
     
      if(cbCompressType->currentText()=="DAX")
    {
	   QString nomSrc=leSrc->text();
	   QString nomDest=leDest->text();
	   QString tauxCompress=cbCompressLevel->currentText();
	   
	   //Vérification des check box et creation des parametres adéquat
	   QString NCSize=0;
	   if(cbNC->isOn()==true)
	   {
	     NCSize=leTailleNC->text();
	       
	       QString chaine= "daxcr -a"+NCSize+" -l"+tauxCompress;
	      if(cbVnc->isOn()==true)chaine+=" -v";
	      if(cbAnc->isOn()==true)chaine+=" -s";
	      chaine+=" -w";
	      chaine+=" \""+nomSrc+"\" \""+nomDest+"\"";
	      int reponse=QMessageBox::question ( this,ecrire(11),ecrire(18),QMessageBox::Yes,QMessageBox::No,0);
	      if(reponse==QMessageBox::Yes)
	      {
		  system(chaine);
		 QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus=ecrire(13)+octet.setNum(tailleSource)+ecrire(19)+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this,ecrire(20),CompressStatus,QMessageBox::Ok,0,0);
	      }
	      if(reponse==QMessageBox::No)
	      {
		  QMessageBox::information ( this,ecrire(21),ecrire(22),QMessageBox::Ok,0,0);
	      }
	      
	   }
	   else
	   {
	       
	        QString chaine = "daxcr -l"+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
	         system(chaine);  
	    }
      }
      if(cbCompressType->currentText()=="JSO")
    {
    QString nomSrc=leSrc->text();
    QString nomDest=leDest->text();
    QString tauxCompress=cbCompressLevel->currentText();
    QString blockSize;
    QString supChaine=" ";
    if(r2048->isChecked()==true)
    {
	blockSize="2048";
    }
    else if(r4096->isChecked()==true)
    {
	blockSize="4096";
    }
    else if(r8192->isChecked()==true)
    {
	blockSize="8192";
    }
    else if(r16384->isChecked()==true)
    {
	blockSize="16384";
    }
    if(headBlock->isOn()==true)
    {
	supChaine+="-B ";
    }
    if(zlibComp->isOn()==true)
    {
	supChaine+="-a zlib ";
    }
   
    
    QString chaine = "jiso -c -l "+tauxCompress+" -b "+blockSize+supChaine+"-i \""+nomSrc+"\" -o \""+nomDest+"\"";
    int reponse=QMessageBox::question ( this,ecrire(11),ecrire(23),QMessageBox::Yes,QMessageBox::No,0);
      if(reponse==QMessageBox::Yes)
      {
	  system(chaine);
	  QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus=ecrire(13)+octet.setNum(tailleSource)+ecrire(24)+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this,ecrire(25),CompressStatus,QMessageBox::Ok,0,0);
      }
      if(reponse==QMessageBox::No)
      {
	  QMessageBox::information ( this,ecrire(26),ecrire(27),QMessageBox::Ok,0,0);
      }
    
    }
      
      if(isoSuppression->isOn())
      {
	   QFile::remove(leSrc->text());
       }
         if(closeProgram->isOn())
       {
	   QApplication::exit( 0 );
       }
      bCopie->setEnabled(true);
     
  }


void formMain::degriserNCAVOption()
{
    if( cbNC->isOn()==true)
    {
	cbVnc->setEnabled(true);
	cbAnc->setEnabled(true);
    }
      if( cbNC->isOn()==false)
    {
	cbVnc->setEnabled(false);
	cbAnc->setEnabled(false);
    }
}




void formMain::degriserNCOption()
{
    if(cbCompressType->currentText()=="DAX")
    {
	 gbOptionDax->setEnabled(true);
	 cbNC->setEnabled(true);
	 leTailleNC->setEnabled(true);
	 jsoOption->setEnabled(false);
     }
     if(cbCompressType->currentText()=="CSO")
    {
	 gbOptionDax->setEnabled(false);
	 jsoOption->setEnabled(false);
     }
     if(cbCompressType->currentText()=="JSO")
    {
	 gbOptionDax->setEnabled(false);
	 jsoOption->setEnabled(true);
     }
}


void formMain::decompressMethod()
{
    int currentItemDecompress=cbDecompWay->currentItem ();
    if(currentItemDecompress==0)
    {
	sdecompressMethod="CSO/ISO";
	lblFileDecompSrc->setText(ecrire(28));
	lblFileDecompDst->setText(ecrire(29));
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
	
    }
    else if(currentItemDecompress==1)
    {
	sdecompressMethod="CSO/DAX";
	lblFileDecompSrc->setText(ecrire(30));
	lblFileDecompDst->setText(ecrire(31));
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
    }
    else if(currentItemDecompress==2)
    {
	sdecompressMethod="CSO/JSO";
	lblFileDecompSrc->setText(ecrire(32));
	lblFileDecompDst->setText(ecrire(33));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
    else if(currentItemDecompress==3)
    {
	sdecompressMethod="DAX/ISO";
	lblFileDecompSrc->setText(ecrire(34));
	lblFileDecompDst->setText(ecrire(35));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
       else if(currentItemDecompress==4)
    {
	sdecompressMethod="DAX/CSO";
	lblFileDecompSrc->setText(ecrire(36));
	lblFileDecompDst->setText(ecrire(37));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
          else if(currentItemDecompress==5)
    {
	sdecompressMethod="DAX/JSO";
	lblFileDecompSrc->setText(ecrire(38));
	lblFileDecompDst->setText(ecrire(39));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
     else if(currentItemDecompress==6)
    {
	sdecompressMethod="JSO/ISO";
	lblFileDecompSrc->setText(ecrire(40));
	lblFileDecompDst->setText(ecrire(41));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
     else if(currentItemDecompress==7)
    {
	sdecompressMethod="JSO/CSO";
	lblFileDecompSrc->setText(ecrire(42));
	lblFileDecompDst->setText(ecrire(43));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
     else if(currentItemDecompress==8)
    {
	sdecompressMethod="JSO/DAX";
	lblFileDecompSrc->setText(ecrire(44));
	lblFileDecompDst->setText(ecrire(45));
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
    pDecompress->setEnabled(true);
    lblFileDecompSrc->setEnabled(true);
    lblFileDecompDst->setEnabled(true);
    leSrcDecomp->setEnabled(true);
    pbBrowseDecompSrc->setEnabled(true);
    leDstDecomp->setEnabled(true);
    pbBrowseDecompDst->setEnabled(true);
	    
	    
}


void formMain::parcourSrcDecompress()
{
    
    if(sdecompressMethod=="CSO/ISO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "CSO File (*.cso)",
                    this,
                    "open file dialog",
		    ecrire(46) );
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
       else if(sdecompressMethod=="CSO/DAX")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "CSO File (*.cso)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".dax";
             leDstDecomp->setText(fichierDest);
    }
          else if(sdecompressMethod=="CSO/JSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "CSO File (*.cso)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".jso";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX File (*.dax)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    } 
    else if(sdecompressMethod=="DAX/CSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX File (*.dax)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".cso";
             leDstDecomp->setText(fichierDest);
    }
        else if(sdecompressMethod=="DAX/JSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX File (*.dax)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".jso";
             leDstDecomp->setText(fichierDest);
    }
	    else if(sdecompressMethod=="JSO/ISO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "JSO File (*.jso)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".jso",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
	    	    else if(sdecompressMethod=="JSO/CSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "JSO File (*.jso)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".jso",0,0);
	fichierDest+=".cso";
             leDstDecomp->setText(fichierDest);
    }
		    	    else if(sdecompressMethod=="JSO/DAX")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "JSO File(*.jso)",
                    this,
                    "open file dialog",
                    ecrire(46));
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".jso",0,0);
	fichierDest+=".dax";
             leDstDecomp->setText(fichierDest);
    }

    
}


void formMain::parcourDstDecompress()
{
     if(sdecompressMethod=="CSO/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier ISO (*.iso)",
                    this,
                    "save file dialog",
                    ecrire(47));
	leDstDecomp->setText(nomDest);
	 
     }
      else if(sdecompressMethod=="CSO/DAX")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier DAX (*.dax)",
                    this,
                    "save file dialog",
                    ecrire(48));
	leDstDecomp->setText(nomDest);
	    
    }
       else if(sdecompressMethod=="CSO/JSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier JSO (*.jso)",
                    this,
                    "save file dialog",
                    ecrire(49));
	leDstDecomp->setText(nomDest);
	    
    }
     
    else if(sdecompressMethod=="DAX/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier ISO (*.iso)",
                    this,
                    "save file dialog",
                    ecrire(50));
	leDstDecomp->setText(nomDest);
	   
     }   
    else if(sdecompressMethod=="DAX/CSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier CSO (*.cso)",
                    this,
                    "save file dialog",
                    ecrire(51));
	leDstDecomp->setText(nomDest);
    }
      else if(sdecompressMethod=="DAX/JSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier JSO (*.jso)",
                    this,
                    "save file dialog",
                    ecrire(52));
	leDstDecomp->setText(nomDest);
	    
    }
      else if(sdecompressMethod=="JSO/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier ISO (*.iso)",
                    this,
                    "save file dialog",
                    ecrire(53));
	leDstDecomp->setText(nomDest);
	   
     }   
        else if(sdecompressMethod=="JSO/CSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier CSO (*.cso)",
                    this,
                    "save file dialog",
                    ecrire(54));
	leDstDecomp->setText(nomDest);
    }
	 else if(sdecompressMethod=="JSO/DAX")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier DAX (*.dax)",
                    this,
                    "save file dialog",
                    ecrire(55));
	leDstDecomp->setText(nomDest);
	    
    }
	
      

}


void formMain::decompress()
{
      if(sdecompressMethod=="CSO/ISO")
    {
	    QString nomSrc=leSrcDecomp->text();
                 QString nomDest=leDstDecomp->text();
                
	    QString chaine = "ciso 0"" \""+nomSrc+"\" \""+nomDest+"\"";
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(57),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this,ecrire(58),ecrire(61),QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this,ecrire(59),ecrire(62),QMessageBox::Ok,0,0);
                  }
    } 
      else if(sdecompressMethod=="CSO/DAX")
    {
	    QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".cso",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "ciso 0"" \""+nomSrc+"\" \""+ fichierDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
                 QString chaine2 = "daxcr -l"+scompressLevel+" \""+ fichierDest+"\" \""+nomDest+"\"";
                
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(60),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this,ecrire(58),ecrire(63),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, ecrire(64),ecrire(126),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(65),ecrire(127),QMessageBox::Ok,0,0);
                  }
    }
       else if(sdecompressMethod=="CSO/JSO")
    {
	   QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".cso",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "ciso 0"" \""+nomSrc+"\" \""+ fichierDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
	   QString chaine2 = "jiso -c -l "+scompressLevel+" -i \""+ fichierDest+"\" -o \""+nomDest+"\"";
	    int reponse=QMessageBox::question ( this,ecrire(56),ecrire(66),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this,ecrire(67),ecrire(68),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this,ecrire(69),ecrire(70),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this,ecrire(71),ecrire(72),QMessageBox::Ok,0,0);
                  }
       }
				      
	  
     
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc=leSrcDecomp->text();
                 QString nomDest=leDstDecomp->text();
                
	    QString chaine = "daxcr -d"" \""+nomSrc+"\" \""+nomDest+"\"";
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(73),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, ecrire(74),ecrire(75),QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(76),ecrire(77),QMessageBox::Ok,0,0);
                  }
	   
     }
    
    else if(sdecompressMethod=="DAX/CSO")
    {
	 QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".dax",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "daxcr -d"" \""+nomSrc+"\" \""+ fichierDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
	    QString chaine2 = "ciso "+scompressLevel+" \""+ fichierDest+"\" \""+nomDest+"\"";
                 
                
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(78),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, ecrire(79),ecrire(80),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, ecrire(81),ecrire(82),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(83),ecrire(84),QMessageBox::Ok,0,0);
                  }
	
    }
    
      else if(sdecompressMethod=="DAX/JSO")
    {
	  QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".dax",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "daxcr -d"" \""+nomSrc+"\" \""+ fichierDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
	    QString chaine2 = "jiso -c -l "+scompressLevel+" -i \""+ fichierDest+"\" -o \""+nomDest+"\"";
                 
                
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(85),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, ecrire(86),ecrire(87),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, ecrire(88),ecrire(89),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(90),ecrire(91),QMessageBox::Ok,0,0);
                  }
	   
       }
     else if(sdecompressMethod=="JSO/ISO")
    {
	 QString nomSrc=leSrcDecomp->text();
                 QString nomDest=leDstDecomp->text();
                
	    QString chaine = "jiso -d  -i \""+nomSrc+"\" -o \""+nomDest+"\"";
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(92),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, ecrire(93),ecrire(94),QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(95),ecrire(96),QMessageBox::Ok,0,0);
                  }
	   
       }
  else if(sdecompressMethod=="JSO/CSO")
    {
      QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".jso",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "jiso -d  -i \""+nomSrc+"\" -o \""+nomDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
	    QString chaine2 = "ciso "+scompressLevel+" \""+ fichierDest+"\" \""+nomDest+"\"";
                 
                
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(97),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, ecrire(98),ecrire(99),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, ecrire(100),ecrire(101),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(102),ecrire(103),QMessageBox::Ok,0,0);
                  }
	   
  }
    else if(sdecompressMethod=="JSO/DAX")
    {
	 QString nomSrc=leSrcDecomp->text();
	    QString fichierDest=nomSrc.section(".jso",0,0);
	     fichierDest+=".isotemp";
                 QString nomDest=leDstDecomp->text();
                 QString chaine1 = "jiso -d  -i \""+nomSrc+"\" -o \""+nomDest+"\"";
                 QString scompressLevel=cbDecompressLevel->currentText();
                 QString chaine2 = "daxcr -l"+scompressLevel+" \""+ fichierDest+"\" \""+nomDest+"\"";
                
                  int reponse=QMessageBox::question ( this,ecrire(56),ecrire(104),QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, ecrire(105),ecrire(106),QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, ecrire(107),ecrire(108),QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, ecrire(109),ecrire(110),QMessageBox::Ok,0,0);
                  }
	   
       }
    

}



void formMain::copieFichierCompress()
{
    //Comptage du nombre de caractere \ dans la box leDest
    QString fichierDest;
    QString fichierCopie;
    int nbDeSeparateur=0;
    fichierDest=leDest->text();
    nbDeSeparateur= fichierDest.contains("/");
    if(nbDeSeparateur!=0)
    {
	fichierCopie=bDriveLetter->currentText();
	fichierCopie+="ISO/";
	fichierCopie+= fichierDest.section("/",nbDeSeparateur,nbDeSeparateur);
	int reponse= QMessageBox::question ( this, ecrire(111),fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	if(reponse==QMessageBox::Yes)
	{
	  bool decomp=copieDeFichier (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this, ecrire(112),ecrire(113),QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this, ecrire(114),ecrire(115),QMessageBox::Ok,0,0);
	       }
	    
	}
	else
	{
	   QMessageBox::warning ( this,ecrire(114),ecrire(115),QMessageBox::Ok,0,0);   
	}
    }
    else if(nbDeSeparateur==0)
    {
	nbDeSeparateur= fichierDest.contains("\\");
	  fichierCopie=bDriveLetter->currentText();
	    fichierCopie=fichierCopie.replace(2,1,"\\");
	    fichierCopie+="ISO\\";
	    fichierCopie+= fichierDest.section("\\",nbDeSeparateur,nbDeSeparateur);
	    int reponse= QMessageBox::question ( this, ecrire(116),fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	    if(reponse==QMessageBox::Yes)
	{
		bool decomp=copieDeFichier  (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this, ecrire(117),ecrire(118),QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this,ecrire(114),ecrire(115),QMessageBox::Ok,0,0);   
		}
	}
	else
	{
	  
	}
    }
   
}




void formMain::parcourDirISO()
{
    QString dirSelectionner;
    dirSelectionner=QFileDialog::getExistingDirectory(
                    "",
                    this,
                    "get existing directory",
                    ecrire(119),
                    TRUE );
    leSaveFolder->setText(dirSelectionner);
    dirOpenSave=dirSelectionner;    
}


void formMain::savOption()
{
    // Récupération des différents elements saisie par la personne
    indexDriveLetter=bDriveLetter_2->currentItem();
    bDriveLetter->setCurrentItem(indexDriveLetter);
    dirOpenSave=leSaveFolder->text();
    QString pathLangue=path+"lang.txt";
    QFile fichierLang(pathLangue);
	    fichierLang.remove();
    if( fichierLang.open(IO_WriteOnly))
    {
	QTextStream aEnregistrerLng(&fichierLang);
	aEnregistrerLng << cbLng->currentText();
	fichierLang.close();
    }
    else
   {
       QMessageBox::warning ( this, ecrire(120),ecrire(120),QMessageBox::Ok,0,0);   
   }
    
    QString pathOption=path+"option.txt";
    QFile fichierOption(pathOption);
    fichierOption.remove();
   if( fichierOption.open(IO_WriteOnly))
    {
       
       QString convert;
    QTextStream aEnregistrer(&fichierOption);
    aEnregistrer << "CSO-DAX COMPRESSOR" << "\n";
    aEnregistrer << version << "\n";
    aEnregistrer << dirOpenSave << "\n";
    aEnregistrer << convert.setNum(bDriveLetter_2->currentItem()) << "\n";
    aEnregistrer << cbStyle->currentItem() << "\n";
     fichierOption.close();
     
     //Mise en place du theme
     if(cbStyle->currentText()=="motif")
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
			      this->setPalette(pal);
			      
	    }
		else if (cbStyle->currentText()=="cde")
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
                             this->setPalette(pal);
	   }
		else if (cbStyle->currentText()=="motifplus")
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
               this->setPalette(pal);
			   
		
		
	   }
	   else if(cbStyle->currentText()=="platinum")
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
			this->setPalette(pal);
	    }
		
		else if(cbStyle->currentText()=="sgi")
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
    
			this->setPalette(pal);
	    }
		
		else if(cbStyle->currentText()=="compact")
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
			this->setPalette(pal);
	    }
		a->setStyle(cbStyle->currentText());
     
     
}
   else
   {
       QMessageBox::warning ( this, ecrire(120),ecrire(120),QMessageBox::Ok,0,0);   
   }
   
    
    
}


void formMain::setDefaultOption()
{
        bDriveLetter_2->setCurrentItem(0);
	bDriveLetter->setCurrentItem(0);
	leSaveFolder->setText("C:\\");
	dirOpenSave="C:\\";
	cbStyle->setCurrentItem(0);
}


void formMain::verifUpdate()
{
 
}      
    











void formMain::choixDossierCompress()
{
      QString dirSelectionner;
    dirSelectionner=QFileDialog::getExistingDirectory(
                    "",
                    this,
                    "get existing directory",
                    ecrire(119),
                    TRUE );
    leSrc_2->setText(dirSelectionner);
}


void formMain::CompressFolder()
{
    QDir dirISO( leSrc_2->text());
    uint nbOfFile=dirISO.count();
    QString nbOfFilestr;
    QString nbOfFileISOstr;
    QString* listeDesFichiersACompresser;
    int compteurFichierCompresser=0;
    //QMessageBox::information(this,"Nombre de fichier ISO",("Nb de fichiers dans le dossier:"+nbOfFilestr.setNum(nbOfFile)),QMessageBox::Ok,0,0);
     for(uint i=0;i<nbOfFile;i++)
    {
	 if(dirISO[i] !="." && dirISO[i] !=".." && (dirISO[i].contains(".ISO") || dirISO[i].contains(".iso")))
	 {
	     //QMessageBox::information(this,"Fichier ISO",dirISO[i],QMessageBox::Ok,0,0);
	     compteurFichierCompresser++;
	 }
    }
    listeDesFichiersACompresser= new QString [ compteurFichierCompresser];
    compteurFichierCompresser=0;
    for(uint i=0;i<nbOfFile;i++)
    {
	 if(dirISO[i] !="." && dirISO[i] !=".." && (dirISO[i].contains(".ISO") || dirISO[i].contains(".iso")))
	 {
	     //QMessageBox::information(this,"Fichier ISO",dirISO[i],QMessageBox::Ok,0,0);
	     listeDesFichiersACompresser[compteurFichierCompresser]=dirISO[i];
	       compteurFichierCompresser++;
	 }
    }
    QString aAfficheListe=ecrire(122)+nbOfFileISOstr.setNum(compteurFichierCompresser)+ecrire(123);
    for(int i=0;i<compteurFichierCompresser;i++)aAfficheListe+= listeDesFichiersACompresser[i]+"\n";
    QMessageBox::information(this,ecrire(124),aAfficheListe,QMessageBox::Ok,0,0);
    
    for(int i=0;i<nbOfFile;i++)
    {
	 if(dirISO[i] !="." && dirISO[i] !=".." && (dirISO[i].contains(".ISO") || dirISO[i].contains(".iso")))
	 {
	      QString fichierDest=dirISO[i].section(".iso",0,0);
	        if(cbCompressType_2->currentText()=="CSO")
	       {
		    fichierDest+=".cso";
                    }
	       if(cbCompressType_2->currentText()=="DAX")
	       {
		    fichierDest+=".dax";
	       }
	       
	       
	       
	       //Compression au format CSO avec un dossier
	        if(cbCompressType_2->currentText()=="CSO")
                     {
		    QString nomSrc= leSrc_2->text()+"/"+dirISO[i];
		    QString nomDest= leSrc_2->text()+"/"+ fichierDest;
		    QString tauxCompress=cbCompressLevel_2->currentText();
		    QString chaine = "ciso "+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
			int reponse=QMessageBox::Yes;
		    if(reponse==QMessageBox::Yes)
		    {
			system(chaine);
			QFile fSrc(nomSrc);
			QFile fDest(nomDest);
			QString octet;
			QString octet2;
			int tailleSource=(int)(fSrc.size()/1000000);
			int tailleDest=(int)(fDest.size()/1000000);
			//QString CompressStatus="La compression CSO est terminé \n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier CSO :"+octet2.setNum(tailleDest)+" Mo";
			//QMessageBox::information ( this, "Compression CSO terminé.................. ",CompressStatus,QMessageBox::Ok,0,0);
		    }
		    if(reponse==QMessageBox::No)
		    {
			QMessageBox::information ( this, ecrire(16),ecrire(17),QMessageBox::Ok,0,0);
		    }
		    
                     }
		
	        //Compression au format DAX avec un dossier
		if(cbCompressType->currentText()=="DAX")
		{
		    QString nomSrc= leSrc_2->text()+"/"+dirISO[i];
		    QString nomDest= leSrc_2->text()+"/"+ fichierDest;
		    QString tauxCompress=cbCompressLevel_2->currentText();
		    //Vérification des check box et creation des parametres adéquat
		    QString NCSize=0;
		    if(cbNC_2->isOn()==true)
		    {
			NCSize=leTailleNC_2->text();
			
			QString chaine= "daxcr -a"+NCSize+" -l"+tauxCompress;
			if(cbVnc_2->isOn()==true)chaine+=" -v";
			if(cbAnc_2->isOn()==true)chaine+=" -s";
			chaine+=" -w";
			chaine+=" \""+nomSrc+"\" \""+nomDest+"\"";
			int reponse=QMessageBox::Yes;
			if(reponse==QMessageBox::Yes)
			{
			    system(chaine);
			    QFile fSrc(nomSrc);
			    QFile fDest(nomDest);
			    QString octet;
			    QString octet2;
			    int tailleSource=(int)(fSrc.size()/1000000);
			    int tailleDest=(int)(fDest.size()/1000000);
			    //QString CompressStatus="La compression DAX est terminé \n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier DAX :"+octet2.setNum(tailleDest)+" Mo";
			   //QMessageBox::information ( this, "Compression DAX terminé.................. ",CompressStatus,QMessageBox::Ok,0,0);
			}
			if(reponse==QMessageBox::No)
			{
			    QMessageBox::information ( this,ecrire(21),ecrire(22),QMessageBox::Ok,0,0);
			}
			
		    }
		    else
		    {
			QString chaine = "daxcr -l"+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
			system(chaine);  
		    }
                       }
		
		 if(cbCompressType_2->currentText()=="JSO")
                     {
		    QString nomSrc= leSrc_2->text()+"/"+dirISO[i];
		    QString nomDest= leSrc_2->text()+"/"+ fichierDest;
		    QString tauxCompress=cbCompressLevel_2->currentText();
		    QString chaine = "jiso -c -l "+tauxCompress+" -i \""+nomSrc+"\" -o \""+nomDest+"\"";
			int reponse=QMessageBox::Yes;
		    if(reponse==QMessageBox::Yes)
		    {
			system(chaine);
			QFile fSrc(nomSrc);
			QFile fDest(nomDest);
			QString octet;
			QString octet2;
			int tailleSource=(int)(fSrc.size()/1000000);
			int tailleDest=(int)(fDest.size()/1000000);
			//QString CompressStatus="La compression CSO est terminé \n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier CSO :"+octet2.setNum(tailleDest)+" Mo";
			//QMessageBox::information ( this, "Compression CSO terminé.................. ",CompressStatus,QMessageBox::Ok,0,0);
		    }
		    if(reponse==QMessageBox::No)
		    {
			QMessageBox::information ( this,ecrire(26),ecrire(27),QMessageBox::Ok,0,0);
		    }
		    
                     }
		
	       
	       
	 }
     }
           QMessageBox::information ( this,ecrire(125),ecrire(126),QMessageBox::Ok,0,0);
       if(isoSuppression_2->isOn())
      {
	   QFile::remove(leSrc->text());
       }
       if(closeProgram_2->isOn())
       {
	   QApplication::exit( 0 );
       }
      
	
    
      
}


void formMain::choixCompressTypeFolder()
{
	
}


void formMain::degriserNCAVOptionFolder()
{
     if( cbNC_2->isOn()==true)
    {
	cbVnc_2->setEnabled(true);
	cbAnc_2->setEnabled(true);
    }
      if( cbNC_2->isOn()==false)
    {
	cbVnc_2->setEnabled(false);
	cbAnc_2->setEnabled(false);
    }
}


void formMain::degriserNCOptionFolder()
{
     if(cbCompressType_2->currentText()=="DAX")
    {
	 gbOptionDax_2->setEnabled(true);
	 cbNC_2->setEnabled(true);
	 leTailleNC_2->setEnabled(true);
	 jsoOption->setEnabled(false);
     }
     if(cbCompressType_2->currentText()=="CSO")
    {
	 gbOptionDax_2->setEnabled(false);
     }
     if(cbCompressType_2->currentText()=="JSO")
    {
	 gbOptionDax_2->setEnabled(false);
	 jsoOption->setEnabled(true);
     }
}





