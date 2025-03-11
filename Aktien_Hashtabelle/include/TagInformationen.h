#ifndef TAGINFORMATIONEN_H
#define TAGINFORMATIONEN_H

#include <string>

class TagInformationen {
public:
    TagInformationen();
    virtual ~TagInformationen();

protected:

private:
    //Ich war nicht ganz sicher als was für Datentypen wir sie speichern werden. Ich glaube aber, alle außer Date werden eh einfach Intetures sein?
    //Date      03/07/2025

    //Close     $891.11

    //Volume    7737488
    int volume;

    //Open      $897.64

    //High      $904.8859

    //Low       $858.07

    //pointer auf naechsten Tag:
    TagInformationen* naechsterTag;
};

#endif // TAGINFORMATIONEN_H
