#include<vector>
#include<list>
#include<cstdlib>
using namespace std;

#ifndef UPDATE_H
#define UPDATE_H

struct position{
    int x, y;
};

void generate_new_vertex(vector<vector<int>>&, list<position>&);
void update_available_positions(vector<vector<int>>&, list<position>&, const int);

#endif 