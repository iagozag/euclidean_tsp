#include "../include/TwiceAroundTheTree.h"

#include <algorithm>

bool Edge::operator<(const Edge &o) {
    return w<o.w;
}

TwiceAroundTheTree::TwiceAroundTheTree(int n) {
    father.resize(n);
    r.resize(n,0);
    for(int i=0;i<n;i++) father[i] = i; 
}

TwiceAroundTheTree::~TwiceAroundTheTree() {}

int TwiceAroundTheTree::find(int v) {
    if(v==father[v]) return v;
    return father[v] = find(father[v]);
}

void TwiceAroundTheTree::unionSet(int u, int v) {
    u = find(u);
    v = find(v);
    if(u!=v) {
        if(r[u]<r[v]) swap(u,v);
        father[v] = u;
        if(r[u]==r[v]) r[u]++;
    }
}

void TwiceAroundTheTree::addEdge(int u, int v, ll w) {
    e.emplace_back(u,v,w);
}

void TwiceAroundTheTree::build(vector<vector<ll>> &adjj) {
    for(unsigned long long i=0;i<adjj.size();i++) 
        for(unsigned long long j=i+1;j<adjj.size();j++) 
            addEdge(i, j, adjj[i][j]);
}

void TwiceAroundTheTree::solve() {
    sort(e.begin(),e.end());

    adj.resize(father.size());
    int un=adj.size();
    for(auto i:e) {
        int u = find(i.u), v = find(i.v);
        if(u!=v) {
            adj[i.u].push_back({i.v,i.w});
            adj[i.v].push_back({i.u,i.w});
            un--;
            unionSet(i.u, i.v);
            if(un==1) break;
        }
    }
    vector<int> seq;
    vector<bool> vis(adj.size(),false);
    dfs(0,vis,seq);
    cost+=adj[seq.back()][0].second;
    seq.push_back(0);

    cout << "cost: " << cost << "\nseq: " << seq.front() << ' ';
    for(int i=1;i<(int)seq.size();i++) cout << " -> " << seq[i];
    cout << '\n';
    
}

void TwiceAroundTheTree::dfs(int v, vector<bool> &vis, vector<int> &seq) {
    vis[v] = true;
    seq.push_back(v);

    for(auto u:adj[v]) {
        if(vis[u.first]) continue;
        cost+=u.second;
        dfs(u.first,vis,seq);
    }
}