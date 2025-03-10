#ifndef HASHTABELLE_H
#define HASHTABELLE_H

# include "Aktie.h"

class Hashtabelle
{
    private:
        Aktie hashtabelle[1399];

    public:
        Hashtabelle();
        virtual ~Hashtabelle();

        void addAktieByName(const Aktie& neuAktie);


    protected:

    private:
        size_t hashfunktion_Name(std::string name);



};

#endif // HASHTABELLE_H
