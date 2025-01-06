#ifndef TSP_H
#define TSP_H

#include <string>
#include <vector>
#include <fstream>

#include "Utils.h"

class TSP{
    private:
        int N;
        vector<long double> x;
        vector<long double> y;

        vector<vector<ll>> g;

    public:

        bool get_input(string filename);

        void build();
};

#endif