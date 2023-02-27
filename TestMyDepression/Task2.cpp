#include <bits/stdc++.h>

using namespace std;

int solve (vector<vector<int>>& a) {
    map <int, int> hash;
    set <int> res;

    int n = a.size();
    int m = a[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If the element does not exist in the hash_map, push it in 
            // Memorize the first row occurence
            // Also check if it is already in the res set
            // If it is, skip it
            if (hash.find(a[i][j]) == hash.end() && res.find(a[i][j]) == res.end()) {
                hash[a[i][j]] = i;
            } else {
                // If the element exists in the hash_map, see if it occurs in different row
                // If it does, push it in res
                // Delete it in hash_map to prevent re-considering it
                if (hash[a[i][j]] != i) {
                    res.insert(a[i][j]);
                    hash.erase(a[i][j]);
                }
            }
        }
    }
    return res.size();
}

int main () {
    vector <vector<int>> a = {{1,2,2}, {3,1,4}};
    cout << solve (a);
}