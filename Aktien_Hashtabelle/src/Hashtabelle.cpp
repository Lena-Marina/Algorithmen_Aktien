#include "hashtabelle.h"
#include "aktie.h"

#include <iostream>

Hashtabelle::Hashtabelle() {
    //ctor
}

//Getter
const Aktie& Hashtabelle::getAktieFromTable(int index) const {
        return hashtabelle[index];
}

void Hashtabelle::addAktieHashtabelle(const Aktie& neueAktie, const std::string hashByValue) {

    size_t Index = calcHashIndex(hashByValue);

    //Bevor die Aktie in die Hashtabelle geschrieben wird, müssen wir prüfen ob leer

    //Wenn leer-> einfach reinschreiben
    this->hashtabelle[Index] = neueAktie;

    //Wenn nicht leer --> neuenIndexSuchen();

}

size_t Hashtabelle::calcHashIndex(std::string hashByValue) {
    size_t hashwert = 0;

    for(std::size_t i = 0; i < hashByValue.size(); i++) { //die Methode size() gibt für std::string einen Wert vom Typ std::size_t zurück
        size_t multiplikator = 11;

        for(std::size_t j = i; j < hashByValue.size(); j++) {
            multiplikator = multiplikator*10;
        }
        hashwert = hashwert * multiplikator + static_cast<int>(hashByValue[i]);
    }

    size_t index = hashwert%1399;

    std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}




