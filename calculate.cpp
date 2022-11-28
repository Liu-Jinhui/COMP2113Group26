//calculate.cpp

#include<iostream>
#include<cmath>
using namespace std;

//transfer the original number to GPA
double transfer(int n){
    if (n == 2)
        return 1;
    else if (n == 4)
        return 1.3;
    else if (n == 8)
        return 1.7;
    else if (n == 16)
        return 2;
    else if (n == 32)
        return 2.3;
    else if (n == 64)
        return 2.7;
    else if (n == 128)
        return 3;
    else if (n == 256)
        return 3.3;
    else if (n == 512)
        return 3.7;
    else if (n == 1024)
        return 4;
    else
        return 4.3;
}

//calculate the score of current game table
double calculation(const vector<vector<int>>& v, const int size){
    double score = 0;
    int cntava = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            score += transfer(v[i][j]);
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if (v[i][j] != 0)
            cntava += 1;
        }
    }
    if (cntava == 0)
        return 0;
    else{
        score = score / cntava;
        return score;}
}
