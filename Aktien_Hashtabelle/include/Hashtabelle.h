#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle {
private:

    Aktie hashtabelle[1399];


public:
    //Konstruktor
    Hashtabelle();

    //Getter
    Aktie& getAktieFromTable(int index);

    void addAktieHashtabelle(const Aktie& neuAktie, const std::string hashByValue);
    void searchAktieHashtabelle(const std::string searchByValue);

    size_t findPositionInTable(const std::string hashByValue, const bool searchMode);
    size_t calcHashIndex(std::string hashByValue);
};

#endif // HASHTABELLE_H
