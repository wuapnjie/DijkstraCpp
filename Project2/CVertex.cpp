//
// Created by snowbean on 16-5-10.
//

#include <iostream>
#include "CVertex.h"

using namespace std;

CVertex::~CVertex() {

}

void CVertex::showVertex() {
    int pId = 0;
    if (p!= nullptr){
        pId = p->ID;
    }
    cout << "ID->" << this->ID << ":d->" << this->d << ",p->" << pId << ",r->" << this->r << endl;
}





