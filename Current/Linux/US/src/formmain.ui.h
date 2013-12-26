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
#include <string.h>
#include <qeventloop.h> 
#include <qfiledialog.h> 
#include <qtextstream.h> 
#include <qfile.h>
#include <qftp.h> 
#include <qprogressdialog.h>
#include <qdir.h> 


//Version du logiciel
QString version="0.34 BETA";

 bool formMain::copieDeFichier(QString source,QString destination)
   {
      
       QFile sourceFile(source);
       QFile destinationFile(destination);

       if(sourceFile.open(IO_ReadOnly) && destinationFile.open(IO_WriteOnly))
       {
	   lblStatut->setText("COPY INITIATE");
	   uint dataLength = 4096;
	   char *data = new char[dataLength];
	   ulong completed = 0;
	   ulong compteur=0;
	   QString octet;
	   long tailleSource=sourceFile.size()/4096;
	   int ratio = 0;
	   QMessageBox::information(this,"Source",("Size of file to copy :<br>"+octet.setNum(tailleSource)));
	   lblTailleCopie->setText("On :<br>"+octet.setNum(tailleSource));
	   while(!sourceFile.atEnd())
	   {
	       completed += sourceFile.readBlock(data, dataLength);
	       destinationFile.writeBlock(data, dataLength);
	       compteur++;
	       
	       lblStatut->setText("Block :"+octet.setNum(compteur));
	        a->eventLoop()->processEvents(QEventLoop::AllEvents); 
	   }
	     sourceFile.close();
	   destinationFile.close();
	  delete[] data;
	    lblStatut->setText("Copie Sucessfull");
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
                    "Choose the ISO you want to compress" );
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
                    "Choose the file where you want to save the CSO File" );
	leDest->setText(nomDest);
    }
    if(cbCompressType->currentText()=="DAX")
    {
		QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichiers Dax (*.dax)",
                    this,
                    "save file dialog",
                    "Choose where you want to save the Dax File" );
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
    int reponse=QMessageBox::question ( this,"Compression ?","Are you sure you want to convert your ISO to CSO?",QMessageBox::Yes,QMessageBox::No,0);
      if(reponse==QMessageBox::Yes)
      {
	  system(chaine);
	  QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus="CSO compression is over\n Original ISO file size:"+octet.setNum(tailleSource)+" Mo\n CSO compressed file size :"+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this, "CSO Compression is over.................. ",CompressStatus,QMessageBox::Ok,0,0);
      }
      if(reponse==QMessageBox::No)
      {
	  QMessageBox::information ( this, "Compression CSO canceled","You have cancel the CSO compression",QMessageBox::Ok,0,0);
      }
    
    }
     
     
      if(cbCompressType->currentText()=="DAX")
    {
	   QString nomSrc=leSrc->text();
	   QString nomDest=leDest->text();
	   QString tauxCompress=cbCompressLevel->currentText();
	   
	   //V�ification des check box et creation des parametres ad�uat
	   QString NCSize=0;
	   if(cbNC->isOn()==true)
	   {
	     NCSize=leTailleNC->text();
	       
	       QString chaine= "daxcr -a"+NCSize+" -l"+tauxCompress;
	      if(cbVnc->isOn()==true)chaine+=" -v";
	      if(cbAnc->isOn()==true)chaine+=" -s";
	      chaine+=" -w";
	      chaine+=" \""+nomSrc+"\" \""+nomDest+"\"";
	     int reponse=QMessageBox::question ( this,"Compression ?","Are you sure you want to convert the ISO file to<br>DAX file with NC area ?",QMessageBox::Yes,QMessageBox::No,0);
	      if(reponse==QMessageBox::Yes)
	      {
		  system(chaine);
		 QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus="CSO compression is over\n Original ISO file size:"+octet.setNum(tailleSource)+" Mo\n DAX compressed file size :"+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this, "DAX Compression is over.................. ",CompressStatus,QMessageBox::Ok,0,0);
	      }
	      if(reponse==QMessageBox::No)
	      {
		  QMessageBox::information ( this, "Compression DAX canceled","You have canceled the DAX compression",QMessageBox::Ok,0,0);
	      }
	      
	   }
	   else
	   {
	        QString chaine = "daxcr -l"+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
	         system(chaine);  
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
     }
     if(cbCompressType->currentText()=="CSO")
    {
	 gbOptionDax->setEnabled(false);
     }
}


