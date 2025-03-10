#ifndef STEUERUNG_H
#define STEUERUNG_H

#include "hashtabelle.h"

class Steuerung
{
    private:
        Hashtabelle H_Name;
        Hashtabelle H_Kuerzel;

    public:
        Steuerung();
        virtual ~Steuerung();

        void add();
        void del();
        void import();
        void Search();
        void plot();
        void save();
        void load();
        void quit();

    protected:


};

#endif // STEUERUNG_H
