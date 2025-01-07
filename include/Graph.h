#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Graph{
    private:
        int N;
        vector<vector<ll>> g;
        vector<long double> x;
        vector<long double> y;
    
    public:

        Graph();

        Graph(int _N, vector<long double> _x, vector<long double> _y);

        ll dist2d(int a, int b);

        void build();

        int size();

        vector<pair<int, int>> get_mins();
};


#endif