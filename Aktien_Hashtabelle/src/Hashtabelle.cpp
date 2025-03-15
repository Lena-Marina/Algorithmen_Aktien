#include "hashtabelle.h"
#include "aktie.h"

#include <iostream>
#include <optional>

Hashtabelle::Hashtabelle() {
    //ctor
}

//Getter
const Aktie& Hashtabelle::getAktieFromTable(int index) const {
    return hashtabelle[index];
}


void Hashtabelle::addAktieHashtabelle(const Aktie& neueAktie, const std::string hashByValue) {
    /*quadratische Sondierung Formel =  h(k,i)=(h'(k)+c1 + c2 * i^2) mod m
    besser -> alternierende quadratische Sondierung; gleichmäßigere Abdeckung
    Formel: h(k,i)=(h′(k)+(−1)^i * i^2)mod m
     */
    size_t index = calcHashIndex(hashByValue); //ruft hashingFunktion auf
    size_t originalIndex = index; // Speichere den ursprünglichen Index
    size_t i = 1; // Startwert für die quadratische Sondierung

    while (!hashtabelle[index].isSlotAvailable()) {
        if (i % 2 == 0) {
            // gerade: Addition
            index = (originalIndex + i * i) % 1399;
        } else {
            // ungerade: Subtraktion
            index = (originalIndex - i * i) % 1399;
        }
        i++;
    }


    hashtabelle[index] = neueAktie; //der bool isDeleted sollte hier mit false überschrieben werden
    std::cout<<"\nAktie adden erfolgreich!\nHashedBy:" <<hashByValue<< "\nIndex: " << index<<"\nVersuche: "<< i << "\n"<<std::endl;

}


size_t Hashtabelle::calcHashIndex(std::string hashByValue) {
    size_t hashwert = 0;

    //maximalen Multiplikator berechnen
    size_t max_multiplikator = 1;
    for (std::size_t i = 1; i < hashByValue.size(); i++) {
        max_multiplikator *= 11;
    }

    for (std::size_t i = 0; i < hashByValue.size(); i++) {
        hashwert = hashwert + static_cast<size_t>(hashByValue[i]) * max_multiplikator;

        max_multiplikator /= 11; // Reduziert den Multiplikator für das nächste Zeichen
    }

    size_t index = hashwert%1399;



    //  std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}




/*
size_t Hashtabelle::calcHashIndex(std::string hashByValue) {
    size_t hashwert = 1;

    for(std::size_t i = 0; i < hashByValue.size(); i++) { //die Methode size() gibt für std::string einen Wert vom Typ std::size_t zurück
        size_t multiplikator = 11;

        for(std::size_t j = i; j < hashByValue.size(); j++) {
            multiplikator *= 10;
        }
        hashwert = hashwert * multiplikator + static_cast<int>(hashByValue[i]);
    }

    size_t index = hashwert%1399;

    std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}
*/




