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
unsigned long long int howManyOnes (unordered_map<unsigned long long int,unsigned long long int>& mapHowManyOnes, unsigned long long int number) {
    unordered_map<unsigned long long int,unsigned long long int>::const_iterator got = mapHowManyOnes.find(number);
    if ( got == mapHowManyOnes.end() ) {
        unsigned long long int smaller = number / 2 - (number + 1) % 2;
        unsigned long long int larger = number / 2;
        mapHowManyOnes[number] = howManyOnes(mapHowManyOnes, smaller) + howManyOnes(mapHowManyOnes, larger);
    }

    return mapHowManyOnes[number];

}
int main() {
    int T;
    unsigned long long int N, K;
    cin >> T;
    unordered_map<unsigned long long int,unsigned long long int> mapHowManyOnes;
    mapHowManyOnes[2] = 1;
    mapHowManyOnes[1] = 1;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K;
        if (K + howManyOnes(mapHowManyOnes, N) > N ) {
            cout << "Case #" << i << ": " << 0 << ' ' << 0 << endl;
        }
        else {
            unsigned long long int result1 = 0;
            unsigned long long int result2 = 0;
            unsigned long long int d = 0; // log2(K)
            for(int i = 63; i >= 0; --i) {
                if ((K >> i) & 1) {
                    d = i;
                    break;
                }
            }
            unsigned long long int e = K - exp2(d) + 1; // 'e'th to receive "additional"
            unsigned long long int m = d + 1; // dropped how many layers
            unsigned long long int r = exp2(m); // how many elements in this layer
            unsigned long long int w = N - (r - 1); // hypothetical sum of elements in this layer
            unsigned long long int n = w / r; // base
            unsigned long long int p = w - r * n; // how many additional 1s to pass down in this layer
            cout << "K is " << K << '\n' << "d (log2K) is " << d << '\n' << "e (eth to receive) is " << e << '\n' << "m (num layers dropped) is " << m << '\n' << "r (hypothetical num of elems in this layer) is " << r << '\n' << "w (sum of elements in this layer) is " << w << '\n' << "n (each element starting base) is " << n << '\n' << "p (how many additional 1s to pass) is " << p << endl;
            if ( w <= r) { // if w <= r/2
                result1 = 1;
                result2 = 0;
            }
            else if (p >= e + r/2) {
                result1 = result2 = n + 1;
            } else if (p >= e) {
                result1 = n+1; // larger number on left
                result2 = n;
            } else {
                result1 = result2 = n;
            }
            cout << "Case #" << i << ": " << result1 << ' ' << result2 << endl;
        }
    }
}