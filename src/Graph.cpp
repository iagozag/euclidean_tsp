#include "Graph.h"

Graph::Graph() {}

Graph::Graph(int _N, vector<long double> _x, vector<long double> _y): N(_N), x(_x), y(_y) {}

ll Graph::dist2d(int a, int b){
    long double xd = x[a]-x[b];
    long double yd = y[a]-y[b];
    return (ll)(sqrt(xd*xd+yd*yd)+0.5);
}

void Graph::build(){
    g.resize(N);
    for(int i = 0; i < N; i++){
        g[i].resize(N); g[i][i] = LINF;
        for(int j = 0; j < N; j++) if(i != j) g[i][j] = dist2d(i, j);
    }
}

int Graph::size(){
    return N;
}

vector<pair<int, int>> Graph::get_mins(){
    vector<pair<int, int>> mins;
    for(int i = 0; i < N; i++){
        pair<int, int> mi = {LINF, LINF};
        for(int j = 0; j < N; j++) if(i != j){
            ll ve = dist2d(i, j);
            if(ve < mi.first){
                if(mi.first < mi.second) mi.second = mi.first;
                mi.first = ve;
            } else if(ve < mi.second) mi.second = ve;
        }
        mins.push_back(mi);
    }

    return mins;
}