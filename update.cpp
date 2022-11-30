#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cmath>
#include<list>
#include "print.h"
using namespace std;

struct position{
    int x, y;
};

const int initialized_values[3] = {0, 2, 4};

void generate_new_vertex(vector<vector<int>>& v, list<position>& pos){
    int num, available_num;
    available_num = pos.size();

    srand(time(NULL));
    num = rand()%available_num;
    for (int i = 0; i < num; i++){
        pos.push_back(pos.front());
        pos.pop_front();
    }
    position *target = new position;
    target = &pos.front();
    pos.pop_front();

    int value = -1;
    srand(time(NULL));
    value = initialized_values[(rand()%3)];
    v[target -> x][target -> y] = value;
    print(v, 4);
}

void update_available_positions(vector<vector<int>>& v, list<position>& pos, const int size){
    while(!pos.empty()){
        pos.pop_front();
    }
    position *p = new position;
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(!v[i][j]){
                p -> x = i;
                p -> y = j;
                pos.push_back((*p));
            }
        }
    }
}