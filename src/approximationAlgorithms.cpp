#include "../include/approximationAlgorithms.h"

#include <lemon/matching.h>
#include <lemon/full_graph.h>
#include <lemon/maps.h>

using namespace lemon;

bool operator<(const Edge x,const Edge o) {
    return x.w<o.w;
}

ll dist2d(long double x1, long double y1, long double x2, long double y2){
    long double xd = x1-x2;
    long double yd = y1-y2;
    return (ll)(sqrt(xd*xd+yd*yd)+0.5);
}

void makeMST(vector<vector<int>> &adj, vector<long double> &x, vector<long double> &y) {
    int n = x.size();
    vector<bool> sel(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    adj.assign(n,{});

    for(int i=0;i<n;i++) {
        int v = -1;
        for(int j=0;j<n;j++) 
            if((not sel[j]) and (v==-1 or min_e[j].w<min_e[v].w)) v = j;

        sel[v] = true;
        if(min_e[v].to!=-1) { 
            adj[v].push_back(min_e[v].to);
            adj[min_e[v].to].push_back(v);
        }

        for(int to=0;to<n;to++) {
            auto dist = dist2d(x[v],y[v],x[to],y[to]);
            if(dist<min_e[to].w) min_e[to].w = dist, min_e[to].to = v;
        }
    }
}

void TwiceAroundTheTree(vector<long double> &x, vector<long double> &y) {
    vector<vector<int>> adj;
    makeMST(adj,x, y);

    vector<int> seq;
    ll cost = dfs(adj,0,seq,-1,x,y);
    cost+=dist2d(x[0],y[0],x[seq.back()],y[seq.back()]);
    seq.push_back(0);
    cout << cost << '\n';
    cout << "seq:\n0";
    for(int i=1;i<(int)seq.size();i++) cout << " -> " << seq[i];
    cout << '\n';

}

ll dfs(vector<vector<int>> &adj,int v, vector<int> &seq,int p,vector<long double> &x, vector<long double> &y) {
    ll r=0;    
    if(seq.size()) r=dist2d(x[v],y[v],x[seq.back()],y[seq.back()]);//  adj[seq.back()][v];
    seq.push_back(v);
    for(auto u:adj[v]) {
        if(u==p) continue;
        r+=dfs(adj,u,seq,v, x,y);
    }
    return r;
}

void Christofides(vector<long double> &x, vector<long double> &y) {
    vector<vector<int>> adj;
    int n = x.size();
    makeMST(adj,x,y);

    vector<int> odd;
    for(int i=0;i<n;i++) 
        if(adj[i].size()&1ULL) odd.push_back(i);

    FullGraph g(odd.size());
    typedef FullGraph::EdgeMap<ll> WeightMap;
    WeightMap weight(g);

    ll w = LLONG_MIN;
    for(unsigned long long i=0;i<odd.size();i++) 
        for(auto j = i+1;j<odd.size();j++) 
            w = max(w,dist2d(x[odd[i]],y[odd[i]],x[odd[j]],y[odd[j]]));
    int i=0,j;

    for(FullGraph::NodeIt u(g); u != INVALID; ++u,i++){
        j=0;
        for(FullGraph::NodeIt v(g); v != INVALID; ++v,j++) {
            if(j>i and u!=v) {
                FullGraph::Edge e = g.edge(u, v);
                weight[e] = w-dist2d(x[odd[i]],y[odd[i]],x[odd[j]],y[odd[j]]);
            }
        }
    }

    MaxWeightedPerfectMatching<FullGraph, WeightMap> matching(g, weight);
    matching.run();

    ll totalCost = 0;
    for (FullGraph::NodeIt u(g); u != INVALID; ++u) {
        FullGraph::Node v = matching.mate(u);
        if (v != INVALID && g.id(u) < g.id(v)) {  // Print each edge once
            cout << "(" << g.id(u) << ", " << g.id(v) << ") - Cost: " << w-weight[g.edge(u, v)] << endl;
            totalCost += w-weight[g.edge(u, v)];
        }
    }

    cout << "Total Minimum Cost: " << totalCost << endl;

}