#include "hashtabelle.h"
#include "aktie.h"

#include <iostream>
#include <optional>
#include <stdexcept>

Hashtabelle::Hashtabelle() {
    //ctor
}

//Getter
Aktie& Hashtabelle::getAktieFromTable(int index) {
    return hashtabelle[index];
}

std::string Hashtabelle::getKuerzelFromName(std::string nameAktie) {
    size_t index = findPositionInTable(nameAktie, true);

    return hashtabelle[index].getKuerzelAktie();
}

size_t Hashtabelle::findPositionInTable(const std::string hashByValue, const bool searchMode) { //search mode FALSE=sucht freien Platz | TRUE = sucht Aktie

    /*quadratische Sondierung Formel =  h(k,i)=(h'(k)+c1 + c2 * i^2) mod m
    besser -> alternierende quadratische Sondierung; gleichmäßigere Abdeckung
    Formel: h(k,i)=(h′(k)+(−1)^i * i^2)mod m*/

    size_t index = calcHashIndex(hashByValue);
    size_t originalIndex = index; // Speichere den ursprünglichen Index
    size_t i = 1; // Startwert für die quadratische Sondierung

    bool nameIsEmpty = hashtabelle[index].getNameAktie().empty();
    bool wasDeleted = hashtabelle[index].wasSlotDeleted();

    while (true) {

        if (!searchMode && (nameIsEmpty || wasDeleted)) {
            // std::cout<<"\nAktie: \nHashedBy:" <<hashByValue<< "\nIndex: " << index<< "\nVersuche: " << i<<std::endl;
            return index; //Freier Platz für addfunktion gefunden

        } else if (searchMode && (nameIsEmpty  || wasDeleted) ) {
            throw std::invalid_argument ("Aktie noch nicht vorhanden");
        }

        if (hashtabelle[index].getNameAktie() == hashByValue || hashtabelle[index].getKuerzelAktie() == hashByValue) {
            if(searchMode) {
                return index; //Aktie für searchFunktion gefunden
            } else {
                throw std::invalid_argument( "Aktie wurde bereits angelegt" );
            }
        }

        //Kollisionsbehandlung
        if (i % 2 == 0) {
            // gerade: Addition
            index = (originalIndex + i * i) % 1399;
        } else {
            // ungerade: Subtraktion
            index = (originalIndex - i * i) % 1399;
        }
        i++;
    }
    return -1;

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
    //std::cout << "Der Index lautet: " << index <<std::endl;

    return index;
}


void Hashtabelle::addAktieHashtabelle(const Aktie& neueAktie, const std::string hashByValue) {

    size_t index = findPositionInTable(hashByValue, false); //searchMode == false (nicht so toll umgesetzt)
//Wert wird gehashed und Kollisionshandling wird durchgeführt
    hashtabelle[index] = neueAktie; //der bool isDeleted sollte hier mit false überschrieben werden



    //std::cout<<"\nAktie adden erfolgreich!\nHashedBy:" <<hashByValue<< "\nIndex: " << index<<std::endl;

}

void Hashtabelle::searchAndPrintFromHashtabelle(const std::string searchByValue) {
    int index = findPositionInTable(searchByValue, true); //searchMode == true (nicht so toll umgesetzt)
    hashtabelle[index].printAktie();//printed den Hauptteil
    hashtabelle[index].printTagInfoAktie();
}



void Hashtabelle::deleteAktieHashtabelle(const std::string deleteChoice) {

    int index = findPositionInTable(deleteChoice, true);
    hashtabelle[index].setSlotToDeleted();

    //Shared Pointer ermitteln
    std::shared_ptr<std::vector<TagInformationen>> tagInfos = hashtabelle[index].kurse;
    tagInfos.reset(); //auf 0 setzen -> löschen
}


void Hashtabelle::setBoolHatTagesInfoTrue(size_t index){
hashtabelle[index].setBoolHatTagesInfo();
}

/*
HASHFUNKTION ALT
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









