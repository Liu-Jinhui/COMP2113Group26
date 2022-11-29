//print.cpp

#include<iostream>
using namespace std;
#include<vector>
#include<iomanip>
#include "calculate.h"
#include "print.h"

void transfergrade(int n){
    if (n == 2)
        cout << setw(3) << "D ";
    else if (n == 4)
        cout << setw(3) << "D+" ;
    else if (n == 8)
        cout << setw(3) << "C-";
    else if (n == 16)
        cout << setw(3) << "C ";
    else if (n == 32)
        cout << setw(3) << "C+";
    else if (n == 64)
        cout << setw(3) << "B-";
    else if (n == 128)
        cout << setw(3) << "B ";
    else if (n == 256)
        cout << setw(3) << "B+";
    else if (n == 512)
        cout << setw(3) << "A-";
    else if (n == 1024)
        cout << setw(3) << "A ";
    else if (n == 2048)
        cout << setw(3) << "A+";
    else 
        cout << setw(3) << "  ";
}

void print(const vector<vector<int>>& v, const int size){
    cout << "-----------------"<<endl;
    for (int i = 0; i < size; i++){
        cout << "|";
        for (int j = 0; j < size; j++){
            transfergrade(v[i][j]);
            cout << "|";
        }
        cout << endl;
        cout << "-----------------"<<endl;

    }
    cout << endl;

    double bestscore = 0.00;
    double currentscore=0.00;
    currentscore = calculation (v,size);
    if ( bestscore < currentscore ){
        bestscore = currentscore;
    }
    cout << "Your Current Score = " << currentscore << endl;
    cout << "Your Best Score = " << bestscore << endl;
}
