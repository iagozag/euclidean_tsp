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
    file >> word;

    g = Graph(n, x, y);

    file.close();

    return 1;
}

void TSP::build_graph(){
    g.build();
}

void TSP::bnb_rec(ll bound, ll cost, int level, int last, vector<bool>& vis,vector<pair<int, int>> &mins) {
    int n = g.size();
    if(level == n-1) best = min(best, cost+g.get(last, 0));
    else{
        for(int i = 0; i < n; i++) if(!vis[i]){
            ll new_bound = bound;
            if(!level) new_bound -= (mins[last].first+mins[i].first+1)/2;
            else new_bound -= (mins[last].second+mins[i].first+1)/2;
            new_bound += g.get(last, i);

            if(new_bound < best){
                vis[i] = 1;
                bnb_rec(new_bound, cost+g.get(last, i), level+1, i, vis,mins);
                vis[i] = 0;
            }
        }
    }
}
ll TSP::bnb(){
    auto begin = chrono::high_resolution_clock::now();

    best = LINF;

    vector<pair<int, int>> mins = g.get_mins(); int sum = 0;
    for(auto p: mins) sum += p.first+p.second;
    sum = (sum+1)/2;

    int n = g.size();


    vector<bool> vis(n); vis[0] = 1;
    bnb_rec(sum, 0, 0, 0, vis,mins);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    ofstream f("data/bnb.txt", ofstream::app);
    f << n << ' ' << best << ' ' << duration.count() << '\n';
    f.close();

    return best;
}