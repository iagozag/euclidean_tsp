#ifndef TATT_H
#define TATT_H

#include "TSP.h"
#include <climits>
#include <list>

struct Edge {
    ll w=LLONG_MAX;
    int to=-1;
    bool operator<(const Edge &o);
    bool operator<(const Edge o);
};

ll dist2d(long double x1, long double y1, long double x2, long double y2);
void makeMST(vector<multiset<int>> &adj,vector<long double> &x,vector<long double> &y);
void dfsTATT(vector<long double> &x,vector<long double> &y,vector<multiset<int>> &adj,
           vector<int> &seq,int v, int p);
void TwiceAroundTheTree(vector<long double> &x, vector<long double> &y);

void dfsHamCyc(vector<multiset<int>> &adj,int v,list<int> &path,int init,int ant=-1);
void Christofides(vector<long double> &x,vector<long double> &y);
void makeMatching(vector<long double> &x,vector<long double> &y,vector<vector<int>> &adj);
void makeHamiltonianCycle(vector<multiset<int>> &adj,list<int> &p);

#endif