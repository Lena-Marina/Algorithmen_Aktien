#include "TagInformationen.h"

TagInformationen::TagInformationen()
{
    //ctor
}

TagInformationen::TagInformationen(std::string d, double c, long v, double o, double h, double l)
    : datum(d), closeLast(c), volume(v), open(o), high(h), low(l)
{

}

TagInformationen::~TagInformationen()
{
    //dtor
}
