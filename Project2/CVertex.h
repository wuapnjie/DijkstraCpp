//
// Created by snowbean on 16-5-10.
//

#ifndef PROJECTS2_CVERTEX_H
#define PROJECTS2_CVERTEX_H

#define INFINITY 19960904

class CVertex {
public:
    int d;
    CVertex *p;
    int ID;
    double r;

    CVertex(int id) {
        this->d = INFINITY;
        this->p = nullptr;
        this->ID = id;
        this->r = r;
    }

    ~CVertex();

    void showVertex();

};

inline bool pVertexCompare(CVertex *x, CVertex *y) {
    return x->d < y->d;
}

inline bool pVertexCompareRate(CVertex *x, CVertex *y) {
    return x->r > y->r;
}


#endif //PROJECTS2_CVERTEX_H
