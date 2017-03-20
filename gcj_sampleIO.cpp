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
    int t, n, m;
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;  // read n and then m.
        cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
    }
}