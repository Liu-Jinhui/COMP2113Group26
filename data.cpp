#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include "calculate.h"
using namespace std;

void del(string file_name){
    ofstream fout ("temp.txt");
    ifstream fin;
    fin.open(file_name);
    string str;
    while(getline(fin, str)){
        if('0' <= str[0] && str[0] <= '9'){
            break;
        }
        fout << str << endl;
    }
    fin.close();
    fout.close();

    fin.open("temp.txt");
    fout.open(file_name);
    while(getline(fin, str)){
        fout << str << endl;
    }
    fin.close();
    fout.close();
    remove("temp.txt");
}

void insert(string file_name, vector<vector<int>>& v, int size){
    ofstream fout;
    fout.open(file_name, ios::app);
    time_t rawtime;
    time (&rawtime);
    fout << "Time: " <<  ctime (&rawtime);
    fout << "Best score: " << calculation(v, size) << endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fout << v[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

void print_history(string file_name){
    ifstream fin;
    fin.open(file_name);
    if(fin.fail()){
        cout << "Invalid user name.\n";
        return ;
    }
    string str;
    while(getline(fin, str)){
        if('0' <= str[0] && str[0] <= '9'){
            break;
        }
        cout << str << endl;
    }
}


