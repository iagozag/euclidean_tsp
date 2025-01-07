#ifndef TATT_H
#define TATT_H

#include "TSP.h"

struct Edge {
    int u;
    int v;
    ll w;
    bool operator<(const Edge &o);
};

class TwiceAroundTheTree{
    private:
        vector<int> father, r;
        vector<Edge> e;
        vector<vector<int>> adj;
        ll cost=0;

        int find(int v);
        void unionSet(int u, int v);
        void dfs(vector<vector<ll>> &adj,int v, vector<bool> &vis, vector<int> &seq);
    public:
        TwiceAroundTheTree(int n);
        ~TwiceAroundTheTree();
        void addEdge(int u, int v, ll w);
        void build(vector<vector<ll>> &adj);
        void solve(vector<vector<ll>> &adj);
};

#endif