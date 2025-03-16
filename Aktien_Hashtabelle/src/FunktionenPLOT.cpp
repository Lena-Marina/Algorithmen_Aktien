#include "FunktionenPLOT.h"


void plotSchlusskurse(const std::vector<TagInformation>& vektor) {
    if (daten.empty()) {
        std::cout << "Um die Schlusskurse auslesen zu k�nnen, m�ssen Sie diese zun�chst mittels IMPORT einlesen.\n";
        return;
    }

    /* Um die Y-Achse sp�ter skalieren zu k�nnen m�ssen wir zun�chst den Minimalen und Maximalen schlusswert
    der Aktie in den letzten 30 Tagen berechnen:   */
    double minWert = vektor[0].closeLast, maxWert = vektor[0].closeLast;
    for (const auto& tag : vektor) {
        if (tag.schlusskurs < minWert) minWert = tag.schlusskurs;
        if (tag.schlusskurs > maxWert) maxWert = tag.schlusskurs;
    }

    // Anzahl der Zeilen f�r die ASCII-Grafik
    const int hoehe = 10;
    const int breite = daten.size();

    // Werte skalieren
    std::vector<int> skaliert;
    for (const auto& tag : daten) {
        int y = static_cast<int>((tag.schlusskurs - minWert) / (maxWert - minWert) * (hoehe - 1));
        skaliert.push_back(y);
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
