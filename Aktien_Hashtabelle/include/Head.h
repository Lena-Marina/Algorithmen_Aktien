#ifndef HEAD_H
#define HEAD_H

#include <string>

#include "TagInformationen.h"

//Head ist der Eintrag in unseren Hashtabellen

class Head
{
    public:
        Head();
        virtual ~Head();

    protected:

    private:
        std::string nameAktie;
        std:.string WKN; //Wertpapierkennnummer = alpahnumerischer code, daher string
        std::string kuerzelAktie;

        //Pointer auf aktuellsten Tag
        TagesInformation aktuellsterTag;

};

#endif // HEAD_H
