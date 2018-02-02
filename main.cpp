#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> e1 {0,1};
    vector<int> e2 {2,3};
    vector<int> e3 {1,3};
    vector<vector<int> > edges {e1,e2,e3};
    Graph g = Graph(edges, 4);
    cout << "Success! Created a graph from an edge list!";
    return 0;
}
