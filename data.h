#include<vector>
#include<ctime>
using namespace std;

#ifndef DATA_H
#define DATA_H

void del(string file_name);
void insert(string file_name, vector<vector<int>>& v, int size, double &bestscore);
void print_history(string file_name);
void save_best(string file_name, vector<vector<int>>& v, int size);

#endif
