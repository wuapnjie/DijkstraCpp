//
// Created by snowbean on 16-5-10.
//

#ifndef PROJECTS2_CGRAPH_H
#define PROJECTS2_CGRAPH_H

#include <list>
#include <map>
#include "CEdge.h"
#include "CVertex.h"

using namespace std;

class CGraph {
private:
    int numVertex;
    int numEdge;
    list<CEdge *> incidentList;
    map<int, CVertex *> mapVID_Vertex;
    list<CVertex *> listTempMark;
    map<int, std::list<CEdge *>> mapVID_listEdge;

    void update(int VID);

    void addEdge(CEdge *edge);

    map<int, std::map<int, CVertex *>> mapBuckets;

public:
    CGraph(char *inputFile);

    CGraph(list<CEdge *> listEdge);

    CGraph(list<CEdge *> listEdge, int minCap);

    CGraph(CGraph &graph);

    ~CGraph();

    int getNumVertex();

    int getNumEdge();

    void dijkstraAlg(int VID);

    void dijkstraAlg(int s, int d);

    void showGraph();

    void showVertex();

    void showShortestPath(int s, int d);

    void showMaxRatePath(int s, int d);

    void dijkstraAlg(int s, int d, int type);

    void update(int s, int type);

    void dialAlg(int s, int d);

    void updateBucket(int s);

    void showShortestPathByDial(int s, int d);
};


#endif //PROJECTS2_CGRAPH_H
