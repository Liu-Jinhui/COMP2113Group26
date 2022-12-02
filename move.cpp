//move.cpp

#include<iostream>
#include<vector>
#include "move.h"
using namespace std;

//move up
//input: (vector) game table, (int) table size
//no output
void up(vector<vector<int>>& v, const int size){
    vector<int> current_col, new_col;
    int col_size;
    for(int j = 0; j < size; j++){
        while (!current_col.empty()){
            current_col.pop_back();
        }
        while (!new_col.empty()){
            new_col.pop_back();
        }
        for(int i = 0; i < size; i++){
            if(v[i][j] != 0){
                current_col.push_back(v[i][j]);
            }
        }
        if(current_col.size() > 1){
            col_size = current_col.size();
            int k = 0;
            while(k < col_size){
                if(k < col_size - 1 && current_col[k] == current_col[k+1]){
                    new_col.push_back(current_col[k]*2);
                    k += 2;
                }
                else{
                    new_col.push_back(current_col[k]);
                    k++;
                }
            }
        }
        else if(current_col.size() == 1){
            new_col.push_back(current_col.front());
            current_col.erase(current_col.begin());
        }
        col_size = new_col.size();
        for(int i = 0; i < size; i++){
            if(i < col_size){
                v[i][j] = new_col.front();
                new_col.erase(new_col.begin());
            }
            else {
                v[i][j] = 0;
            }
        }
    }
}

//move down
//input: (vector) game table, (int) table size
//no output
void down(vector<vector<int>>& v, const int size){
    vector<int> current_col, new_col;
    int col_size;
    for(int j = 0; j < size; j++){
        while (!current_col.empty()){
            current_col.pop_back();
        }
        while (!new_col.empty()){
            new_col.pop_back();
        }
        for (int i = size - 1; i >= 0; i--){
            if(v[i][j] != 0){
                current_col.push_back(v[i][j]);
            }
        }
        int k = 0;
        if(current_col.size() > 1){
            col_size = current_col.size();
            int k = 0;
            while(k < col_size){
                if(k < col_size - 1 && current_col[k] == current_col[k+1]){
                    new_col.push_back(current_col[k]*2);
                    k += 2;
                }
                else{
                    new_col.push_back(current_col[k]);
                    k++;
                }
            }
        }
        else if(current_col.size() == 1){
            new_col.push_back(current_col.front());
            current_col.erase(current_col.begin());
        }
        for(int i = size - 1; i >=0; i--){
            if(!new_col.empty()){
                v[i][j] = new_col.front();
                new_col.erase(new_col.begin());
            }
            else{
                v[i][j] = 0;
            }
        }
    }
}

//move left
//input: (vector) game table, (int) table size
//no output
void left(vector<vector<int>>& v, const int size){
    vector<int> current_row, new_row;
    int row_size;
    for(int i = 0; i < size; i++){
        while (!current_row.empty()){
            current_row.pop_back();
        }
        while (!new_row.empty()){
            new_row.pop_back();
        }
        for (int j = 0; j < size; j++){
            if(v[i][j] != 0){
                current_row.push_back(v[i][j]);
            }
        }
        int k = 0;
        if(current_row.size() > 1){
            row_size = current_row.size();
            int k = 0;
            while(k < row_size){
                if(k < row_size - 1 && current_row[k] == current_row[k+1]){
                    new_row.push_back(current_row[k]*2);
                    k += 2;
                }
                else{
                    new_row.push_back(current_row[k]);
                    k++;
                }
            }
        }
        else if(current_row.size() == 1){
            new_row.push_back(current_row.front());
            current_row.erase(current_row.begin());
        }
        for(int j = 0; j < size; j++){
            if(!new_row.empty()){
                v[i][j] = new_row.front();
                new_row.erase(new_row.begin());
            }
            else{
                v[i][j] = 0;
            }
        }
    }
}

//move right 
//input: (vector) game table, (int) table size
//no output
void right(vector<vector<int>>& v, const int size){
    vector<int> current_row, new_row;
    int row_size;
    for(int i = 0; i < size; i++){
        while (!current_row.empty()){
            current_row.pop_back();
        }
        while (!new_row.empty()){
            new_row.pop_back();
        }
        for (int j = size - 1; j >= 0; j--){
            if(v[i][j] != 0){
                current_row.push_back(v[i][j]);
            }
        }
        int k = 0;
        if(current_row.size() > 1){
            row_size = current_row.size();
            int k = 0;
            while(k < row_size){
                if(k < row_size - 1 && current_row[k] == current_row[k+1]){
                    new_row.push_back(current_row[k]*2);
                    k += 2;
                }
                else{
                    new_row.push_back(current_row[k]);
                    k++;
                }
            }
        }
        else if(current_row.size() == 1){
            new_row.push_back(current_row.front());
            current_row.erase(current_row.begin());
        }
        for(int j = size - 1; j >= 0; j--){
            if(!new_row.empty()){
                v[i][j] = new_row.front();
                new_row.erase(new_row.begin());
            }
            else{
                v[i][j] = 0;
            }
        }
    }
}
