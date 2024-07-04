#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// This value stores the range of possible values, since the
// coordinates can range from -1000 to 1000 
const int MAX_POS = 2000;

// A cell visible[x][y] is considered visible if it has a 
// billboard and it is not blocked by the truck
bool visible[MAX_POS][MAX_POS];

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    // For each rectangle we read the coordinates (x1, y1) (x2, y2)
    for (int i = 0; i < 3; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Make all coordinates positive by making the range 
        // [0, 2000] instead of [-1000, 1000], because an 
        // array can't store negative indices. 
        x1 += MAX_POS / 2;
        x2 += MAX_POS / 2;
        y1 += MAX_POS / 2;
        y2 += MAX_POS / 2;

        // Iterate through the rectangle and update visible
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                // If we are processing a billboard
                if (i < 2) {
                    visible[x][y] = true;
                }
                // If we are processing a truck
                else{
                    visible[x][y] = false;
                }
            }
        }
    }

    int squaresVisible = 0;
    for (int x = 0; x < MAX_POS; x++) {
        for (int y = 0; y < MAX_POS; y++) {
            squaresVisible += visible[x][y];
        }
    }
    cout << squaresVisible << "\n";
};
