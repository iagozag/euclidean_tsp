#include "Graph.h"

Graph::Graph() {}

Graph::Graph(int _N, vector<long double> _x, vector<long double> _y): N(_N), x(_x), y(_y) {}

ll Graph::dist2d(int a, int b){
    long double xd = x[a]-x[b];
    long double yd = y[a]-y[b];
    return (ll)(sqrt(xd*xd+yd*yd)+0.5);
}

ll Graph::get(int a, int b){
    return g[a][b];
}

void Graph::build(){
    g.resize(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++){
         g[i][i] = LINF;
        for(int j = i+1; j < N; j++) g[i][j] = g[j][i] = dist2d(i, j);
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
            if(g[i][j] < mi.first){
                if(mi.first < mi.second) mi.second = mi.first;
                mi.first = g[i][j];
            } else if(g[i][j] < mi.second) mi.second = g[i][j];
        }
        mins.push_back(mi);
    }

    return mins;
}