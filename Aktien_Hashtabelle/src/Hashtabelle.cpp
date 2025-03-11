#include "hashtabelle.h"
#include "aktie.h"

#include <iostream>

Hashtabelle::Hashtabelle() {
    //ctor
}


void Hashtabelle::addAktieByName(const Aktie& neueAktie) {
    std::string name = neueAktie.getName();

    size_t Index = hashfunktion_Name(name);

    this->hashtabelle[Index] = neueAktie;

}

size_t Hashtabelle::hashfunktion_Name(std::string name) {
    size_t hashwert = 0;

    for(std::size_t i = 0; i < name.size(); i++) { //die Methode size() gibt für std::string einen Wert vom Typ std::size_t zurück
        size_t multiplikator = 11;

        for(std::size_t j = i; j < name.size(); j++) {
            multiplikator = multiplikator*10;
        }
        hashwert = hashwert * multiplikator + static_cast<int>(name[i]);
    }

    size_t index = hashwert%1399;

    std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}




