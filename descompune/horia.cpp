#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> matches(const string& p, const string& t) {
    int pos = -1;
    vector<int> ret;
    while ( (pos = static_cast<int>(p.find(t, pos + 1))) != -1) {
        ret.push_back(pos);
    }
    return ret;
}

pair< vector<string>, int> solve(const string& s,
                                 const int& n,
                                 const vector< pair<string,int> >& dictionary) {
    vector< pair<int,int> > p;   
    for (int i = 0; i < n; i++) {
        const auto& word = dictionary[i];
        vector<int> m = matches(s, word.first);
        for (int& position : m) {
            p.push_back(make_pair(position + 1, i));
        }
    }
    const int inf = int(1e9);
    sort (begin(p), end(p));
    vector<int> dp(s.size() + 1, inf);
    vector<int> who(s.size() + 1, -1);
    dp[0] = 0;
    for (pair<int,int>& match : p) { 
        if (dp[match.first + dictionary[match.second].first.size() - 1] > 
            dp[match.first - 1] + dictionary[match.second].second) {
            dp[match.first + dictionary[match.second].first.size() - 1] = 
            dp[match.first - 1] + dictionary[match.second].second;
            who[match.first + dictionary[match.second].first.size() - 1] = match.second; 
        }

    }
    if (dp[s.size()] == inf)   
        return make_pair(vector<string>(), -1);
   
    vector<string> solution;
    for (int L = static_cast<int>(s.size()); L;) {
        solution.push_back(dictionary[who[L]].first);
        L = L - dictionary[who[L]].first.size();
    }

    return make_pair(solution, dp[s.size()]);
}

int main() {
    string s;
    vector< pair<string, int> > d;
    getline(cin, s);
    int n;
    cin >> n;
    cin.get();
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
    }

    pair< vector<string>, int> ans = solve(s, n, d);
    if (ans.second == -1) {
        cout << "-1\n";
    } else {
        for (auto& word : ans.first) {
            cout << word << " ";
        }
        cout << "\n";
        cout << ans.second << "\n";
    }
    return 0;
}
