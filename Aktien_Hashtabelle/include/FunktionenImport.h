#ifndef FUNKTIONENIMPORT_H_INCLUDED
#define FUNKTIONENIMPORT_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "TagInformationen.h"


std::string readPathToFile();

std::shared_ptr<std::vector<TagInformationen>> readCSV(const std::string& filePath);
    /*Was tut die funktion? Sie �bernimmt den Pfad zu einer CSV Datei
    Dann erstellt sie aus maximal 30 Zeilen TagInformationspbjekte
    diese h�ngt sie an einen vektor, der am Heap angelegt wird
    und gibt dann einen shared pointer auf diesen Vektor zur�ck
    wenn sie die CSV datei nicht �ffnen kann, gibt sie einen NULL-Pointer zur�ck*/





void readTagInformationen(TagInformationen Tag);
void printAllTagInformation(const std::shared_ptr<std::vector<TagInformationen>>& tagInfos);

#endif // FUNKTIONENIMPORT_H_INCLUDED
