#include<iostream>
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
void print(const vector<vector<int>>& v, const int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << setw(5) << v[i][j];
        }
        cout << endl;
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
    cout << endl;
}
