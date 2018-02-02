#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Graph{
    private:
        vector<vector<int> > edge_matrix;

    public:
        int node_cnt;
        int edge_cnt;
        bool has_loops;

        Graph(string graph_file, int node_cnt);
        Graph(vector<vector<int> > edges, int node_cnt);

        /*Path finding*/
        vector<vector<int> > find_paths(int src, int dest);

        /*Information about the graph*/
        bool has_path(int src, int dest);
        vector<vector<int> > get_edge_list();

        /*Edit the graph*/
        void add_nodes(int cnt);
        void add_edge(int src, int dest);
        void add_edge(vector<vector<int> > edges);
        void del_edge(int src, int dest);
        void del_edge(vector<vector<int> > edges);
};

#endif
