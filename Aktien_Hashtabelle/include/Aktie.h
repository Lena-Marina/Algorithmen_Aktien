#ifndef AKTIE_H
#define AKTIE_H

#include <string>

class Aktie
{
    public:
        Aktie(std::string NameAktie, std::string WKNu, std::string kuerzel);
        Aktie();
        virtual ~Aktie();
        Aktie addAktie();

        //getter
        std::string getName() const;

    protected:

    private:
        std::string nameAktie;
        std::string WKN; //Wertpapierkennnummer = alpahnumerischer code, daher string
        std::string kuerzelAktie;

        //Pointer auf aktuellsten Tag

};

#endif // AKTIE_H
