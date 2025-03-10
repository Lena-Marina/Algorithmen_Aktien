#include "Aktie.h"

#include <stdexcept>
#include <iostream>

Aktie::Aktie()
{
}

Aktie::Aktie(std::string NameAktie, std::string WKNu, std::string kuerzel)
:nameAktie(NameAktie), WKN(WKNu), kuerzelAktie(kuerzel)
{
    //ctor
    if(nameAktie.empty()||WKN.empty()||kuerzelAktie.empty()){
        throw std::runtime_error("Eine der Eingaben war leer! Aktie konnte nicht erstellt werden");
    }

}

Aktie::~Aktie()
{
    //dtor
}

//getter
std::string Aktie::getName() const
{
    return this->nameAktie;
}
