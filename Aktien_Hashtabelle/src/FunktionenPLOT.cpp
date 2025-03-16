#include "FunktionenPLOT.h"


void plotSchlusskurse(const std::vector<TagInformationen>& vektor) {
    if (vektor.empty())  { //Wenn der Vektor und das Objekt auf das der Vektor zeigt leer sind
        std::cout << "Um die Schlusskurse auslesen zu können, müssen Sie diese zunächst mittels IMPORT einlesen.\n";
        return;
    }

    /* Um die Y-Achse später skalieren zu können müssen wir zunächst den Minimalen und Maximalen schlusswert
    der Aktie in den letzten 30 Tagen berechnen:   */
    double minWert = vektor[0].closeLast, maxWert = vektor[0].closeLast;
    for (const auto& tag : vektor) { /*Jedes Objekt in dem Vektor wird "tag" genannt und jedes tag nach größeren oder kleineren Werten durchsucht*/
        if (tag.closeLast < minWert) minWert = tag.closeLast;
        if (tag.closeLast > maxWert) maxWert = tag.closeLast;
    }


    const int hoehe = 10; //10 Zeilen
    const int breite = vektor.size(); //"Anzahl der TagInformationsobjekte im Vektor"-viele Spalten

    // Werte werden skaliert
    std::vector<int> skaliert; //ein neuer Vektor wird angelegt der die skalierten Schlusskurse als int enthalten wird
    for (const auto& tag : vektor) {
        int y = static_cast<int>((tag.closeLast - minWert) / (maxWert - minWert) * (hoehe - 1));
        skaliert.insert(skaliert.begin(), y); /*fügt sie immer vorne dran, da in unserem ursprünglichen Vektor ja immer der neueste ganz vorne dran hängt
        wir aber den "ältesten" Tag ganz rechts in der Grafik ausgeben wollen*/
    }

    // ASCII-Grafik zeichnen (von oben nach unten)
    for (int zeile = hoehe - 1; zeile >= 0; --zeile) {
        for (int spalte = 0; spalte < breite; ++spalte) {
            if (skaliert[spalte] == zeile)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }

    // X-Achse ausgeben
    std::cout << std::string(breite, '-') << "\n";
}
