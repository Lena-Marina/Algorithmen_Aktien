#include "Aktie.h"

#include <stdexcept>
#include <iostream>

Aktie::Aktie()
    :nameAktie(""), wknAktie(""), kuerzelAktie(""), isDeleted(false), hatTagesinfo(false) {
}

Aktie::Aktie(std::string nameAktie, std::string wknAktie, std::string kuerzelAktie)
    :nameAktie(nameAktie), wknAktie(wknAktie), kuerzelAktie(kuerzelAktie), isDeleted(false) {
    //ctor
    if(nameAktie.empty()||wknAktie.empty()||kuerzelAktie.empty()) {
        throw std::runtime_error("Eine der Eingaben war leer! Aktie konnte nicht erstellt werden");
    }

}

Aktie::~Aktie() {

}


//getter
std::string Aktie::getNameAktie()const {
    return this->nameAktie;
}

std::string Aktie::getKuerzelAktie()const {
    return this->kuerzelAktie;
}

//setter
void Aktie::setSlotToDeleted() {
    isDeleted = true;
}

void Aktie::setBoolHatTagesInfo() {
    hatTagesinfo=true;
}


void Aktie::printAktie()const {
    std::cout<< "\nName: "<< nameAktie<<std::endl;
    std::cout <<"WKN: "<< wknAktie<<std::endl;
    std::cout <<"Kuerzel: "<< kuerzelAktie << "\n"<<std::endl;
    //std::cout <<"Bool isDeleted"<< isDeleted<<std::endl;

}

bool Aktie::wasSlotDeleted() const {
    return isDeleted;
}

void Aktie::printTagInfoAktie()const {

    if (hatTagesinfo) {
        std::cout<< "\nDatum: " << (*kurse)[0].datum<<std::endl;
        std::cout<< "Close Last: " << (*kurse)[0].closeLast<<std::endl;
        std::cout<< "Volume: " << (*kurse)[0].volume<<std::endl;
        std::cout<< "Open: " << (*kurse)[0].open<<std::endl;
        std::cout<< "High: " << (*kurse)[0].high<<std::endl;
        std::cout<< "Low: " << (*kurse)[0].low<<std::endl;
    } else {
        std::cout<< "Noch keine Tagesinfos vorhanden"<<std::endl;
    }


}





