#ifndef AKTIE_H
#define AKTIE_H

#include <string>
#include <vector>

#include "TagInformationen.h"

class Aktie {

private:
    std::string nameAktie;
    std::string wknAktie; //Wertpapierkennnummer = alpahnumerischer code, daher string
    std::string kuerzelAktie;

    bool wasDelted;

    //Vector auf aktuellsten Tag
    std::vector<TagInformationen> kurse;

//METHODEN
public:
    Aktie();
    Aktie(std::string NameAktie, std::string WKNu, std::string kuerzel);

    //getter


    Aktie addAktie(); //??

    void printAktie()const;






};

#endif // AKTIE_H
