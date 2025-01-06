#include <iostream>

#include "TSP.h"

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(int argc, char* argv[]){ _
	if (argc < 2) {
		cout << "How to use: ./main <file>" << endl;
		exit(0);
	}

    TSP tsp;
    string filename = "examples/"; filename += argv[1];
    if(!tsp.get_input(filename)) exit(0);

    tsp.build();

    exit(0);
}
