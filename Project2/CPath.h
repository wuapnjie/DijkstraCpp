//
// Created by snowbean on 16-5-17.
//

#ifndef PROJECTS2_CPATH_H
#define PROJECTS2_CPATH_H
#define TYPE_RATE 1

#include <list>
#include "CVertex.h"

using namespace std;
class CPath {
public:
    CVertex* source;
    CVertex* destination;
    double distance;
    double rate;
    std::list<CVertex* > paths;
    CPath(){};
    CPath(CVertex* s,CVertex* d);
    void showPaths();

    void showPaths(int type);
};


#endif //PROJECTS2_CPATH_H
