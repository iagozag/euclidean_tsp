#include "TSP.h"

bool TSP::get_input(string filename){
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << endl;
        return 0;
    }

    string word; int n;
    while(file >> word){
        if(word == "DIMENSION") file >> n;
        else if(word == "NODE_COORD_SECTION") break;
    }

    x.resize(n), y.resize(n);

    int j;
    for(int i = 0; i < n; i++) file >> j >> x[j-1] >> y[j-1];

    g = Graph(n, x, y);

    file.close();

    return 1;
}

void TSP::build_graph(){
    g.build();
}

ll TSP::bnb(){
    priority_queue<tuple<ll, int, ll, vector<bool>, int>> pq;

    vector<pair<int, int>> mins = g.get_mins(); int sum = 0;
    for(auto [a, b]: mins) sum += (a+b)/2;

    int n = g.size();
    pq.push({-sum, 0, 0, vector<bool>(n), 0});
    
    ll best = LINF;
    while(!pq.empty()){
        auto [bound, level, cost, vis, last] = pq.top(); pq.pop(); bound *= -1;
        cout << bound << ' ' << best << endl;
        if(bound < best){
            if(level == n-1) best = min(best, cost+g.dist2d(last, 0));
            else{
                for(int k = 0; k < n; k++) if(!vis[k]){
                    ll new_bound = bound;
                    if(!level) new_bound -= (mins[last].first+mins[k].first)/2;
                    else new_bound -= (mins[last].second+mins[k].first)/2;
                    new_bound += g.dist2d(last, k);

                    if(new_bound < best){
                        vis[k] = 1;
                        pq.push({-new_bound, level+1, cost+g.dist2d(last, k), vis, k});
                        vis[k] = 0;
                    }
                }
            }
        }
    }

    return best;
}