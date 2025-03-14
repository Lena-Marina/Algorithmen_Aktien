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


    //neues Aktien-Objekt wird erstellt
    Aktie neueAktie = Aktie(nameAktie, wknAktie, kuerzelAktie);

    //Aktien werden in Tabellen hinzugefügt
    H_Name.addAktieHashtabelle(neueAktie, nameAktie);
    H_Kuerzel.addAktieHashtabelle(neueAktie, kuerzelAktie);


}


void AktienManager::del() {

    //Wenn eine Aktie gelöscht wird, muss ihr bool wasDeleted auf true gesetzt werden
}
void AktienManager::import() {
}
void AktienManager::Search() {

      //DEBUGGING
    const Aktie& aktieFromTable = H_Name.getAktieFromTable(74);
    const Aktie& aktie2 = H_Kuerzel.getAktieFromTable(540);
    aktieFromTable.printAktie();
    aktie2.printAktie();

}
void AktienManager::plot() {
}
void AktienManager::save() {
}
void AktienManager::load() {
}
void AktienManager::quit() {
}
