#ifndef TSP_H
#define TSP_H

#include "Graph.h"

class TSP{
    private:
        vector<long double> x;
        vector<long double> y;

        Graph g;

    public:

        bool get_input(string filename);

        void build_graph();

        void get_mins();

        ll bnb();
};

#endif