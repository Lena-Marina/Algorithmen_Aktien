#include "AktienManager.h"
#include "Aktie.h"

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





    try {
        //neues Aktien-Objekt wird erstellt
        Aktie neueAktie = Aktie(nameAktie, wknAktie, kuerzelAktie);
        //Aktien werden in Tabellen hinzugefügt
        H_Name.addAktieHashtabelle(neueAktie, nameAktie);
        H_Kuerzel.addAktieHashtabelle(neueAktie, kuerzelAktie);

    } catch( const std::invalid_argument& e ) {
//hier sollte eine deleteFunktion für das H_Name aufgerufen werden weil sonst wird der Name angelegt aber das kürzel nicht
        std::cout << e.what();
    }



}


void AktienManager::del() {

    while (true) {
        std::string deleteAktieChoice;
        std::cout <<"Name der zu löschenden Aktie"<<std::endl;
        std::getline(std::cin, deleteAktieChoice);

        try {
            H_Name.deleteAktieHashtabelle(deleteAktieChoice, true)//searchMode == true (ja, kann besser sein)
        } catch(const std::invalid_argument& e )

        }

    //Wenn eine Aktie gelöscht wird, muss ihr bool wasDeleted auf true gesetzt werden
}
void AktienManager::import() {
}
void AktienManager::search() {
    std::string searchByChoice;
    std::string searchByValue;


    while (true) {
        std::cout <<"Wählen Sie ein Suchkriterium (Name/Kuerzel)"<<std::endl;
        std::cin >> searchByChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (searchByChoice == "Name") {
            std::cout <<"Name der gesuchten Aktie: "<<std::endl;
            std::getline(std::cin, searchByValue);

            try {
                H_Name.searchAktieHashtabelle(searchByValue);
            } catch( const std::invalid_argument& e ) {

                std::cout << e.what();
            }


            break;

        } else if (searchByChoice == "Kuerzel") {
            std::cout <<"Kürzel der gesuchten Aktie: "<<std::endl;
            std::getline(std::cin, searchByValue);

            H_Kuerzel.searchAktieHashtabelle(searchByValue);
            break;

        } else {
            std::cout<<"Ungültige Eingabe!\nVersuchen Sie es erneut!"<<std::endl;
        }
    }

    /*


        while (true) {
            std::cout <<"Wählen Sie ein Suchkriterium (Name/Kuerzel)"<<std::endl;
            std::cin >> searchByChoice;
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (searchByChoice == "Name") {
                std::cout <<"Name der gesuchten Aktie: "<<std::endl;
                std::getline(std::cin, searchByValue);
                std::cout <<"Stop "<<std::endl;

                int index = H_Name.findPositionInTable(searchByValue);
                const Aktie& aktieFromTable = H_Name.getAktieFromTable(index);
                aktieFromTable.printAktie();



                break;

            } else if (searchByChoice == "Kuerzel") {
                std::cout <<"Kürzel der gesuchten Aktie: "<<std::endl;
                std::getline(std::cin, searchByValue);
                break;

            } else {
                std::cout<<"Ungültige Eingabe!\nVersuchen Sie es erneut!"<<std::endl;
            }
        }



        //
        //const Aktie& aktie2 = H_Kuerzel.getAktieFromTable(index);
        // aktie2.printAktie();
    */
}
void AktienManager::plot() {
}
void AktienManager::save() {
}
void AktienManager::load() {
}
void AktienManager::quit() {
}
