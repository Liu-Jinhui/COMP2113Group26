//main.cpp

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<list>
#include<cstdio>
#include<time.h>
#include "calculate.h"
#include "menu.h"
#include "move.h"
#include "print.h"
#include "status.h"
#include "update.h"
#include "data.h"
#include "init.h"
using namespace std;

int table_size;

double bestscore = 0.00;

//Show different things based on user's choice to the options shown on the menu
void work_menu(string opt, vector<vector<int>>& v, string name){
    while (true){
        if(opt == "R"){
            print_regulation();
            return ;
        }
        else if(opt == "S"){
            return ;
        }
        else if(opt == "E"){
            bool del = false, ins = true;
            if(name != ""){
                string file_name = name + ".txt";
                insert(file_name, v, table_size, bestscore);
            }
            bye();
            exit(1);
        }
        else if(opt == "H"){
            string file_name = name + ".txt";
            print_history(file_name);
            return ;
        }
        else{
            cout << "Invalid option. Please type in again:";
            cin >> opt;
        }
    }
}

int main(){
    vector<vector<int>> game_table;
    string status, name = "";
    welcome();

    print_menu();
    string menu_opt;
    cin >> menu_opt;
    work_menu(menu_opt, game_table, name);

    while (true){
        cout << "Are you a new user?[Yes|No]" << endl;
        cin >> status;
        cout << "What's your name?";
        cin >> name;
        if (status == "Yes"){//new user
            cout << "Your prefered table size?[3|4|5]" << endl;
            string s;
            cin >> s;
            table_size = new_user_init(name, s, game_table);
            break;
        }
        else if (status == "No"){//old user
            //load user's previous game history
            ifstream fin;
            string file_name = name + ".txt";
            fin.open(file_name);
            if(fin.fail()){
                cout << "No record found. Please try again. ";
                continue;
            }
            string str;
            bool flag = false;
            while(getline(fin, str)){
                if('0' <= str[0] && str[0] <= '9'){
                    vector<int> v0;
                    if (!flag) cout << "\nThis is your latest game history.\n" << endl;
                    flag = true;
                    int len = str.length();
                    int x, cnt = -1, print_cnt = 0;
                    for(int i = 0; i < len; i++){
                        if(str[i] == ' '){
                            v0.push_back(cnt);
                            print_cnt++;
                            cnt = -1;
                        }
                        else{
                            if(cnt == -1) cnt = 0;
                            x = int(str[i] - '0');
                            cnt = cnt * 10 + x;
                        }
                    }
                    if(cnt != -1){
                        print_cnt++;
                        v0.push_back(cnt);
                    }
                    game_table.push_back(v0);
                    table_size = print_cnt;
                    print_cnt = 0;
                }
            }
            fin.close();
            if(flag){
                print(game_table, table_size, bestscore);//print user's latest unfinished game history
            }
            else{
                cout << "No previous game to continue. Please start a new game.\n";//no latest unfinished game history found
                cout << "Your prefered table size?[3|4|5]" << endl;
                string s;
                cin >> s;
                table_size = new_user_init(name, s, game_table);//start a new game based on the users preference
                break;
            }
            flag = false;
            while(true){
                cout << "Do you want to continue?[Yes|No]" << endl;
                string option;
                cin >> option;
                if(option == "No"){
                    del(file_name);
                    renew(game_table);
                    cout << "Let's start a new game. What is your prefered table size?[3|4|5]" << endl;
                    string s;
                    cin >> s;
                    table_size = new_user_init(name, s, game_table);//start a new game based on the users preference
                    flag = true;
                    break;
                }
                else if(option == "Yes"){//keep playing the unfinished one
                    del(file_name); 
                    flag = true;
                    break;
                }
                else{
                    cout << "Invalid option. Please try again" << endl;
                }
            }
            if(flag) break;
        }
    }
    //get availale positions for generating new tiles
    list<position> available_pos;
    position *p = new position;

    for(int i = 0; i < table_size; i++){
        for (int j = 0; j < table_size; j++){
            p -> x = i;
            p -> y = j;
            available_pos.push_back((*p));
        }
    }

    //play the game: move the slides in different directions
    generate_new_vertex(game_table, available_pos, table_size, bestscore);
    cout << "1|up  2|down  3|left  4|right  exit|end game  M|show menu" << endl;
    string opt;
    while(cin >> opt){
        if(opt == "1"){//move up
            if(check_alive(game_table, table_size) == 34){//if the user choose to move up, but the current status only allows to move left or right
                string file_name = name + ".txt";
                save_best(file_name, game_table, table_size);
                cout << "Game Over" << endl;
                break; 
            }
            up(game_table, table_size);
            update_available_positions(game_table, available_pos, table_size);
            generate_new_vertex(game_table, available_pos, table_size, bestscore);
        }
        else if(opt == "2"){//move down
            if(check_alive(game_table, table_size) == 34){//if the user choose to move down, but the current status only allows to move left or right
                string file_name = name + ".txt";
                save_best(file_name, game_table, table_size);
                cout << "Game Over" << endl;
                break; 
            }
            down(game_table, table_size);
            update_available_positions(game_table, available_pos, table_size);
            generate_new_vertex(game_table, available_pos, table_size, bestscore);
        }
        else if(opt == "3"){//move left
            if(check_alive(game_table, table_size) == 12){//if the user choose to move left, but the current status only allows to move up or down
                string file_name = name + ".txt";
                save_best(file_name, game_table, table_size);
                cout << "Game Over" << endl;
                break; 
            }
            left(game_table, table_size);
            update_available_positions(game_table, available_pos, table_size);
            generate_new_vertex(game_table, available_pos, table_size, bestscore);
        }
        else if(opt == "4"){//move right
            if(check_alive(game_table, table_size) == 12){//if the user choose to move right, but the current status only allows to move up or down
                string file_name = name + ".txt";
                save_best(file_name, game_table, table_size);
                cout << "Game Over" << endl;
                break; 
            }
            right(game_table, table_size);
            update_available_positions(game_table, available_pos, table_size);
            generate_new_vertex(game_table, available_pos, table_size, bestscore);
        }
        else if(opt == "M"){//show menu
           print_menu();
           cin >> menu_opt;
           work_menu(menu_opt, game_table, name); 
           print(game_table, table_size, bestscore);
        }
        else if(opt == "E"){//exit the game
            bool del = false, ins = true;
            if(name != ""){
                string file_name = name + ".txt";
                insert(file_name, game_table, table_size, bestscore);
            }
            bye();
            break;
        }
        else{
            print(game_table, table_size, bestscore);
        }
        if(!check_alive(game_table, table_size)){//no available movement
            string file_name = name + ".txt";
            save_best(file_name, game_table, table_size);
            cout << "Game Over" << endl;
            break;
        }
        cout << "1|up  2|down  3|left  4|right  E|end game  M|show menu" << endl;
    }

    return 0;
}
