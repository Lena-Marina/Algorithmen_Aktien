#ifndef FUNKTIONENPLOT_H_INCLUDED
#define FUNKTIONENPLOT_H_INCLUDED

#include <string>
#include <limits>
#include <iostream>
#include <vector>
#include <memory> //f�r shared Pointer

#include "TagInformationen.h"
#include "Aktie.h"

void plotSchlusskurse(const std::vector<TagInformationen>& vektor);

#endif // FUNKTIONENPLOT_H_INCLUDED
