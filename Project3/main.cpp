#include <iostream>
#include "CGraph.h"

using namespace std;

int main() {
    std::list<CEdge *> listEdge;
    listEdge.push_back(new CEdge(1, 2, 5, 4, 0.4));
    listEdge.push_back(new CEdge(1, 3, 6, 6, 0.6));
    listEdge.push_back(new CEdge(1, 5, 9, 7, 0.7));
    listEdge.push_back(new CEdge(2, 5, 3, 3, 0.9));
    listEdge.push_back(new CEdge(3, 2, 17, 8, 0.3));
    listEdge.push_back(new CEdge(3, 4, 16, 9, 0.8));
    listEdge.push_back(new CEdge(3, 6, 2, 4, 0.6));
    listEdge.push_back(new CEdge(4, 1, 10, 4, 0.4));
    listEdge.push_back(new CEdge(5, 6, 17, 6, 0.6));
    listEdge.push_back(new CEdge(5, 8, 22, 7, 0.7));
    listEdge.push_back(new CEdge(6, 4, 11, 3, 0.9));
    listEdge.push_back(new CEdge(6, 9, 4, 8, 0.3));
    listEdge.push_back(new CEdge(7, 4, 16, 9, 0.8));
    listEdge.push_back(new CEdge(7, 6, 13, 4, 0.6));
    listEdge.push_back(new CEdge(8, 6, 20, 4, 0.4));
    listEdge.push_back(new CEdge(8, 9, 8, 6, 0.6));
    listEdge.push_back(new CEdge(9, 10, 3, 7, 0.7));
    listEdge.push_back(new CEdge(10, 7, 1, 3, 0.9));


    CGraph *graph = new CGraph(listEdge);
    graph->showGraph();
//    graph->showShortestPath(1, 3);

    int s, d;
    cout << "请输入起始顶点和目标顶点：" << endl;
    cin >> s;
    cin >> d;


    cout << "输入序列号执行对应项目:\n"
    << "1. 单源单宿最短路算法\n"
    << "2. 最大通过率路径算法\n"
    << "3. 带宽约束最短路算法\n"
    << "4. Dijkstra算法与Dial实现最短路算法的对比\n"
    << endl;

    int type;
    cout << "选择:";
    cin >> type;

    if (type == 1) {
        graph->showShortestPath(s, d);
    } else if (type == 2) {
        graph->showMaxRatePath(s, d);
    } else if (type == 3) {
        cout << "请输入带宽需求:" << endl;
        int c;
        cin >> c;
        graph = new CGraph(listEdge, c);
        graph->showShortestPath(s, d);
    } else if (type == 4) {
        CGraph *graphDial = new CGraph(listEdge);
        graph->showShortestPath(s, d);
        graphDial->showShortestPathByDial(s, d);
    }

    return 0;
}