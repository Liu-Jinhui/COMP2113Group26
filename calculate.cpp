//calculate.cpp

#include<iostream>
#include<cmath>
using namespace std;

//transfer the original number to GPA
double transfer(int n){
    if (n == 2)
        return 1
    if (n == 4)
        return 1.3
    if (n == 8)
        return 1.7
    if (n == 16)
        return 2
    if (n == 32)
        return 2.3
    if (n == 64)
        return 2.7
    if (n == 128)
        return 3
    if (n == 256)
        return 3.3
    if (n == 512)
        return 3.7
    if (n == 1024)
        return 4
    if (n == 2048)
        return 4.3
}

//calculate the score of current game table
double calculation(const vector<vector<int>>& v, const int size){
    double score = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            score += transfer(v[i][j]);
        }
    }
    return score;
}
