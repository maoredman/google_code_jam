#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;
// in terminal: MY_PROGRAM < input_file.txt > output_file.txt
// The input consists of one line with a number of test cases T, and then T more lines, each of which contains two positive integers N and M
int main() {
    int T = 0;
    string S = "";
    int K = 0;
    cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= T; ++i) {
        cin >> S >> K;
        char* pancakes = new char[S.length()]; // pancakes array
        strcpy(pancakes, S.c_str());

        int flipCount = 0;
        for (int a = 0; a <= strlen(pancakes) - K; ++a) {
            if (pancakes[a] == '-') {
                /* cout << "flip into: ";
                for (int b = 0; b < strlen(pancakes); ++b) cout << pancakes[b];
                cout << endl; */
                pancakes[a] = '+';
                ++flipCount;
                for (int b = 1; b < K; ++b) {
                    if (pancakes[a + b] == '-') {
                        pancakes[a + b] = '+';
                    } else {
                        pancakes[a + b] = '-';
                    }
                }
            }
        }

        string result = to_string(flipCount);
        for (int a = strlen(pancakes) - 1; a > strlen(pancakes) - K; --a) {
            if (pancakes[a] == '-') {
                result = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << i << ": " << result << "\n";
    }
}