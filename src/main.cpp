#include <fstream>
#include <iostream>
#include "../include/approximationAlgorithms.h"

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

void get_input(string filename,vector<long double> &x, vector<long double> &y){
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << endl;
        return;
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


    file.close();
    // TwiceAroundTheTree(x,y);
}

int main(int argc, char* argv[]){
	if (argc < 3) {
		cout << "How to use: ./main <file> <algorithm>" << endl;
		exit(0);
	}

    int opt = atoi(argv[2]);
    vector<long double> x,y;
    string filename = "examples/"; filename += argv[1];
    get_input(filename,x,y);

    switch(opt) {
        case 1: {
            TSP tsp;
            if(!tsp.get_input(filename)) exit(0);
            tsp.build_graph();
            cout << tsp.bnb() << endl;
            break;
        }
        case 2:{
            ofstream f("data/tatt.txt",ofstream::app);
            f << filename.substr(9) << ' ';
            f.close();
            TwiceAroundTheTree(x,y);
            break;
        }
        case 3: {
            ofstream f("data/christofides.txt",ofstream::app);
            f << filename.substr(9) << ' ';
            f.close();
            Christofides(x,y);
            break;
        }
    }

    exit(0);
}
