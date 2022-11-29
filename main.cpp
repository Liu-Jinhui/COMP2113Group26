//main.cpp

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdio>
#include "calculate.h"
#include "menu.h"
#include "move.h"
#include "print.h"
#include "status.h"
using namespace std;

struct position{
    int x,y;
};

int best_score = 0;

const int initialized_values[3] = {0, 2, 4};
int table_size;

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

void update(string file_name, bool deletion, bool insertion){
    if (deletion){
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
            cout << str << endl;
            fout << str;
        }
        fin.close();
        fout.close();
        remove("temp.txt");
    }
}

int main(){
    vector<vector<int>> game_table;

    string status, name;
    while (true){
        cout << "Are you a new user?[Yes|No]" << endl;
        cin >> status;
        cout << "What's your name?";
        cin >> name;
        if (status == "Yes"){
            cout << "Your prefered table size?[3|4|5]" << endl;
            string s;
            cin >> s;
            table_size = new_user_init(name, s, game_table);
            break;
        }
        else if (status == "No"){
            ifstream fin;
            string file_name = name + ".txt";
            fin.open(file_name);
            if(fin.fail()){
                cout << "No record found. Please try again.";
                continue;
            }
            string str;
            bool flag = false;
            while(getline(fin, str)){
                if('0' <= str[0] && str[0] <= '9'){
                    vector<int> v0;
                    if (!flag) cout << "This is your latest game history." << endl;
                    flag = true;
                    int len = str.length();
                    int x, cnt = 0, print_cnt = 0;
                    for(int i = 0; i < len; i++){
                        if(str[i] == ' '){
                            cout << setw(5) << cnt;
                            v0.push_back(cnt);
                            print_cnt++;
                            cnt = 0;
                        }
                        else{
                            x = int(str[i] - '0');
                            cnt = cnt * 10 + x;
                        }
                    }
                    if(print_cnt < len){
                        cout << setw(5) << cnt;
                    }
                    print_cnt = 0;
                    game_table.push_back(v0);
                    table_size = len;
                    cout << endl;
                }
            }
            fin.close();
            cout << "Do you want to continue?[Yes|No]" << endl;
            string option;
            cin >> option;
            if(option == "No"){
                bool del = true;
                bool ins = false;
                update(file_name, del, ins);
                break;
            }
        }
    }
    //print menu
    //get user's options
    //call move function
    //calculate score
    //print game table and score
    //check status
    return 0;
}