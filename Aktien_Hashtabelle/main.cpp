#include <iostream>

#include "head.h"

enum Auswahl {ADD, DEL, IMPORT, SEARCH, PLOT, SAVE, LOAD, QUIT};

int main()
{
    int run = 1;
    while(run)
    {
        int choice;
        std::cout << "Waehlen Sie einen der folgenden Menue-Punkte durch Eingabe der zugehoerigen Zahl, oder des Wortes: "<< std::endl;
        std::cout << "0. ADD" <<std::endl;
        std::cout << "1. DEL" <<std::endl;
        std::cout << "2. IMPORT" <<std::endl;
        std::cout << "3. SEARCH" <<std::endl;
        std::cout << "4. PLOT" <<std::endl;
        std::cout << "5. SAVE" <<std::endl;
        std::cout << "6. LOAD" <<std::endl;
        std::cout << "7. QUIT" <<std::endl;

        std::cout << std::endl;
        std::cin >> choice;
        std::cout << std::endl; //Zeilenabstand

        switch(choice)
        {
        case 0: //ADD
            std::cout << "Sie haben 0. ADD gewaehlt" <<std::endl;
        //Eine Aktie mit Namen, WKN und Kürzel wird hinzugefügt.

            break;

        case 1: //DEL
            std::cout << "Sie haben 1. DEL gewaehlt" <<std::endl;
        //Aktie wird gelöscht.
            break;

        case 2: //IMPORT
            std::cout << "Sie haben 2. IMPORT gewaehlt" <<std::endl;
        //Kurswerte für eine Aktie werden aus einer csv Datei importiert
            break;

        case 3: //SEARCH
            std::cout << "Sie haben 3. SEARCH gewaehlt" <<std::endl;
        //Eine Aktie wird in der Hashtabelle gesucht und der aktuellste Kurseintrag (Date,Close,Volume,Open,High,Low) wird ausgegeben.
        //Man soll sowohl nach Name als auch nach Kürzel gesucht werden können.

            break;

        case 4: //PLOT
            std::cout << "Sie haben 4. PLOT gewaehlt" <<std::endl;
        //Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII Grafik ausgegeben, Format ist frei wählbar.
            break;

        case 5: //SAVE
            std::cout << "Dateiname: " <<std::endl;
        //Programm speichert die Hashtabelle in eine Datei ab
            break;

        case 6: //LOAD
            std::cout << "Dateiname: " <<std::endl;
        //Programm lädt die Hashtabelle aus einer Datei
            break;

        case 7: //QUIT
            std::cout << "Programm wird beendet. " <<std::endl;
        //Programm wird beendet
            run = 0;
            break;

        }

    }

    return 0;
}
