#include "hashtabelle.h"
#include "aktie.h"

#include <iostream>

Hashtabelle::Hashtabelle()
{
    //ctor
}

Hashtabelle::~Hashtabelle()
{
    //dtor
}

void Hashtabelle::addAktieByName(const Aktie& neueAktie)
{
    std::string name = neueAktie.getName();

    size_t Index = hashfunktion_Name(name);

    this->hashtabelle[Index] = neueAktie;

}

size_t Hashtabelle::hashfunktion_Name(std::string name)
{
    size_t hashwert = 0;

    for(int i = 0; i<name.size(); i++){
        size_t multiplikator = 11;

        for(int j = i; j < name.size(); j++){
            multiplikator = multiplikator*10;
        }
        hashwert = hashwert * multiplikator + static_cast<int>(name[i]);
    }

    size_t index = hashwert%1399;

    std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}




