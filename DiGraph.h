#ifndef DIGRAPH_H
#define DIGRAPH_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class DiGraph{
    protected:
        vector<vector<int> > edge_matrix;

    public:
        int node_cnt;
        int edge_cnt;
        bool has_loops;

        Graph(string graph_file, int node_cnt);
        Graph(vector<vector<int> > edges, int node_cnt);

        /*Functions*/
        vector<vector<int> > find_paths(int src, int dest); //TODO
        bool has_path(int src, int dest);                   //TODO
        vector<vector<int> > get_edge_list();

        /*Edit the graph*/
        void add_nodes(int cnt);
        void add_edge(int src, int dest);
        void add_edge(vector<vector<int> > edges);
        void del_edge(int src, int dest);
        void del_edge(vector<vector<int> > edges);
};

#endif

