//
// Created by snowbean on 16-5-10.
//

#ifndef PROJECT_ONE_CEDGE_H
#define PROJECT_ONE_CEDGE_H
class CEdge {
private:
    int head;
    int tail;
    int weight;
    int capacity;
    double rate;
public:
    CEdge(int a, int b, int c, int d , double e);
    CEdge(int a, int b, int c, int e);
    CEdge(int a, int b,int c);
    CEdge(int a, int b);
    CEdge(CEdge &x);
    ~CEdge();
    int getHead();
    int getTail();
    int getWeight();
    int getCap();
    double getRate();
    bool operator<(CEdge &x);
};
#endif //PROJECT_ONE_CEDGE_H
