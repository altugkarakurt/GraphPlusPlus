#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int> > edges {vector<int> {0,1}, vector<int> {2,3}, vector<int> {1,3}};
    Graph g = Graph(edges, 4);
    g.add_edge(1,2);
    g.del_edge(0,1);
    g.add_nodes(3);
}
