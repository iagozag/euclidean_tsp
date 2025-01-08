#include "TSP.h"

TSP::TSP(): best(0) {}

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
    best = LINF;

    vector<pair<int, int>> mins = g.get_mins(); int sum = 0;
    for(auto [a, b]: mins) sum += (a+b)/2;

    int n = g.size();

    auto bnb_rec = [&](auto&& self, ll bound, ll cost, int level, int last, vector<bool>& vis) -> void {
        cout << bound << ' ' << best << ' ' << cost << ' ' << level << ' ' << last << endl;

        if(level == n-1) best = min(best, cost+g.dist2d(last, 0));
        else{
            for(int i = 0; i < n; i++) if(!vis[i]){
                ll new_bound = bound;
                if(!level) new_bound -= (mins[last].first+mins[i].first)/2;
                else new_bound -= (mins[last].second+mins[i].first)/2;
                new_bound += g.dist2d(last, i);

                if(new_bound < best){
                    vis[i] = 1;
                    self(self, new_bound, cost+g.dist2d(last, i), level+1, i, vis);
                    vis[i] = 0;
                }
            }
        }
    };

    vector<bool> vis(n);
    bnb_rec(bnb_rec, sum, 0, 0, 0, vis);

    return best;
}