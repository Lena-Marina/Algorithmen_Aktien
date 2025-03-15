#include "AktienManager.h"
#include "Aktie.h"

#include "FunktionenImport.h"
#include "TagInformationen.h"

#include <string>
#include <limits>
#include <iostream>

AktienManager::AktienManager() {
    //ctor
}



void AktienManager::add() {
    std::string nameAktie, wknAktie, kuerzelAktie;

    std::cout << "Bitte geben Sie den Namen der Aktie an: " <<std::endl;
    std::getline(std::cin >> std::ws, nameAktie); //.ws entfernt vorherige Whitespaces //getline sorgt dafür dass auch Leerzeichen eingelesen werden

    std::cout << "Bitte geben Sie die WKN der Aktie an: " <<std::endl;
    std::getline(std::cin, wknAktie);

    std::cout << "Bitte geben Sie das Kuerzel der Aktie an: " <<std::endl;
    std::getline(std::cin, kuerzelAktie);


    //neues Aktien-Objekt wird erstellt
    Aktie neueAktie = Aktie(nameAktie, wknAktie, kuerzelAktie);

    //Aktien werden in Tabellen hinzugefügt
    H_Name.addAktieHashtabelle(neueAktie, nameAktie);
    H_Kuerzel.addAktieHashtabelle(neueAktie, kuerzelAktie);


}


void AktienManager::del() {

    //Wenn eine Aktie gelöscht wird, muss ihr bool wasDeleted auf true gesetzt werden

    /*Wenn der Shared pointer in den Aktienobjekten beider Tabellen auf Null gesetzt wird,
    sollten die angehängten TagInformationen vom Heap automatisch freigegeben werden */
}


void AktienManager::import() {
    //Aktien zum dranhängen vorbereiten
    std::string aktieKuerzel;

    std::cout <<"Bitte geben Sie das Kürzerl der Aktie an, für die Sie Kurswerte einlesen wollen: ";
    std::getline(std::cin, aktieKuerzel);

    //Über das kürzel soll der name gesucht werden (User freundlichkeit)!
    std::string aktieName;






    //FilePath einlesen
    std::string filePath = readPathToFile(); //Funktion aus FunktionenImport.h

    auto tagInfos = readCSV(filePath);//Funktion aus FunktionenImport.h
    //Diese Funktion extrahiert Informationen aus einer CSV und speichert sie in ein TagInformationsobjekt
    //Aktie zurückgeben und diese an die eine Liste dran pushen
    //zwei Subklassen von Hashtabellen, die eine hat den Vektor, die andere einen Pointer auf den vektor

    //Prüfen ob einlesen erfolgreich war
    if (tagInfos) { //Wenn tagInfos kein Nullpointer ist
        std::cout << "TagInformationen wurden erfolgreich eingelesen!\n um sie einzusehen, wählen sie bitte SEARCH" << std::endl;
    } else {
        std::cerr << "Fehler beim Einlesen der CSV-Datei!" << std::endl;
    }
    /*DEBUGGING*/
    //printAllTagInformation(tagInfos);

    //In den Hashtabellen (H_name und H_kuerzel) die richtigen Aktien suchen (über name und Kuerzel)
    //und ihren Vector durch den Shared Vekotr (tagInfos) ersetzen


}


void AktienManager::Search() {

      //DEBUGGING
    const Aktie& aktieFromTable = H_Name.getAktieFromTable(74);
    const Aktie& aktie2 = H_Kuerzel.getAktieFromTable(540);
    aktieFromTable.printAktie();
    aktie2.printAktie();

}
void AktienManager::plot() {

    //1.) Welche Aktie will die Userin?

    //2.) (shared)Pointer auf Aktie holen

    //3.) größten und kleinsten Schlusswert der TagInformationsobjekte finden

    //4.) ???

}


void AktienManager::save() {
}
void AktienManager::load() {
}
void AktienManager::quit() {
}
