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
    /*Was tut die funktion? Sie übernimmt den Pfad zu einer CSV Datei
    Dann erstellt sie aus maximal 30 Zeilen TagInformationspbjekte
    diese hängt sie an einen vektor, der am Heap angelegt wird
    und gibt dann einen shared pointer auf diesen Vektor zurück
    wenn sie die CSV datei nicht öffnen kann, gibt sie einen NULL-Pointer zurück*/





void readTagInformationen(TagInformationen Tag);
void printAllTagInformation(const std::shared_ptr<std::vector<TagInformationen>>& tagInfos);

#endif // FUNKTIONENIMPORT_H_INCLUDED
