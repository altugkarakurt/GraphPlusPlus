#include "DiGraph.h"


DiGraph::DiGraph(vector<vector<int> > edges, int node_cnt){
    this -> node_cnt = node_cnt;
    edge_cnt = sizeof(edges);
    edge_matrix = vector<vector<int> >(node_cnt, vector<int>(node_cnt,0));
    add_edge(edges);
}

/*
DiGraph::DiGraph(string graph_file, int node_cnt){
    this -> node_cnt = node_cnt;
    edge_matrix = vector<vector<int> >(node_cnt, vector<int>(node_cnt,0));
    edge_cnt = 0;
    //TODO: go over line by line, do pattern matching
}
*/


void DiGraph::add_edge(int src, int dest){
    edge_matrix[src][dest] = 1;
    edge_cnt++;
    if(src == dest){
        has_loops = true;
    }
}

void DiGraph::add_edge(vector<vector<int> > edges){
    for(unsigned int i=0; i<edges.size(); i++){
        add_edge(edges[i][0], edges[i][1]);
    }
}

void DiGraph::del_edge(int src, int dest){
    edge_matrix[src][dest] = 0;
    edge_cnt--;
}

void DiGraph::del_edge(vector<vector<int> > edges){
    for(unsigned int i=0; i<edges.size(); i++){
        del_edge(edges[i][0], edges[i][1]);
    }
}

vector<vector<int> > DiGraph::get_edge_list(){
    vector<vector<int> > edges;
    for(int i=0;i<node_cnt;i++){
        for(int j=0;j<node_cnt;j++){
            if(edge_matrix[i][j] == 1){
                edges.push_back(vector<int> {i,j});
            }
        }
    }
    return edges;
}


void DiGraph::add_nodes(int cnt){
    for(int i=0;i<cnt;i++){
        edge_matrix.push_back(vector<int>(node_cnt,0));
    }
    node_cnt += cnt;
    for(int i=0;i<node_cnt;i++){
        for(int j=0;j<cnt;j++){
            edge_matrix[i].push_back(0);
        }
    }
}
