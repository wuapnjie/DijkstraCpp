//
// Created by snowbean on 16-5-17.
//

#include "CPath.h"
#include <iostream>


void CPath::showPaths() {
    if ((*paths.begin())->ID == source->ID) {
        list<CVertex *>::iterator l;
        cout << (*paths.begin())->ID;
        for (l = ++paths.begin(); l != paths.end(); l++) {
            cout << "-->" << (*l)->ID;
        }
        cout << endl;
        cout << "distance is " << distance << endl;
    } else {
        cout << "出发顶点为" << source->ID << ",目标顶点" << destination->ID << "不可到达" << endl;
    }
}


CPath::CPath(CVertex *s, CVertex *d) {
    this->source = s;
    this->destination = d;
    this->distance = d->d;
    this->rate = d->r;
    do {
        paths.push_back(d);
    }
    while ((d = d->p) != nullptr && d->ID != s->ID);
    if (d != nullptr) {
        paths.push_back(d);
    }
    paths.reverse();
}

void CPath::showPaths(int type) {
    if (type==TYPE_RATE){
        if ((*paths.begin())->ID == source->ID) {
            list<CVertex *>::iterator l;
            cout << (*paths.begin())->ID;
            for (l = ++paths.begin(); l != paths.end(); l++) {
                cout << "-->" << (*l)->ID;
            }
            cout << endl;
            cout << "rate is " << rate << endl;
        } else {
            cout << "出发顶点为" << source->ID << ",目标顶点" << destination->ID << "不可到达" << endl;
        }
    }
}







