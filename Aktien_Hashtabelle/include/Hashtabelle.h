#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle {
private:
    Aktie hashtabelle[1399];


//METHODEN
private:
    size_t hashfunktion_Name(std::string name);

public:
    Hashtabelle();//Konstruktor

    void addAktieByName(const Aktie& neuAktie);

};

#endif // HASHTABELLE_H
