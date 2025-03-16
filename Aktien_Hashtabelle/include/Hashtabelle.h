#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle {
private:

    Aktie hashtabelle[1399];
    size_t calcHashIndex(std::string hashByValue);


public:
    //Konstruktor
    Hashtabelle();

    //Getter
    Aktie& getAktieFromTable(int index);

    std::string getKuerzelFromName(std::string nameAktie);

    void addAktieHashtabelle(const Aktie& neuAktie, const std::string hashByValue);
    void searchAndPrintFromHashtabelle(const std::string searchByValue);
    void deleteAktieHashtabelle(const std::string deleteAktieChoice);

    size_t findPositionInTable(const std::string hashByValue, const bool searchMode);

    void setBoolHatTagesInfoTrue(size_t index);
};

#endif // HASHTABELLE_H
