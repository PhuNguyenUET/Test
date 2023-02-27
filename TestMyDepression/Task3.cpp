#include <bits/stdc++.h>

using namespace std;

int solve (vector <int>& a) {
    //Sort the array first
    sort (a.begin(), a.end());
    vector <int> occurence_tmp;

    int res = 0;
    int n = a.size();
    int cur = 1;

    // Get the occurence of numbers in the array
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cur ++;
        } else {
            occurence_tmp.push_back(cur);
            cur = 1;
        }
    }

    // Sort the occurence array
    occurence_tmp.push_back(cur);
    sort (occurence_tmp.begin(), occurence_tmp.end());

    set <int> occurence;

    // If the current occurence is not unique, decrease it until it is unique
    // Because the occurence array is in ascending order,
    // it will be pushed into the set also in ascending order
    for (auto i : occurence_tmp) {   
        if (occurence.find(i) == occurence.end()) {
            occurence.insert(i);
        } else {
            int tmp = i;
            while (occurence.find(tmp) != occurence.end()) {
                tmp --;
                res ++;
            }
        }
    }
    return res;
}

int main () {
    vector <int> a = {127, 15, 3, 8, 10};
    cout << solve (a);
}