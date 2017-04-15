#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unordered_map>

using namespace std;
// in terminal: MY_PROGRAM < input_file.txt > output_file.txt
int max (int a, int b) {
    return (a > b) ? a : b;
}
int min (int a, int b) {
    return (a < b) ? a : b;
}

bool thisPackageWorks (int ingredientIndex, int input_lower, int input_higher, vector<int>& ingredientRequirement, unordered_map<int,vector<int> >& packagesOfIngredients) {

    if (ingredientIndex >= ingredientRequirement.size()) {
        return true;
    }

    int lower, higher;
    for (int b = 0; b < packagesOfIngredients[ingredientIndex].size(); ++b) {
        lower = ceil(packagesOfIngredients[ingredientIndex][b] / 1.1 / (float) ingredientRequirement[ingredientIndex]);
        higher = floor(packagesOfIngredients[ingredientIndex][b] / 0.9 / (float) ingredientRequirement[ingredientIndex]);

        /* cout << "internal lower is " << lower << endl;
        cout << "internal higher is " << higher << endl; */
        if ( (higher >= lower) && (higher >= input_lower && lower <= input_higher) ) { // this level OK
            bool worksForOtherIngredients = thisPackageWorks(ingredientIndex + 1, max(lower, input_lower), min(higher, input_higher), ingredientRequirement, packagesOfIngredients);
            if (worksForOtherIngredients) {
                // erase the i+1th element
                packagesOfIngredients[ingredientIndex].erase(packagesOfIngredients[ingredientIndex].begin() + b);
                --b;
                return true;
            }
        }
    }
    return false;
}

int main() { // works only in cases where "first come, first served" works; doesn't optimize for most number of kits
    int T;
    int numIngredients, packages; // N, P
    cin >> T;
    for (int i = 1; i <= T; ++i) {

        cin >> numIngredients >> packages;

        vector<int> ingredientRequirement; // ingredient indices 0 ~ numIngredients-1
        for (int i = 0; i < numIngredients; ++i) {
            int requirement;
            cin >> requirement;
            ingredientRequirement.push_back(requirement);
        }

        unordered_map<int,vector<int> > packagesOfIngredients;
        for (int a = 0; a < numIngredients; ++a){
            vector<int> packagesOfOneIngredient;
            for (int b = 0; b < packages; ++b){
                int onePackage;
                cin >> onePackage;
                packagesOfOneIngredient.push_back(onePackage);
            }
            packagesOfIngredients[a] = packagesOfOneIngredient;
        }

        int count = 0;
        for (int a = 0; a < packages; ++a) {
            int lower = ceil(packagesOfIngredients[0][a] / 1.1 / (float)ingredientRequirement[0]);
            int higher = floor(packagesOfIngredients[0][a] / 0.9 / (float)ingredientRequirement[0]);
            if( higher >= lower && thisPackageWorks(1, lower, higher, ingredientRequirement, packagesOfIngredients) ) {
                ++count;
            }
        }
        cout << "Case #" << i << ": " << count << endl;
    }
}