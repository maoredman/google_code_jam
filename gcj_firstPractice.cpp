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

int main() {
    fstream myfile;
    myfile.open("A-large-practice.in.txt");
    ofstream outfile;
    outfile.open ("out.txt");
    if (myfile.is_open()) {
        string line;
        getline(myfile,line);
        int case_number = stoi(line); // number of cases
        int counter = 1;
        int credits = 0;
        int item_number = 0; // number of items for a case
        while(getline(myfile,line)){
            switch(counter % 3){
                case 1 : credits = stoi(line);
                        break;
                case 2 : item_number = stoi(line);
                        break;
                case 0 :
                    int startpos = 0; // startpos of string
                    int endpos = 0; // endpos of string
                    map <int, int> price_pos; // pos is >= 1
                    for(int i = 0; i < item_number; i++){
                        if(i == item_number - 1){
                            endpos = line.find('\n', startpos);
                        }
                        else{
                            endpos = line.find(' ', startpos);
                        }

                        int price = stoi(line.substr(startpos, endpos - startpos));
                        if(price_pos.find(credits - price) != price_pos.end()){
                            //std::cout<<"Matching price is in the map!"<<endl;
                            outfile << "Case #" << counter / 3 << ": " << price_pos.find(credits - price)->second << ' ' << i + 1 << '\n';
                            cout << "Writing case " << counter / 3 << endl;
                        }
                        else{
                            price_pos[price] = i + 1;
                        }

                        startpos = endpos + 1;
                    }
                    break;
            }
            counter++;
        }
    }
    outfile.close();
    myfile.close();

}