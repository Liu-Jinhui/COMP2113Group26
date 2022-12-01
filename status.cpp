//status.cpp

#include<iostream>
#include<vector>
#include "status.h"
using namespace std;

//scan through the table to check the availability of continue playing
int check_alive(const vector<vector<int>>&v, const int size){
    int flag = 0;
    int cnt = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(v[i][j]) cnt++;
        }
    }
    if(cnt < size * size){
        flag = 1;
    }
    else{
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1; j++){
                if(v[i][j] && v[i][j] == v[i][j+1]) flag = 34;
            }
        }
        for(int j = 0; j < size; j++){
            for(int i = 0; i < size - 1; i++){
                if(v[i][j] && v[i][j] == v[i + 1][j]) flag = 12;
            }
        }
    }
    return flag;
}