void formMain::decompressMethod()
{
    int currentItemDecompress=cbDecompWay->currentItem ();
    if(currentItemDecompress==0)
    {
	sdecompressMethod="CSO/ISO";
	lblFileDecompSrc->setText("CSO file you want to decompress");
	lblFileDecompDst->setText("ISO file when the decompres is OK");
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
	
    }
    else if(currentItemDecompress==1)
    {
	sdecompressMethod="DAX/ISO";
	lblFileDecompSrc->setText("DAX  file you want to decompress");
	lblFileDecompDst->setText("ISO file when the decompres is OK");
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
    }
    else if(currentItemDecompress==2)
    {
	sdecompressMethod="CSO/DAX";
	lblFileDecompSrc->setText("CSO  file you want to decompress");
	lblFileDecompDst->setText("DAX file when the decompres and recompress  is OK");
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
    }
    else if(currentItemDecompress==3)
    {
	sdecompressMethod="DAX/CSO";
	lblFileDecompSrc->setText("DAX  file you want to decompress");
	lblFileDecompDst->setText("CSO file when the decompres and recompress  is OK");
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
                    "CSO file to decompress (*.cso)",
                    this,
                    "open file dialog",
                    "Choose the file you want to decompress" );
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX  file to decompress (*.dax)",
                    this,
                    "open file dialog",
                    "Choose the file you want to decompress" );
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="CSO/DAX")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX  file to decompress (*.cso)",
                    this,
                    "open file dialog",
                    "Choose the file you want to decompress" );
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".dax";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="DAX/CSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "DAX  file to decompress (*.dax)",
                    this,
                    "open file dialog",
                    "Choose the file you want to decompress" );
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".cso";
             leDstDecomp->setText(fichierDest);
    }
    
}


