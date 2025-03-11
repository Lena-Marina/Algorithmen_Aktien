#include "Aktie.h"

#include <stdexcept>
#include <iostream>

Aktie::Aktie() {
}

Aktie::Aktie(std::string NameAktie, std::string WKNu, std::string kuerzel)
    :nameAktie(NameAktie), wknAktie(WKNu), kuerzelAktie(kuerzel) {
    //ctor
    if(nameAktie.empty()||wknAktie.empty()||kuerzelAktie.empty()) {
        throw std::runtime_error("Eine der Eingaben war leer! Aktie konnte nicht erstellt werden");
    }

}

//getter
std::string Aktie::getName() const {
    return this->nameAktie;
}


void Aktie::printAktie()const{
std::cout<< "Name: "<< nameAktie<<std::endl;
std::cout <<"WKN: "<< wknAktie<<std::endl;
std::cout <<"Kuerzel: "<< kuerzelAktie<<std::endl;

}
