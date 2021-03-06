#include <bits/stdc++.h>

using namespace std;

string lowercaseAndSort(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
        }
    }
    sort(s.begin(), s.end());
    return s;
}

int main () {
    vector<string> all;
    map<string, int> v;
    for (;;) {
        string in;
        cin >> in;
        if (in.compare("#") == 0) break;
        all.push_back(in);
        v[lowercaseAndSort(in)]++;
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
        if (v[lowercaseAndSort(all[i])] == 1) {
            printf("%s\n", all[i].c_str());
        }
    }
    return 0;
}
