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
    priority_queue<tuple<ll, int, ll, set<int>, int>> pq;

    vector<pair<int, int>> mins = g.get_mins(); int sum = 0;
    for(auto [a, b]: mins) sum += (a+b)/2;

    pq.push({-sum, 0, 0, set<int>({0}), 0});
    
    ll best = LINF; int n = g.size();
    while(!pq.empty()){
        auto [bound, level, cost, vis, last] = pq.top(); pq.pop(); bound *= -1;
        if(bound < best){
            if(level == n-1) best = min(best, cost+g.dist2d(last, 0));
            else{
                for(int k = 0; k < n; k++) if(!vis.count(k)){
                    if(!level) bound -= (mins[last].first+mins[k].first)/2;
                    else bound -= (mins[last].second+mins[k].first)/2;
                    bound += g.dist2d(last, k);

                    vis.insert(k);
                    pq.push({-bound, level+1, cost+g.dist2d(last, k), vis, k});
                }
            }
        }
    }

    return best;
}