#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unordered_map>

using namespace std;
// in terminal: MY_PROGRAM < input_file.txt > output_file.txt

int main() {
    int T;
    int R, C;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> R >> C;
        vector< vector<char> > cake;
        string cakeRow = "";
        for (int a = 0; a < R; ++a){
            cin >> cakeRow;
            vector<char> row;
            for (int b = 0; b < C; ++b){
                row.push_back(cakeRow[b]);
            }
            cake.push_back(row);
        }

        unordered_map<char,bool> doneChar;
        for (int a = 0; a < R; ++a) {
            for (int b = 0; b < C; ++b){
                if (cake[a][b] != '?' && doneChar.find(cake[a][b])==doneChar.end()){
                    doneChar[cake[a][b]] = true;
                    int runUp = a - 1;
                    int runDown = a + 1;
                    int runLeft = b - 1;
                    int runRight = b + 1;
                    //cout << "now at position " << a << ' ' << b << endl;

                    while (runLeft >= 0 && cake[a][runLeft] == '?') {
                        cake[a][runLeft] = cake[a][b];
                        --runLeft;
                    }
                    while (runRight <= C - 1 && cake[a][runRight] == '?') {
                        cake[a][runRight] = cake[a][b];
                        ++runRight;
                    }

                    bool canRunUp = true;
                    while (runUp >= 0) {
                        for (int j = runLeft + 1; j < runRight; ++j) {
                            if (cake[runUp][j] != '?') {
                                canRunUp = false;
                                break;
                            }
                        }
                        if (!canRunUp){
                            break;
                        }
                        for (int j = runLeft + 1; j < runRight; ++j) {
                            cake[runUp][j] = cake[a][b];
                        }
                        --runUp;
                    }

                    bool canRunDown = true;
                    while (runDown <= R - 1) {
                        for (int j = runLeft + 1; j < runRight; ++j) {
                            if (cake[runDown][j] != '?') {
                                canRunDown = false;
                                break;
                            }
                        }
                        if (!canRunDown){
                            break;
                        }
                        for (int j = runLeft + 1; j < runRight; ++j) {
                            cake[runDown][j] = cake[a][b];
                        }
                        ++runDown;
                    }
                }
            }
        }
        cout << "Case #" << i << ":" << endl;
        for (int a = 0; a < R; ++a) {
            for (int b = 0; b < C; ++b){
                cout << cake[a][b];
            }
            cout << endl;
        }
    }
}