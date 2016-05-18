//
// Created by snowbean on 16-5-10.
//

#include <iostream>
#include "CGraph.h"
#include "CPath.h"


using namespace std;

CGraph::CGraph(char *inputFile) {

}

CGraph::CGraph(std::list<CEdge *> listEdge) {
    list<CEdge *>::iterator i, iend;
    iend = listEdge.end();
    for (i = listEdge.begin(); i != iend; ++i) {
        addEdge(*i);
    }
}

CGraph::CGraph(std::list<CEdge *> listEdge, int minCap) {
    list<CEdge *>::iterator i, iend;
    iend = listEdge.end();
    for (i = listEdge.begin(); i != iend; ++i) {
        if ((*i)->getCap() >= minCap)
            addEdge(*i);
    }
}

CGraph::CGraph(CGraph &graph) {
}

CGraph::~CGraph() {

}

int CGraph::getNumVertex() {
    return numVertex;
}

int CGraph::getNumEdge() {
    return numVertex;
}

void CGraph::update(int v) {
    std::list<CEdge *> lEdge = mapVID_listEdge[v];
    std::list<CEdge *>::iterator i, iend;
    iend = lEdge.end();
    for (i = lEdge.begin(); i != iend; ++i) {
        int w = (*i)->getWeight();
        CVertex *h = mapVID_Vertex[(*i)->getTail()];
        CVertex *t = mapVID_Vertex[v];
        if (t->d + w < h->d) {
            h->d = t->d + w;
            h->p = mapVID_Vertex[v];
        }
    }
}

void CGraph::update(int v, int type) {
    std::list<CEdge *> lEdge = mapVID_listEdge[v];
    std::list<CEdge *>::iterator i, iend;
    iend = lEdge.end();
    for (i = lEdge.begin(); i != iend; ++i) {
        double r = (*i)->getRate();
        CVertex *h = mapVID_Vertex[(*i)->getTail()];
        CVertex *t = mapVID_Vertex[v];
        if (t->r * r > h->r) {
            h->r = t->r * r;
            h->p = mapVID_Vertex[v];
        }
    }
}


void CGraph::dijkstraAlg(int s) {
    map<int, CVertex *>::iterator i, iend;
    iend = mapVID_Vertex.end();
    for (i = mapVID_Vertex.begin(); i != iend; i++) {
        if (i->second->ID == s) {
            i->second->d = 0;
        }
        listTempMark.push_back(i->second);
    }
    update(s);
    while (!listTempMark.empty()) {
        listTempMark.sort(pVertexCompare);
        int j = (*listTempMark.begin())->ID;
        listTempMark.pop_front();
        update(j);
    }
}


void CGraph::dijkstraAlg(int s, int d) {
    map<int, CVertex *>::iterator i, iend;
    iend = mapVID_Vertex.end();
    for (i = mapVID_Vertex.begin(); i != iend; i++) {
        if (i->second->ID == s) {
            i->second->d = 0;
        }
        listTempMark.push_back(i->second);
    }
    update(s);
    while (!listTempMark.empty()) {
        listTempMark.sort(pVertexCompare);
        int j = (*listTempMark.begin())->ID;

        if (j == d) {
            return;
        }
        listTempMark.pop_front();
        update(j);
    }
}


void CGraph::updateBucket(int s) {
    std::list<CEdge *> lEdge = mapVID_listEdge[s];
    std::list<CEdge *>::iterator i, iend;
    iend = lEdge.end();

    for (i = lEdge.begin(); i != iend; ++i) {
        int w = (*i)->getWeight();
        CVertex *t = mapVID_Vertex[(*i)->getTail()];
        CVertex *h = mapVID_Vertex[s];
        if (h->d + w < t->d) {
            t->d = h->d + w;
            t->p = mapVID_Vertex[s];

            if (t->bucket != INFINITY) {
                mapBuckets[t->bucket].erase(t->ID);
                if (mapBuckets[t->bucket].empty()) {
                    mapBuckets.erase(t->bucket);
                }
            }

            t->bucket = t->d;
            mapBuckets[t->d][t->ID] = t;
        }
    }
}

