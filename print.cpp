//print.cpp

#include<iostream>
using namespace std;

void print(const vector<vector<int>>& v, const int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << setw(5) << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    double bestscore = 0.00;
    double currentscore=0.00;
    currentscore = calculation (v,size);
    if ( bestscore > currentscore ){
        bestscore = currentscore;
    }
    cout << "Your Current Score = " << currentscore << endl;
    cout << "Your Best Score = " << bestscore << endl;
}
