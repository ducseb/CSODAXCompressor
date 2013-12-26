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
	   lblStatut->setText("COPIE EN COURS");
	   uint dataLength = 4096;
	   char *data = new char[dataLength];
	   ulong completed = 0;
	   ulong compteur=0;
	   QString octet;
	   long tailleSource=sourceFile.size()/4096;
	   int ratio = 0;
	   QMessageBox::information(this,"Source",("Taille du fichier source à�copié�<br>:"+octet.setNum(tailleSource)));
	   lblTailleCopie->setText("Sur :<br>"+octet.setNum(tailleSource));
	   while(!sourceFile.atEnd())
	   {
	       completed += sourceFile.readBlock(data, dataLength);
	       destinationFile.writeBlock(data, dataLength);
	       compteur++;
	       
	       lblStatut->setText("Copie du block :"+octet.setNum(compteur));
	        a->eventLoop()->processEvents(QEventLoop::AllEvents); 
	   }
	     sourceFile.close();
	   destinationFile.close();
	  delete[] data;
	    lblStatut->setText("COPIE FINIE");
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
                    "Choisisser le fichier ISO �compresser" );
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
                    "Fichier CSO �sauvegarder" );
	leDest->setText(nomDest);
    }
    if(cbCompressType->currentText()=="DAX")
    {
		QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichiers Dax (*.dax)",
                    this,
                    "save file dialog",
                    "Choisisser ou vous voulez sauver le fichier DAX" );
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
    int reponse=QMessageBox::question ( this,"Compression ?","Etes vous sur de vouloir convertir le fichier ISO vers CSO?",QMessageBox::Yes,QMessageBox::No,0);
      if(reponse==QMessageBox::Yes)
      {
	  system(chaine);
	  QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus="La compression CSO est terminé�\n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier CSO :"+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this, "Compression CSO terminé�................. ",CompressStatus,QMessageBox::Ok,0,0);
      }
      if(reponse==QMessageBox::No)
      {
	  QMessageBox::information ( this, "Compression CSO annulé","Vous avez annulé la compression CSO",QMessageBox::Ok,0,0);
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
	      int reponse=QMessageBox::question ( this,"Compression ?","Etes vous sur de vouloir convertir le fichier ISO vers un fichier DAX ?<br> avec l'utilisation de zone non compressé�?",QMessageBox::Yes,QMessageBox::No,0);
	      if(reponse==QMessageBox::Yes)
	      {
		  system(chaine);
		 QFile fSrc(nomSrc);
	  QFile fDest(nomDest);
	  QString octet;
	  QString octet2;
                int tailleSource=(int)(fSrc.size()/1000000);
	   int tailleDest=(int)(fDest.size()/1000000);
	  QString CompressStatus="La compression DAX est terminé \n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier DAX :"+octet2.setNum(tailleDest)+" Mo";
	  QMessageBox::information ( this, "Compression DAX terminé ................. ",CompressStatus,QMessageBox::Ok,0,0);
	      }
	      if(reponse==QMessageBox::No)
	      {
		  QMessageBox::information ( this, "Compression DAX annulé","Vous avez annulé la compression DAX",QMessageBox::Ok,0,0);
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
	lblFileDecompSrc->setText("Fichier CSO que vous voulez déompresser");
	lblFileDecompDst->setText("Fichier ISO à obtenir après la décompression");
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
	
    }
    else if(currentItemDecompress==1)
    {
	sdecompressMethod="DAX/ISO";
	lblFileDecompSrc->setText("Fichier DAX que vous voulez décompresser");
	lblFileDecompDst->setText("Fichier ISO à obtenir �après la décompression");
	ldlDecompressLevel->setEnabled(false);
	cbDecompressLevel->setEnabled(false);
    }
    else if(currentItemDecompress==2)
    {
	sdecompressMethod="CSO/DAX";
	lblFileDecompSrc->setText("Ficher CSO que vous voulez décompresser");
	lblFileDecompDst->setText("Fichier DAX à obtenir �après la décompression");
	ldlDecompressLevel->setEnabled(true);
	cbDecompressLevel->setEnabled(true);
	
    }
    else if(currentItemDecompress==3)
    {
	sdecompressMethod="DAX/CSO";
	lblFileDecompSrc->setText("Fichier DAX que vous voulez décompresser");
	lblFileDecompDst->setText("Fichier CSO à obtenir �après la décompression");
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
                    "Fichier CSO (*.cso)",
                    this,
                    "open file dialog",
		    "Choisisser le fichier que vous voulez décompresser");
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "Fichier DAX (*.dax)",
                    this,
                    "open file dialog",
                    "Choisisser le fichier que vous voulez décompresser");
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".dax",0,0);
	fichierDest+=".iso";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="CSO/DAX")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "Fichier CSO (*.cso)",
                    this,
                    "open file dialog",
                    "Choisisser le fichier que vous voulez décompresser");
             leSrcDecomp->setText(nomSrc);
	QString fichierDest=nomSrc.section(".cso",0,0);
	fichierDest+=".dax";
             leDstDecomp->setText(fichierDest);
    }
    else if(sdecompressMethod=="DAX/CSO")
    {
	QString nomSrc = QFileDialog::getOpenFileName(
	     dirOpenSave,
                    "Fichier DAX (*.dax)",
                    this,
                    "open file dialog",
                    "Choisisser le fichier que vous voulez décompresser");
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
                    "Fichier ISO (*.iso)",
                    this,
                    "save file dialog",
                    "Choisisser ou sauvez le fichier ISO décompresser");
	leDstDecomp->setText(nomDest);
     }
    else if(sdecompressMethod=="DAX/ISO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(leDest->text(),"Fichier ISO (*.iso)",this,"save file dialog","Choisisser ou sauvez le fichier ISO décompresser");
	leDstDecomp->setText(nomDest);
     }
    else if(sdecompressMethod=="CSO/DAX")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier DAX (*.dax)",
                    this,
                    "save file dialog",
                    "Choisisser ou sauvez le fichier  DAX décompresser");
	leDstDecomp->setText(nomDest);
	    
    }
    else if(sdecompressMethod=="DAX/CSO")
    {
	 QString nomDest= QFileDialog::getSaveFileName(
	     leDest->text(),
                    "Fichier CSO (*.cso)",
                    this,
                    "save file dialog",
                    "Choisisser ou sauvez le fichier  CSO décompresser");
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
                  int reponse=QMessageBox::question ( this,"Décompression ?","Etes vous sur de vouloir convertir le fichier CSO en fichier ISO?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, "Décompression CSO terminé","La d�ompression du fichier CSO vers ISO est terminé",QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Décompression CSO Annulé","Vous avez annulez la décompression CSO ",QMessageBox::Ok,0,0);
                  }
    } 
				      
	  
     
    else if(sdecompressMethod=="DAX/ISO")
    {
	QString nomSrc=leSrcDecomp->text();
                 QString nomDest=leDstDecomp->text();
                
	    QString chaine = "daxcr -d"" \""+nomSrc+"\" \""+nomDest+"\"";
                  int reponse=QMessageBox::question ( this,"Décompression ?","Etes vous sur de vouloir convertir le fichier DAX en fichier ISO ?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine);
	            QMessageBox::information ( this, "Décompression DAX terminé","La décompression du fichier DAX vers ISO est terminé",QMessageBox::Ok,0,0);
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this,"Décompression DAX Annulé","Vous avez annulez la décompression DAX ",QMessageBox::Ok,0,0);
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
                
                  int reponse=QMessageBox::question ( this,"Décompression ?","Etes vous sur de vouloir convertir le fichier CSO en fichier DAX ?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this, "Décompression CSO terminé","La décompression CSO est terminé�<br>Maintenant la compression DAX va commencé",QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, "Décompression CSO->DAX  terminé","La décompression/recompression CSO->DAX est OK",QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this,"Décompression CSO->DAX Annulé","Vous avez annulez la décompression CSO->DAX",QMessageBox::Ok,0,0);
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
                 
                
                  int reponse=QMessageBox::question ( this,"Décompression ?","Etes vous sur de vouloir convertir le fichier DAX en fichier CSO ?",QMessageBox::Yes,QMessageBox::No,0);
                  if(reponse==QMessageBox::Yes)
                 {
	            system(chaine1);
	            QMessageBox::information ( this,"Décompression DAX terminé","La décompression DAX est terminé�<br>Maintenant la compression CSO va commencer",QMessageBox::Ok,0,0);
		    system(chaine2);
		    QMessageBox::information ( this, "Décompression DAX->CSO  terminer","La décompression/recompression DAX->CSO est OK",QMessageBox::Ok,0,0);
		 QFile supFichier( fichierDest);
		bool sup= supFichier.remove();

		   
                  }
                   if(reponse==QMessageBox::No)
                  {
               	  QMessageBox::information ( this, "Décompression  DAX->CSO Annulé","Vous avez annulez la décompression DAX->CSO",QMessageBox::Ok,0,0);
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
	int reponse= QMessageBox::question ( this, "Chemin ou copié l'ISO",fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	if(reponse==QMessageBox::Yes)
	{
	  bool decomp=copieDeFichier (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this, "Copie de fichier OK","La copie à été effectué�avec succes",QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this, "Problème de copie de fichier  de fichier","Une erreur est survenu pendant la copie de votre<br> fichier source vers le fichier de destination.<br> Vérifier que vous avez assez de place sur la mémory stick et que la PSP est branché",QMessageBox::Ok,0,0);
	       }
	    
	}
	else
	{
	   QMessageBox::warning ( this,"Problème de copie de fichier  de fichier","Une erreur est survenu pendant la copie de votre<br> fichier source vers le fichier de destination.<br> Vérifier que vous avez assez de place sur la mémory stick et que la PSP est branché",QMessageBox::Ok,0,0);
	}
    }
    else if(nbDeSeparateur==0)
    {
	nbDeSeparateur= fichierDest.contains("\\");
	  fichierCopie=bDriveLetter->currentText();
	    fichierCopie=fichierCopie.replace(2,1,"\\");
	    fichierCopie+="ISO\\";
	    fichierCopie+= fichierDest.section("\\",nbDeSeparateur,nbDeSeparateur);
	    int reponse= QMessageBox::question ( this, "Chemin ou copié�l'ISO",fichierCopie,QMessageBox::Yes,QMessageBox::No,0);
	    if(reponse==QMessageBox::Yes)
	{
		bool decomp=copieDeFichier  (fichierDest, fichierCopie);
		if(decomp==true)
		{
		     QMessageBox::warning ( this, "Copie de fichier OK","La copie à été effectué�avec succes",QMessageBox::Ok,0,0);   
		}
		else
		{
		   QMessageBox::warning ( this,"Probleme de copie de fichier  de fichier","Une erreur est survenu pendant la copie de votre<br> fichier source vers le fichier de destination.<br> V�ifier que vous avez assez de place sur la m�ory stick et que la PSP est branché",QMessageBox::Ok,0,0);
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
                    "Choisisser un repertoire",
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
       QMessageBox::warning ( this, "Probleme création fichier","Impossible de créé le fichier nécessaire pour la création de fichier option",QMessageBox::Ok,0,0);   
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
                    "Choisisser un repertoire",
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
    QString aAfficheListe="Nombre de fichier à�compresser :"+nbOfFileISOstr.setNum(compteurFichierCompresser)+"\n Voici la liste des fichiers à�compresser :\n";
    for(int i=0;i<compteurFichierCompresser;i++)aAfficheListe+= listeDesFichiersACompresser[i]+"\n";
    QMessageBox::information(this,"Les fichiers à compresser",aAfficheListe,QMessageBox::Ok,0,0);
    
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
			//QString CompressStatus="La compression CSO est termin�\n Taille du fichier ISO :"+octet.setNum(tailleSource)+" Mo\n Taille du fichier CSO :"+octet2.setNum(tailleDest)+" Mo";
			//QMessageBox::information ( this, "Compression CSO termin�................. ",CompressStatus,QMessageBox::Ok,0,0);
		    }
		    if(reponse==QMessageBox::No)
		    {
			QMessageBox::information ( this, "Compression CSO annulé" ,"Vous avez annulé�la compression CSO",QMessageBox::Ok,0,0);
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
			    QMessageBox::information ( this,"Compression DAX annulé","Vous avez annulé�la compression DAX",QMessageBox::Ok,0,0);
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
           QMessageBox::information ( this,"Les fichiers on été compressé","Fin de la compression des différents fichiers iso",QMessageBox::Ok,0,0);
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
