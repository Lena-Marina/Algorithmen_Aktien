#include <iostream>
#include <string>
#include <limits>

#include "steuerung.h"

int main()
{

    Steuerung S1;

    int run = 1;
    while(run)
    {
        int choice;
        std::cout << "Waehlen Sie einen der folgenden Menue-Punkte durch Eingabe der zugehoerigen Zahl: "<< std::endl;
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Entfernt �brig gebliebenes '\n'
        std::cout << std::endl; //Zeilenabstand

        switch(choice)
        {
        case 0: //ADD
            std::cout << "Sie haben 0. ADD gewaehlt" <<std::endl;
            S1.add();

            break;

        case 1: //DEL
            std::cout << "Sie haben 1. DEL gewaehlt" <<std::endl;
        //Aktie wird gel�scht.
            break;

        case 2: //IMPORT
            std::cout << "Sie haben 2. IMPORT gewaehlt" <<std::endl;
        //Kurswerte f�r eine Aktie werden aus einer csv Datei importiert
            break;

        case 3: //SEARCH
            std::cout << "Sie haben 3. SEARCH gewaehlt" <<std::endl;
        //Eine Aktie wird in der Hashtabelle gesucht und der aktuellste Kurseintrag (Date,Close,Volume,Open,High,Low) wird ausgegeben.
        //Man soll sowohl nach Name als auch nach K�rzel gesucht werden k�nnen.

            break;

        case 4: //PLOT
            std::cout << "Sie haben 4. PLOT gewaehlt" <<std::endl;
        //Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII Grafik ausgegeben, Format ist frei w�hlbar.
            break;

        case 5: //SAVE
            std::cout << "Dateiname: " <<std::endl;
        //Programm speichert die Hashtabelle in eine Datei ab
            break;

        case 6: //LOAD
            std::cout << "Dateiname: " <<std::endl;
        //Programm l�dt die Hashtabelle aus einer Datei
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

//Allgemeine Informationen:
/*F�r Hashfunktionen L�nge in nicht-kryptografischen Kontexten (z. B. Hash-Tabellen)
 k�nnten 128- oder 160-Bit-Hashwerte ausreichen.*/

 /*F�r eine Hash-Tabelle mit maximal 1000 Eintr�gen empfehle ich eine Gr��e der Hash-Tabelle von etwa 1399 oder 1501.
 Diese Gr��e stellt sicher, dass die Tabelle nicht zu voll wird (guter Ladefaktor),
 und da es sich um eine Primzahl handelt, wird die Verteilung der Eintr�ge optimiert.*/

 /*Der Index in der Hashtabelle Berechnet sich aus: Hashcode%Tabellengr��e      % = Modulo*/

 /*Wenn du das Modulo verwendest, wird der Hashcode gleichm��ig �ber den Indexbereich verteilt.
 Das hilft dabei, die Kollisionen zu minimieren und stellt sicher, dass die Eintr�ge gut in der Hash-Tabelle verteilt werden.
 Auch wenn zwei verschiedene Objekte denselben Hashcode haben, sorgt das Modulo daf�r,
 dass sie auf unterschiedliche Indizes abgebildet werden, je nachdem, wie der Hashcode sich ver�ndert.*/
