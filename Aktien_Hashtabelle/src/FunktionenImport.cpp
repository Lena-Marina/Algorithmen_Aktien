#include "FunktionenImport.h"

std::string readPathToFile()
{
    std::string filePath;
    std::cout << std::endl << "Sie wollen die Kurse einer Aktie einlesen." <<std::endl;
    std::cout << "Bitte geben Sie den relativen Pfad zu dem File ein, das Sie einlesen wollen: ";
    std::getline(std::cin >> std::ws, filePath);

    //Sicherheitsvorkehrung, dass es vom Format her valide ist

    return filePath;
}

std::shared_ptr<std::vector<TagInformationen>> readCSV(const std::string& filePath)
{
    std::ifstream file(filePath); //erstellt ein Eingabe-Dateistream-Objekt vom Typ std::ifstream und �ffnet die Datei die im filePath zu finden ist

    if (!file.is_open())   //Pr�ft ob sich die Datei hat �ffnen lassen
    {
        std::cerr << "Fehler beim �ffnen der Datei: " << filePath << std::endl;
        return nullptr;
    }

    // Shared Pointer f�r Vektor wird erstellt (ein Shared pointer gibt den Speicher automatisch frei, sobald kein Shared pointer mehr auf die Daten zeigt
    auto tagInfos = std::make_shared<std::vector<TagInformationen>>();

    //wir lesen die CSV Datei jetzt Zeile f�r Zeile aus, und speichern sie in die Variable line
    std::string line;

    //da in der Ersten Zeile nicht die Daten, sondern nur die �berschriften sind, holen wir uns diese jetzt schon, um sie sp�ter zu �berspringen
    std::getline(file, line);
    size_t count = 0; //size_t statt int (obwohl nur max 30) weil das wohl konvention ist

    //Jetzt wird aus jeder Zeile die Daten extrahiert und in Variablen gespeichert
    //Das aber nur f�r maximal 30 Zeilen (also die Einunddrei�igste Zeile der CSV Datei
    while (std::getline(file, line) && count < 30)
    {
        std::stringstream strstream(line); //ein String-Stream objekt wird aus der Zeile erstellt
        std::string datum, closeLastStr, volumeStr, openStr, highStr, lowStr; //String objekte um die extrahierten daten einzulesen

        std::getline(strstream, datum, ','); //Eine Zeichenfolge wird aus dem StringStream (strstream) bis zum n�chsten ',' eingelesen und in "datum" gespeichert
        std::getline(strstream, closeLastStr, ',');
        std::getline(strstream, volumeStr, ',');
        std::getline(strstream, openStr, ',');
        std::getline(strstream, highStr, ',');
        std::getline(strstream, lowStr, ',');

        //Die $ Zeichen werden aus den Strings entfernt, damit wir sie als doubles und longs abspeichern k�nnen
        if (!closeLastStr.empty() && closeLastStr[0] == '$')
        {
            closeLastStr.erase(0, 1);
        }
        if (!openStr.empty() && openStr[0] == '$')
        {
            openStr.erase(0, 1);
        }
        if (!highStr.empty() && highStr[0] == '$')
        {
            highStr.erase(0, 1);
        }
        if (!lowStr.empty() && lowStr[0] == '$')
        {
            lowStr.erase(0, 1);
        }

        //Ein neues TagInformationen Objekt wird erstellt, und gleich an den vektor (TagInfos) angeh�ngt.
        try {
            tagInfos->emplace_back(
                datum,
                std::stod(closeLastStr), //Die Funktion stod()wandelt den string in ein double um
                std::stol(volumeStr), //Die Funktion stol() wandelt den string in ein long um
                std::stod(openStr),
                std::stod(highStr),
                std::stod(lowStr)
            );
        } catch (const std::exception& e) { //Sollte das Umwandelt der Strings und somit das erstellen des TagInformationsobjektes nicht funktionieren, wird die fehlerhafte Zeile �berspr�unge und eine Fehlermeldung ausgegeben
            std::cerr << "Fehler beim Konvertieren der Daten: " << e.what() << std::endl;
            continue; // �berspringt fehlerhafte Zeilen
        }
        count++;
    }
    //der Shared Pointer auf den vector (am Heap) wird zur�ck gegeben
    return tagInfos;
}

//DEBUGGING FUNKTIONEN
void readTagInformationen(TagInformationen tag)
{
    std::cout << tag.datum
    << " | Close/Last: " << tag.closeLast
    << " | Volume: " << tag.volume
    << " | Open: " << tag.open
    << " | High: " << tag.high
    << " | Low: " << tag.low
    <<std::endl;
}

void printAllTagInformation(const std::shared_ptr<std::vector<TagInformationen>>& tagInfos)
{
    // �berpr�fen, ob tagInfos g�ltig (kein NULL-Pointer)ist
    if (tagInfos) {
        // Iteration �ber alle TagInformationen im Vektor
        for (const auto& tagInfo : *tagInfos) {
            std::cout << "Datum: " << tagInfo.datum << std::endl;
        }
    } else {
        std::cerr << "TagInformations-Vector ist leer oder ung�ltig!" << std::endl;
    }
}
