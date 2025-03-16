#ifndef AKTIENMANAGER_H
#define AKTIENMANAGER_H

#include "hashtabelle.h"
#include "TagInformationen.h"
#include "FunktionenImport.h"

class AktienManager {
private:
    Hashtabelle H_Name = Hashtabelle();
    Hashtabelle H_Kuerzel = Hashtabelle();

//METHODEN
public:
    AktienManager();

    void add();
    void del();
    void import();
    void search();
    void plot();
    void save();
    void load();
    void quit();

};

#endif