void formMain::parcourDstDecompress()
{
     if(sdecompressMethod=="CSO/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "ISO File (*.iso)",
                    this,
                    "save file dialog",
                    "Choose the file where you want to save the ISO File" );
	leDstDecomp->setText(nomDest);
	 
     }
    else if(sdecompressMethod=="DAX/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "ISO File (*.iso)",
                    this,
                    "save file dialog",
                    "Choose the file where you want to save the ISO File" );
	leDstDecomp->setText(nomDest);
	   
     }
    else if(sdecompressMethod=="CSO/DAX")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "DAX File (*.dax)",
                    this,
                    "save file dialog",
                    "Choose the file where you want to save the DAX File" );
	leDstDecomp->setText(nomDest);
	    
    }
    else if(sdecompressMethod=="DAX/CSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "CSO File (*.cso)",
                    this,
                    "save file dialog",
                    "Choose the file where you want to save the CSO File" );
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
                  int reponse=QMessageBox::question ( this,"Decompression ?","Are you sure you want to convert your CSO to ISO?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, "CSO Decompres is over ","The CSO decompression is over and OK",QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Decompres CSO canceled","You have cancel the CSO decompress",QMessageBox::Ok,0,0);
                  }
    } 
				      
	  
     
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc=leSrcDecomp->text();
                 QString nomDest=leDstDecomp->text();
                
	    QString chaine = "daxcr -d"" \""+nomSrc+"\" \""+nomDest+"\"";
                  int reponse=QMessageBox::question ( this,"Decompression ?","Are you sure you want to convert your DAX to ISO?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, "DAX Decompres is over ","The DAX decompression is over and OK",QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Decompres DAX canceled","You have cancel the DAX decompress",QMessageBox::Ok,0,0);
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
                
                  int reponse=QMessageBox::question ( this,"Decompression ?","Are you sure you want to convert your CSO to DAX ?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, "CSO Decompres is over ","The CSO decompression is over and OK<br> Now the the DAX compression will begin",QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, "CSO-> DAX Decompres is over ","The CSO to DAX decompression is over",QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Decompres CSO canceled","You have cancel the DAX decompress",QMessageBox::Ok,0,0);
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
                 
                
                  int reponse=QMessageBox::question ( this,"Decompression ?","Are you sure you want to convert your DAX to CSO ?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, "DAX Decompres is over ","The DAX decompression is over and OK<br> Now the the CSO compression will begin",QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, "DAX->CSO Decompres is over ","The DAX to CSO decompression is over",QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Decompres DAX canceled","You have cancel the DAX decompress",QMessageBox::Ok,0,0);
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
	int reponse= QMessageBox::question ( this, "Path where copy the ISO",fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	if(reponse==QMessageBox::Yes)
	{
	  bool decomp=copieDeFichier (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this, "File copy is OK","The file copy is sucessfull",QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this, "Problem","Erro during copy from source to destination<br>Be sur you have enough disk space on your memory stick  and the PSP is plug on the computer",QMessageBox::Ok,0,0);
	       }
	    
	}
	else
	{
	      QMessageBox::warning ( this, "Problem","Erro during copy from source to destination<br>Be sur you have enough disk space on your memory stick  and the PSP is plug on the computer",QMessageBox::Ok,0,0); 
	}
    }
    else if(nbDeSeparateur==0)
    {
	nbDeSeparateur= fichierDest.contains("\\");
	  fichierCopie=bDriveLetter->currentText();
	    fichierCopie=fichierCopie.replace(2,1,"\\");
	    fichierCopie+="ISO\\";
	    fichierCopie+= fichierDest.section("\\",nbDeSeparateur,nbDeSeparateur);
	    int reponse= QMessageBox::question ( this, "Path where copy the ISO",fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	    if(reponse==QMessageBox::Yes)
	{
		bool decomp=copieDeFichier  (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this," File copy is OK","The file copy is sucessfull",QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this, "Problem","Erro during copy from source to destination<br>Be sur you have enough disk space on your memory stick  and the PSP is plug on the computer",QMessageBox::Ok,0,0);
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
                    "Choose a path",
                    TRUE );
    leSaveFolder->setText(dirSelectionner);
    dirOpenSave=dirSelectionner;    
}


void formMain::savOption()
{
    // R�up�ation des diff�ents elements saisie par la personne
    indexDriveLetter=bDriveLetter_2->currentItem();
    bDriveLetter->setCurrentItem(indexDriveLetter);
    dirOpenSave=leSaveFolder->text();
    
    QFile fichierOption("option.txt");
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
}
   else
   {
       QMessageBox::warning ( this, "File creation problem","Option file creation fail, be sure you have the right rights for this folder",QMessageBox::Ok,0,0);   
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
                    "Choose a folder",
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
    QString aAfficheListe="File to compress :"+nbOfFileISOstr.setNum(compteurFichierCompresser)+"\n List of ISO file to compress :\n";
    for(int i=0;i<compteurFichierCompresser;i++)aAfficheListe+= listeDesFichiersACompresser[i]+"\n";
    QMessageBox::information(this,"ISO file to compress",aAfficheListe,QMessageBox::Ok,0,0);
    
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
		  int   reponse=QMessageBox::Yes;
		    if(reponse==QMessageBox::Yes)
		    {
			system(chaine);
			QFile fSrc(nomSrc);
			QFile fDest(nomDest);
			QString octet;
			QString octet2;
			int tailleSource=(int)(fSrc.size()/1000000);
			int tailleDest=(int)(fDest.size()/1000000);
			//QString CompressStatus="La compression CSO est termin�\n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier CSO :"+octet2.setNum(tailleDest)+" Mo";
			//QMessageBox::information ( this, "Compression CSO termin�................. ",CompressStatus,QMessageBox::Ok,0,0);
		    }
		    if(reponse==QMessageBox::No)
		    {
			//QMessageBox::information ( this, "Compression CSO annul�,"Vous avez annul�la compression CSO",QMessageBox::Ok,0,0);
		    }
		    
                     }
		
	        //Compression au format DAX avec un dossier
		if(cbCompressType->currentText()=="DAX")
		{
		    QString nomSrc= leSrc_2->text()+"/"+dirISO[i];
		    QString nomDest= leSrc_2->text()+"/"+ fichierDest;
		    QString tauxCompress=cbCompressLevel_2->currentText();
		    //V�ification des check box et creation des parametres ad�uat
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
			    //QString CompressStatus="La compression DAX est termin�\n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier DAX :"+octet2.setNum(tailleDest)+" Mo";
			    //QMessageBox::information ( this, "Compression DAX termin�................. ",CompressStatus,QMessageBox::Ok,0,0);
			}
			if(reponse==QMessageBox::No)
			{
			    QMessageBox::information ( this, "Compression DAX annuler","Vous avez annul�la compression DAX",QMessageBox::Ok,0,0);
			}
			
		    }
		    else
		    {
			QString chaine = "daxcr -l"+tauxCompress+" \""+nomSrc+"\" \""+nomDest+"\"";
			system(chaine);  
		    }
                       }
		
	       
	       
	 }
     }
       QMessageBox::information ( this, "File compression is over","All the iso file have been compressed",QMessageBox::Ok,0,0);
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
     }
     if(cbCompressType_2->currentText()=="CSO")
    {
	 gbOptionDax_2->setEnabled(false);
     }
}
