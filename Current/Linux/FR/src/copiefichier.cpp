#include <copiefichier.h>


void CopieFichier::run()
{
     QMessageBox::information(unFormulaireDepart,"Source",("Le fichier source est :<br>"+fichierSource));
       QMessageBox::information(unFormulaireDepart,"Destination",("Le fichier source est :<br>"+fichierDest));
       QFile sourceFile(fichierSource);
       QFile destinationFile(fichierDest);
       
       if(sourceFile.open(IO_ReadOnly) && destinationFile.open(IO_WriteOnly))
       {
	   uint dataLength = 4096;
	   char *data = new char[dataLength];
	   ulong completed = 0;
	   pbCopie->setProgress(completed);
	   while(!sourceFile.atEnd())
	   {
	       completed += sourceFile.readBlock(data, dataLength);
	       destinationFile.writeBlock(data, dataLength);
	     pbCopie->setProgress((int)(completed/sourceFile.size()));
	   }
	     sourceFile.close();
	   destinationFile.close();
	  delete[] data;
	  pbCopie->setProgress(100);
	   
       }
       else
       {
	  
       }
    
}
