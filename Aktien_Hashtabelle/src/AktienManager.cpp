#include "AktienManager.h"
#include "Aktie.h"

#include "FunktionenImport.h"
#include "FunktionenPLOT.h"

#include "TagInformationen.h"

#include <string>
#include <limits>
#include <iostream>
#include <memory> //für shared Pointer

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


    try {
        //neues Aktien-Objekt wird erstellt
        Aktie neueAktie = Aktie(nameAktie, wknAktie, kuerzelAktie);
        //Aktien werden in Tabellen hinzugefügt
        H_Name.addAktieHashtabelle(neueAktie, nameAktie);
        H_Kuerzel.addAktieHashtabelle(neueAktie, kuerzelAktie);

    } catch( const std::invalid_argument& e ) {
        H_Name.deleteAktieHashtabelle(nameAktie); //das Kürzel wurde bereits verwendet; also muss die bereits angelegte H_Name Aktie gelöscht werden
        std::cout << e.what();
    }



}



void AktienManager::del() {

    while (true) {
        std::string deleteAktieChoice;
        std::cout << "\nWelche Aktie wollen Sie entfernen? (Aktienname) \noder backToMenu" << std::endl;
        std::getline(std::cin, deleteAktieChoice);

        if (deleteAktieChoice == "backToMenu") {
            throw std::exception(); //damit die while-Schleife durchbrochen wird
        }
        std::string kuerzelAktie = H_Name.getKuerzelFromName(deleteAktieChoice);


        try {
            H_Name.deleteAktieHashtabelle(deleteAktieChoice);

            H_Kuerzel.deleteAktieHashtabelle(kuerzelAktie);
            break;
        } catch (const std::invalid_argument& e) { // Aktie nicht vorhanden
            std::cout << e.what() << std::endl;
            continue;
        }
    }


//Wenn eine Aktie gelöscht wird, muss ihr bool wasDeleted auf true gesetzt werden

    /*Wenn der Shared pointer in den Aktienobjekten beider Tabellen auf Null gesetzt wird,
    sollten die angehängten TagInformationen vom Heap automatisch freigegeben werden */
}

void AktienManager::import() {
    //Aktien zum dranhängen vorbereiten
    std::string aktieKuerzel;



    std::cout <<"Bitte geben Sie das Kürzerl der Aktie an, für die Sie Kurswerte einlesen wollen: ";
    std::getline(std::cin >> std::ws, aktieKuerzel);


    //FilePath einlesen
    std::string filePath = readPathToFile(); //Funktion aus FunktionenImport.h

    auto tagInfos = readCSV(filePath);//Funktion aus FunktionenImport.h
    //Diese Funktion extrahiert Informationen aus einer CSV und speichert sie in ein TagInformationsobjekt
    //Aktie zurückgeben und diese an die eine Liste dran pushen
    //zwei Subklassen von Hashtabellen, die eine hat den Vektor, die andere einen Pointer auf den vektor

    //Prüfen ob einlesen erfolgreich war
    if (!tagInfos) { //Wenn tagInfos ein Nullpointer ist
        std::cerr << "Fehler beim Einlesen der CSV-Datei!" << std::endl;
    }

    /*DEBUGGING*/
    //printAllTagInformation(tagInfos);

    //In den Hashtabellen (H_name und H_kuerzel) die richtigen Aktien suchen (über name und Kuerzel)
    //und ihren Vector durch den Shared Vektor (tagInfos) ersetzen

    try {
        size_t index_kuerzel = H_Kuerzel.findPositionInTable(aktieKuerzel, true); //true -> searchModus

        std::string aktieName = H_Kuerzel.getAktieFromTable(index_kuerzel).getNameAktie();
        size_t index_name = H_Name.findPositionInTable(aktieName, true); //true -> searchModus

        H_Kuerzel.getAktieFromTable(index_kuerzel).kurse = tagInfos;
        H_Name.getAktieFromTable(index_name).kurse = tagInfos;

        H_Kuerzel.setBoolHatTagesInfoTrue(index_kuerzel);
        H_Name.setBoolHatTagesInfoTrue(index_name);
        std::cout << "TagInformationen wurden erfolgreich eingelesen!\nUm sie einzusehen, wählen sie bitte SEARCH" << std::endl;
    } catch (const std::invalid_argument& e) { // Aktie nicht vorhanden
        std::cout << e.what() << std::endl;

    }





    /*DEBUGGING - lässt sich der Shared pointer in der Aktie ersetzen? -> JA! */
    //printAllTagInformation(H_Kuerzel.getAktieFromTable(index_kuerzel).kurse); //test für kürzeltabelle
    //printAllTagInformation(H_Name.getAktieFromTable(index_name).kurse); //test für nametabelle

}

void AktienManager::search() {
    std::string searchByChoice;
    std::string searchByValue;


    while (true) {
        std::cout <<"\nWählen Sie ein Suchkriterium (Name/Kuerzel)\nbackToMenu zum abbrechen"<<std::endl;
        std::cin >> searchByChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (searchByChoice == "backToMenu") {
            throw std::exception(); //damit die while-Schleife durchbrochen wird
        }

        if (searchByChoice == "Name") {
            std::cout <<"\nName der gesuchten Aktie: "<<std::endl;
            std::getline(std::cin, searchByValue);

            try {
                H_Name.searchAndPrintFromHashtabelle(searchByValue);
                break;
            } catch( const std::invalid_argument& e ) {

                std::cout << e.what();
            }
            continue;

        } else if (searchByChoice == "Kuerzel") {
            std::cout <<"\nKürzel der gesuchten Aktie: "<<std::endl;
            std::getline(std::cin, searchByValue);
            try {
                H_Kuerzel.searchAndPrintFromHashtabelle(searchByValue);
                break;
            } catch(const std::invalid_argument& e ) {

                std::cout << e.what();
                continue;
            }



        } else {
            std::cout<<"\nUngültiges Suchkriterium!\nVersuchen Sie es erneut!"<<std::endl;
        }


        //const Aktie& aktie2 = H_Kuerzel.getAktieFromTable(index);
        // aktie2.printAktie();
    }

}

void AktienManager::plot() {
    std::string aktieKuerzel;
    while (true) {
        //1.) Welche Aktie will die Userin?


        std::cout <<"\nBitte geben Sie das Kuerzel der Aktie an, deren Schlusswerte Sie sehen wollen: \nbackToMenu zum abbrechen\n";
        std::getline(std::cin >> std::ws, aktieKuerzel);

        if (aktieKuerzel == "backToMenu") {
            throw std::exception(); //damit die while-Schleife durchbrochen wird
        }

        try {
            //2.) (shared)Pointer (name = tagInfos) aus Aktie holen
            size_t index_kuerzel = H_Kuerzel.findPositionInTable(aktieKuerzel, true);
            std::shared_ptr<std::vector<TagInformationen>> tagInfos = H_Kuerzel.getAktieFromTable(index_kuerzel).kurse;

            //3.) tagInfos an Funktion übergeben
            plotSchlusskurse(*tagInfos);
            break;


        } catch (const std::invalid_argument& e ) {

            std::cout << e.what();
            continue;//Frage erneut
        }

    }



}


void AktienManager::save() {
}
void AktienManager::load() {
}
void AktienManager::quit() {
}
