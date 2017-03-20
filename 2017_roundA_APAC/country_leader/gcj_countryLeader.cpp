#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
/*The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with an interger N, the number of people in the country. Then N lines follow. The i-th line represents the name of the i-th person. Each name contains at most 20 characters and contains at least one alphabet letter.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the name of the leader. */

using namespace std;
// in terminal: MY_PROGRAM < input_file.txt > output_file.txt
// The input consists of one line with a number of test cases T, and then T more lines, each of which contains two positive integers N and M
int main() {
    int cases= 0;
    cin >> cases;
    for (int case_number = 1; case_number <= cases; ++case_number) {
        int people = 0;
        cin >> people;
        cin.ignore(); // to avoid interfering with getline(cin, name)
        int max = 0;
        string max_name = "";
        for(int person = 0; person < people; ++person){
            string name;
            getline(cin, name);
            bool alphabet[26] = {false};
            int count = 0;
            for(int letter = 0; letter < name.length(); ++letter){
                if(name[letter] != ' ' && alphabet[ name[letter] - 'A' ] == false){
                    alphabet[ name[letter] - 'A' ] = true;
                    count++;
                }
            }
            if(count > max){
                max_name = name;
                max = count;
            }
            else if(count == max){
                int a = 0;
                int b = 0;
                while(a < max_name.length() && b < name.length()){
                    /*while(max_name[a] == ' ')   a++;
                    while(name[b] == ' ')   b++;*/

                    if(max_name[a] < name[b])   break;
                    else if(name[b] < max_name[a]){
                        max_name = name;
                        max = count;
                        break;
                    }
                    else{
                        a++; b++;
                    }
                }
            }
        }
        cout << "Case #" << case_number << ": " << max_name << endl;
    }
}