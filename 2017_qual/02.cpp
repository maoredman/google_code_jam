#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
// in terminal: MY_PROGRAM < input_file.txt > output_file.txt
// The input consists of one line with a number of test cases T, and then T more lines, each of which contains two positive integers N and M
int main() {
    int T = 0;
    string N = ""; // store number as string for time being; will write to int vector
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        unsigned long long int result = 0;
        vector<int> input;
        for (int a = 0; a < N.length(); ++a) {
            input.push_back( N[a] - '0' );
        }
        for (int a = input.size() - 1; a >= 1; --a) {
            if (input[a] < input[a-1]) {
                for (int b = a; b < input.size(); ++b) {
                    if (input[b] == 9) {
                        break;
                    }
                    input[b] = 9;
                }
                while (input[a-1] == 0) {
                    input[a-1] = 9;
                    --a;
                }
                input[a-1] = input[a-1] - 1;
            }
        }
        for (int a = 0; a < input.size(); ++a){
            result = result * 10 + input[a];
        }
        cout << "Case #" << i << ": " << setprecision(input.size()) << result << "\n";
    }
}