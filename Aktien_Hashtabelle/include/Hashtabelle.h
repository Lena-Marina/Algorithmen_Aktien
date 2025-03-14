#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle {
private:

    Aktie hashtabelle[1399];

//METHODEN
private:
    size_t calcHashIndex(std::string hashByValue);

public:
    Hashtabelle();//Konstruktor

    //Getter
    const Aktie& getAktieFromTable(int index) const;



    void addAktieHashtabelle(const Aktie& neuAktie, const std::string hashByValue);

};

#endif // HASHTABELLE_H
