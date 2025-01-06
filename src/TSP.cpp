#include "TSP.h"

bool TSP::get_input(string filename){
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << endl;
        return 0;
    }

    string word;
    while(file >> word){
        if(word == "DIMENSION") file >> N;
        else if(word == "NODE_COORD_SECTION") break;
    }

    x.resize(N), y.resize(N);

    int j;
    for(int i = 0; i < N; i++) file >> j >> x[j-1] >> y[j-1];

    file.close();

    return 1;
}

void TSP::build(){
    g.resize(N);
    for(int i = 0; i < N; i++){
        g[i].resize(N);
        for(int j = 0; j < N; j++) g[i][j] = dist2d(x[i], y[i], x[j], y[j]);
    }
}