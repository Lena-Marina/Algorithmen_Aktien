#include "Aktie.h"

#include <stdexcept>
#include <iostream>

Aktie::Aktie()
    :nameAktie(""), wknAktie(""), kuerzelAktie(""), isDeleted(false) {
}

Aktie::Aktie(std::string nameAktie, std::string wknAktie, std::string kuerzelAktie)
    :nameAktie(nameAktie), wknAktie(wknAktie), kuerzelAktie(kuerzelAktie), isDeleted(false) {
    //ctor
    if(nameAktie.empty()||wknAktie.empty()||kuerzelAktie.empty()) {
        throw std::runtime_error("Eine der Eingaben war leer! Aktie konnte nicht erstellt werden");
    }

}

//getter
/*std::string Aktie::getNameAktie(Aktie hashtabelle[index])const{
return this->nameAktie;
}
*/

void Aktie::printAktie()const {
    std::cout<< "Name: "<< nameAktie<<std::endl;
    std::cout <<"WKN: "<< wknAktie<<std::endl;
    std::cout <<"Kuerzel: "<< kuerzelAktie<<std::endl;
    std::cout<<"Bool was deleted = " << isDeleted<<std::endl;

}

bool Aktie::isSlotAvailable() const {
    if (nameAktie.empty() || isDeleted) {
        return true;
    } else {
        return false;
    }
}


