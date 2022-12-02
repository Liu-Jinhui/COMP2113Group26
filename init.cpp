#include<iostream>
#include<vector>
#include<list>
#include<fstream>
using namespace std;

//Renew the game table by removing all the staffs in the table
//input: (vector) game table
//no output
void renew(vector<vector<int>>& v){
    while(!v.empty()){
        v.pop_back();
    }
}

//Initialize the game table based on the user's preference
//input: (string) user name, (string) user's choice of game table, (vector) game table
//output: (int) size of game table
int new_user_init(string name, string s, vector<vector<int>>& v){
    ifstream fin;
    int size = int(s[0] - '0');
    int x;
    vector<int> v0;
    if(s == "3"){
        fin.open("3x3.txt");
        for (int i = 0; i < size; i++){
            while(!v0.empty()){
                v0.pop_back();
            }
            for (int j = 0; j < size; j++){
                fin >> x;
                v0.push_back(x);
            }
            v.push_back(v0);
        }
    }
    else if(s == "4"){
        fin.open("4x4.txt");
        for (int i = 0; i < size; i++){
            while(!v0.empty()){
                v0.pop_back();
            }
            for (int j = 0; j < size; j++){
                fin >> x;
                v0.push_back(x);
            }
            v.push_back(v0);
        }
    }
    if(s == "5"){
        fin.open("5x5.txt");
        for (int i = 0; i < size; i++){
            while(!v0.empty()){
                v0.pop_back();
            }
            for (int j = 0; j < size; j++){
                fin >> x;
                v0.push_back(x);
            }
            v.push_back(v0);
        }
    }
    return size;
}
