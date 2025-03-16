#ifndef AKTIE_H
#define AKTIE_H

#include <string>
#include <vector>
#include <memory> //für shared pointer

#include "TagInformationen.h"

class Aktie {

private:
    std::string nameAktie;
    std::string wknAktie; //Wertpapierkennnummer = alpahnumerischer code, daher string
    std::string kuerzelAktie;
    bool isDeleted;
    bool hatTagesinfo;



//METHODEN
public:
    //Vector auf aktuellsten Tag
    std::shared_ptr<std::vector<TagInformationen>> kurse;

    Aktie();
    Aktie(std::string nameAktie, std::string wknAktie, std::string kuerzelAktie);

    ~Aktie();

    //getter
    std::string getNameAktie()const;
    std::string getKuerzelAktie()const;

    void setSlotToDeleted();
    void setBoolHatTagesInfo();


    //Aktie addAktie(); //??
bool wasSlotDeleted()const;
    void printAktie()const;
    void printTagInfoAktie()const;






};

#endif // AKTIE_H
