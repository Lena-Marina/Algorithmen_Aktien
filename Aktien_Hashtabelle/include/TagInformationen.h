#ifndef TAGINFORMATIONEN_H
#define TAGINFORMATIONEN_H

#include <string>

class TagInformationen {
public:
    //Constructoren
    TagInformationen();
    TagInformationen(std::string d, double c, long v, double o, double h, double l);

    //Destructoren
    virtual ~TagInformationen();

    //Datentypen von CHATGPT vorgeschlagen
    std::string datum;
    double closeLast;
    long volume;
    double open;
    double high;
    double low;



protected:

private:

};

#endif // TAGINFORMATIONEN_H
