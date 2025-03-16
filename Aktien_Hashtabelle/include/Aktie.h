#ifndef AKTIE_H
#define AKTIE_H

#include <string>

class Aktie {

private:
    std::string nameAktie;
    std::string wknAktie; //Wertpapierkennnummer = alpahnumerischer code, daher string
    std::string kuerzelAktie;

    bool isDeleted;

    //Vector auf aktuellsten Tag

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







};

#endif // AKTIE_H
