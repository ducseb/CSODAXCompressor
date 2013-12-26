#ifndef COPIEFICHIER_H
#define COPIEFICHIER_H
#include <qthread.h>
#include <qfile.h>
#include <qmessagebox.h> 
#include <qdialog.h>
#include <qprogressbar.h>
#include <qwidget.h>
#include <qtabwidget.h> 

class CopieFichier : public QThread
{
    public:
     void run();
    QString fichierSource;
    QString fichierDest;
    // CopieFichier();
   //~CopieFichier();
     QDialog* unFormulaireDepart;
     QProgressBar* pbCopie;
};

#endif
