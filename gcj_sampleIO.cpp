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
int main() {
    int t, n, m;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;  // read n and then m.
        cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
    }
}