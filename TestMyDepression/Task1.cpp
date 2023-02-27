#include <bits/stdc++.h>

using namespace std;

// Get the number of digits for the number
// To calculate the dash and the space needed
int getDigits (int m) {
    int digits = 0;
    while (m >= 1) {    
        m/=10;
        digits ++;
    }
    return digits;
}

// Print the +---+---
void printTop (int k, int numDash) {
    for (int j = 0; j < k; j++) {
            cout << "+";
            for (int l = 0; l < numDash; l++) {
                cout << "-";
            }
        }
}

// Print the main content of the cell (the number)
void printMainContent (int k, int numDash, int& ctr, vector<int>& a) {
        for (int j = 0; j < k; j++) {
            int cur = a[ctr];

            // The number of space in a cell
            int numSpace = numDash - getDigits(cur);
            cout << "|";
            for (int l = 0; l < numSpace; l++) {
                cout << " ";
            }
            cout << cur;
            ctr ++;
        }
}

void solve (vector <int> &a, int k) {
    int n = a.size();
    int r = n/k + 1;
    int lastRow = n % k;
    int mx_element = a[0];

    // Get the max element
    for (int i = 0; i < n; i++) {
        if (a[i] > mx_element) {
            mx_element = a[i];
        }
    }

    int ctr = 0;

    // Number of dash in a cell
    int numDash = getDigits(mx_element);
    // The upper cells
    for (int i = 0; i < r - 1; i++) {

        // Print the top of cells
        printTop(k, numDash);
        cout << "+" << endl;

        // Print the main content of cells
        printMainContent(k, numDash, ctr, a);
        cout << "|" << endl;
    }

    printTop(k, numDash);
    cout << "+" << endl;

    printMainContent(lastRow, numDash, ctr, a);

    if (lastRow != 0) {
        cout << "|" << endl;
    }
    printTop(lastRow, numDash);

    if (lastRow != 0) {
        cout << "+";
    }

}

int main () {
    vector <int> a = {4, 35, 80, 123};
    int k = 3;
    solve (a, k);
}