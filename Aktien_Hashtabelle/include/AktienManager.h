#ifndef STEUERUNG_H
#define STEUERUNG_H

#include "hashtabelle.h"

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
    void Search();
    void plot();
    void save();
    void load();
    void quit();

};

#endif // STEUERUNG_H
