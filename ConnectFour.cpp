#include "Checker.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Checker checker1;
    checker1.render();
    checker1.setPieceVal('B');
    checker1.render();
    cout << endl;

    //vector<vector<Checker>>test(5, vector<Checker>(2));

    /*for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            test[i][j].render();
        }
        cout << endl;
    }
    */

}


