//status.cpp

#include<iostream>
#include<vector>
#include "status.h"
using namespace std;

bool check_alive(const vector<vector<int>>&v, const int size){
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(v[i][j]) cnt++;
        }
    }
    if(cnt < size * size){
        flag = true;
    }
    else{
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1; j++){
                if(v[i][j] && v[i][j] == v[i][j+1]) flag = true;
            }
        }
        for(int j = 0; j < size; j++){
            for(int i = 0; i < size - 1; i++){
                if(v[i][j] && v[i][j] == v[i + 1][j]) flag = true;
            }
        }
    }
    return flag;
}
