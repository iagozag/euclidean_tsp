#ifndef TATT_H
#define TATT_H

#include "TSP.h"
#include <climits>

struct Edge {
    ll w=LLONG_MAX;
    int to=-1;
    bool operator<(const Edge &o);
    bool operator<(const Edge o);
};

ll dist2d(long double x1, long double y1, long double x2, long double y2);
ll dfs(vector<vector<int>> &adj,int v, vector<int> &seq,int p,vector<long double> &x, vector<long double> &y);
void makeMST(vector<vector<int>> &adj, vector<long double> &x, vector<long double> &y);
void TwiceAroundTheTree(vector<long double> &x, vector<long double> &y);

void Christofides(vector<long double> &x, vector<long double> &y);

#endif