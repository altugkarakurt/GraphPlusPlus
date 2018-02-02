#include "Graph.h"

Graph::Graph(vector<vector<int> > edges, int node_cnt){
    this -> node_cnt = node_cnt;
    edge_cnt = sizeof(edges);
    edge_matrix = vector<vector<int> >(node_cnt, vector<int>(node_cnt,0));
    add_edge(edges);
}

/*
Graph::Graph(string graph_file, int node_cnt){
    this -> node_cnt = node_cnt;
    edge_matrix = vector<vector<int> >(node_cnt, vector<int>(node_cnt,0));
    edge_cnt = 0;
    //TODO: go over line by line, do pattern matching
}
*/


void Graph::add_edge(int src, int dest){
    edge_matrix[src][dest] = 1;
    edge_cnt++;
}

void Graph::add_edge(vector<vector<int> > edges){
    for(unsigned int i=0; i<edges.size(); i++){
        add_edge(edges[i][0], edges[i][1]);
    }
}

void Graph::del_edge(int src, int dest){
    edge_matrix[src][dest] = 0;
    edge_cnt--;
}

void Graph::del_edge(vector<vector<int> > edges){
    for(unsigned int i=0; i<edges.size(); i++){
        del_edge(edges[i][0], edges[i][1]);
    }
}

vector<vector<int> > Graph::get_edge_list(){
    vector<vector<int> > edges;
    for(int i=0;i<node_cnt;i++){
        for(int j=i;j<node_cnt;j++){
            if(edge_matrix[i][j] == 1){
                edges.push_back(vector<int> {i,j});
            }
        }
    }
    return edges;
}