void CGraph::dialAlg(int s, int d) {

    map<int, CVertex *>::iterator i, iend;
    iend = mapVID_Vertex.end();
    for (i = mapVID_Vertex.begin(); i != iend; i++) {
        if (i->second->ID == s) {
            i->second->d = 0;
            i->second->bucket = 0;
            map<int, CVertex *> bucket;
            bucket[i->second->ID] = i->second;
            mapBuckets[0] = bucket;
        }
    }

    updateBucket(s);

    while (!mapBuckets.empty()) {
        map<int, std::map<int, CVertex *>>::iterator f = mapBuckets.begin();
        int minDistance = (*f).first;

        map<int, CVertex *>::iterator ff = (*f).second.begin();
        int j = (*ff).first;

        if (j == d) return;

        (*f).second.erase(j);
        if ((*f).second.empty()) {
            mapBuckets.erase(minDistance);
        }

        updateBucket(j);

    }

}

void CGraph::dijkstraAlg(int s, int d, int type) {
    map<int, CVertex *>::iterator i, iend;
    iend = mapVID_Vertex.end();
    for (i = mapVID_Vertex.begin(); i != iend; i++) {
        if (i->second->ID == s) {
            i->second->r = 1;
        }
        listTempMark.push_back(i->second);
    }
    update(s, type);
    while (!listTempMark.empty()) {
        listTempMark.sort(pVertexCompareRate);
        int j = (*listTempMark.begin())->ID;

        if (j == d) {
            return;
        }
        listTempMark.pop_front();
        update(j, type);
    }
}

void CGraph::addEdge(CEdge *edge) {
    numEdge++;
    int head = edge->getHead();
    int tail = edge->getTail();
    this->incidentList.push_back(edge);
    if (this->mapVID_Vertex[head] == nullptr) {
        numVertex++;
        CVertex *vertex = new CVertex(head);
        mapVID_Vertex[head] = vertex;
        std::list<CEdge *> edgeList;
        edgeList.push_back(edge);
        mapVID_listEdge[head] = edgeList;
    } else {
        mapVID_listEdge[head].push_back(edge);
    }

    if (this->mapVID_Vertex[tail] == nullptr) {
        numVertex++;
        std::list<CEdge *> edgeList;
        mapVID_listEdge[tail] = edgeList;
        CVertex *vertex = new CVertex(tail);
        mapVID_Vertex[tail] = vertex;
    }
}

void CGraph::showGraph() {
    cout << "此图有" << getNumVertex() << "个顶点，" << "有" << getNumEdge() << "条边:" << endl;
    std::map<int, std::list<CEdge *>>::iterator i, iend;
    iend = this->mapVID_listEdge.end();
    for (i = this->mapVID_listEdge.begin(); i != iend; ++i) {
        std::list<CEdge *> edgeList = (*i).second;
        std::list<CEdge *>::iterator j, jend;
        jend = edgeList.end();
        cout << "顶点" << (*i).first << "的连通邻接顶点有：";
        for (j = edgeList.begin(); j != jend; ++j) {
            CEdge *edge = *j;
            cout << edge->getTail() << "\t";
        }
        cout << endl;
    }
}

void CGraph::showVertex() {
    std::map<int, CVertex *>::iterator i, iend;
    iend = mapVID_Vertex.end();
    for (i = mapVID_Vertex.begin(); i != iend; ++i) {
        (*i).second->showVertex();
    }
}

void CGraph::showShortestPath(int s, int d) {
    clock_t startTime = clock();
    dijkstraAlg(s, d);
    clock_t endTime = clock();
    cout << "\n标准Dijkstra算法查找使用" << endTime - startTime << "个clock_t的时间" << endl;
    CPath cPath(mapVID_Vertex[s], mapVID_Vertex[d]);
    cPath.showPaths();
}

void CGraph::showMaxRatePath(int s, int d) {
    clock_t startTime = clock();
    dijkstraAlg(s, d, TYPE_RATE);
    clock_t endTime = clock();
    cout << "\n查找使用" << endTime - startTime << "个clock_t" << endl;
    CPath cPath(mapVID_Vertex[s], mapVID_Vertex[d]);
    cPath.showPaths(TYPE_RATE);
}

void CGraph::showShortestPathByDial(int s, int d) {
    clock_t startTime = clock();
    dialAlg(s, d);
    clock_t endTime = clock();
    cout << "\nDial形式的Dijkstra算法查找使用" << endTime - startTime << "个clock_t" << endl;
    CPath cPath(mapVID_Vertex[s], mapVID_Vertex[d]);
    cPath.showPaths();
}











































