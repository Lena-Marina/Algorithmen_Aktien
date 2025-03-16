#include <iostream>
#include <string>
#include <limits>

#include "AktienManager.h"


//Forward Declaration
int frageUserNachInput();

int main() {

    AktienManager aktienManager = AktienManager();

    bool run = true;
    while(run) {

        int actionUserInput = frageUserNachInput();

        switch(actionUserInput) {
        case 0: //ADD
            std::cout << "Sie haben 0. ADD gewaehlt" <<std::endl;
            aktienManager.add();
            break;

        case 1: // DEL
            std::cout << "Sie haben 1. DEL gewaehlt" << std::endl;
            try {
                aktienManager.del();
            } catch (const std::exception& e) { // Exception gefangen
                std::cerr << "\nHAUPTMENUE" << std::endl;
                continue; // Zurück zum Hauptmenü
            }
            break;



            break;

        case 2: //IMPORT
            //Kurswerte für eine Aktie werden aus einer csv Datei importiert
            std::cout << "Sie haben 2. IMPORT gewaehlt" <<std::endl;
            aktienManager.import();
            //lässt sich momentan austesten, wenn du für den filePath CSV19.csv eingibst


            break;

        case 3: //SEARCH
            //Eine Aktie wird in der Hashtabelle gesucht und der aktuellste Kurseintrag (Date,Close,Volume,Open,High,Low) wird ausgegeben.
            //Man soll sowohl nach Name als auch nach Kürzel gesucht werden können.
            std::cout << "Sie haben 3. SEARCH gewaehlt" << std::endl <<std::endl;
            try {
                aktienManager.search();

            } catch (const std::exception& e) { // Exception gefangen
                std::cerr << "\nHAUPTMENUE" << std::endl;
                continue; // Zurück zum Hauptmenü
            }
            break;




        case 4: //PLOT
            //Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII Grafik ausgegeben, Format ist frei wählbar.
            std::cout << "Sie haben 4. PLOT gewaehlt" << std::endl << std::endl;
            try {
                aktienManager.plot();

            } catch (const std::exception& e) { // Exception gefangen
                std::cerr << "\nHAUPTMENUE" << std::endl;
                continue; // Zurück zum Hauptmenü
            }
            break;




        case 5: //SAVE
            //Programm speichert die Hashtabelle in eine Datei ab
            std::cout << "Dateiname: " <<std::endl;

            break;

        case 6: //LOAD
            //Programm lädt die Hashtabelle aus einer Datei
            std::cout << "Dateiname: " <<std::endl;

            break;

        case 7: //QUIT
            std::cout << "Programm wird beendet. " <<std::endl;

            run = false;
            break;
        default:
            std::cerr << "Falsche Eingabe!\nVersuchen Sie es erneut!\n" << std::endl;
            break;
        }
    }
    return 0;
}

int frageUserNachInput() {
    int choice;
    std::cout << "\nWaehlen Sie einen der folgenden Menue-Punkte durch Eingabe der zugehoerigen Zahl: "<< std::endl;
    std::cout << "0. ADD" <<std::endl;
    std::cout << "1. DEL" <<std::endl;
    std::cout << "2. IMPORT" <<std::endl;
    std::cout << "3. SEARCH" <<std::endl;
    std::cout << "4. PLOT" <<std::endl;
    std::cout << "5. SAVE" <<std::endl;
    std::cout << "6. LOAD" <<std::endl;
    std::cout << "7. QUIT\n" <<std::endl;

    if (!(std::cin >> choice)) {//es können nur Zahlen eingelesen werden
        std::cin.clear();  // Fehlerzustand zurücksetzen
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Puffer leeren
        return -1;  // Rückgabe eines ungültigen Werts
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Puffer leeren
    std::cout << std::endl;

    return choice;
}

//Allgemeine Informationen:
/*Für Hashfunktionen Länge in nicht-kryptografischen Kontexten (z. B. Hash-Tabellen)
 könnten 128- oder 160-Bit-Hashwerte ausreichen.*/

/*Für eine Hash-Tabelle mit maximal 1000 Einträgen empfehle ich eine Größe der Hash-Tabelle von etwa 1399 oder 1501.
Diese Größe stellt sicher, dass die Tabelle nicht zu voll wird (guter Ladefaktor),
und da es sich um eine Primzahl handelt, wird die Verteilung der Einträge optimiert.*/

/*Der Index in der Hashtabelle Berechnet sich aus: Hashcode%Tabellengröße      % = Modulo*/

/*Wenn du das Modulo verwendest, wird der Hashcode gleichmäßig über den Indexbereich verteilt.
Das hilft dabei, die Kollisionen zu minimieren und stellt sicher, dass die Einträge gut in der Hash-Tabelle verteilt werden.
Auch wenn zwei verschiedene Objekte denselben Hashcode haben, sorgt das Modulo dafür,
dass sie auf unterschiedliche Indizes abgebildet werden, je nachdem, wie der Hashcode sich verändert.*/
