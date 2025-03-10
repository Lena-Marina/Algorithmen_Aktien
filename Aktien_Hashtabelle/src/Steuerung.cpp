#include "Steuerung.h"

#include <string>
#include <limits>
#include <iostream>

Steuerung::Steuerung()
{
    //ctor
}

Steuerung::~Steuerung()
{
    //dtor
}

void Steuerung::add()
{
    std::string NameAktie;
    std::string WKN;
    std::string kuerzel;

    std::cout << "Bitte geben Sie den Namen der Aktie an: " <<std::endl;
    std::getline(std::cin >> std::ws, NameAktie); //.ws entfernt vorherige Whitespaces //getline sorgt dafür dass auch Leerzeichen eingelesen werden

    std::cout << "Bitte geben Sie die WKN der Aktie an: " <<std::endl;
    std::getline(std::cin, WKN);

    std::cout << "Bitte geben Sie das Kuerzel der Aktie an: " <<std::endl;
    std::getline(std::cin, kuerzel);

    Aktie neueAktie = Aktie(NameAktie, WKN, kuerzel);

    H_Name.addAktieByName(neueAktie);

    //H_Kuerzel.addAktie(neueAktie);

}


void Steuerung::del(){
}
void Steuerung::import(){
}
void Steuerung::Search(){
}
void Steuerung::plot(){
}
void Steuerung::save(){
}
void Steuerung::load(){
}
void Steuerung::quit(){
}
