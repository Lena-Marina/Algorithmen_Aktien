#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle {
private:

    Aktie hashtabelle[1399];

//METHODEN
private:
size_t findPositionInTable(const std::string hashByValue, const bool searchMode)const;
    size_t calcHashIndex(std::string hashByValue);



public:
    //Konstruktor
    Hashtabelle();

    //Getter
    const Aktie& getAktieFromTable(int index) const;

    void addAktieHashtabelle(const Aktie& neuAktie, const std::string hashByValue);
    void searchAktieHashtabelle(const std::string searchByValue);
};

#endif // HASHTABELLE_H
