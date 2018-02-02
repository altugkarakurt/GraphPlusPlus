#include "Graph.h"

Graph::Graph(string graph_file, int node_cnt){
    this->node_cnt = node_cnt;
}

Graph::Graph(vector<vector<int> > edges, int node_cnt){
    this -> node_cnt = node_cnt;
    edge_cnt = sizeof(edges);
    edge_matrix = vector<vector<int> >(node_cnt, vector<int>(node_cnt,0));

    //TODO: check if elements of edges are tuples
    for(int i=0; i<edges.size(); i++){
        // Add each edge twice because this is an undirected graph
        edge_matrix[edges[i][0]][edges[i][1]] = 1;
        edge_matrix[edges[i][1]][edges[i][0]] = 1;
    }
}
