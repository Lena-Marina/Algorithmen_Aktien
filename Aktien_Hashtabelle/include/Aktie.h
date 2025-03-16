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



//METHODEN
public:
    Aktie();
    Aktie(std::string nameAktie, std::string wknAktie, std::string kuerzelAktie);

    ~Aktie();

    //getter
    std::string getNameAktie()const;
    std::string getKuerzelAktie()const;



    Aktie addAktie(); //??

    void printAktie()const;
    bool slotWasDeleted()const;

    //Vector auf aktuellsten Tag
    std::shared_ptr<std::vector<TagInformationen>> kurse;


};

#endif // AKTIE_H
