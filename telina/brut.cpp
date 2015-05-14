#include <bits/stdc++.h>

using namespace std;
int main() {
  ifstream cin("telina.in");
  ofstream cout("telina.out");

  string S; cin >> S;

  int n = S.size();


  string sresult = S;
  for (int i = 0; i < (1 << n); ++i) {
    string sprim = S;
    for (int j = n - 1; j >= 0; --j) {
      if (i & (1 << j)) {
        reverse(sprim.begin() + j, sprim.end());
      }
    }
    if (sprim < sresult) {
      sresult = sprim;
    }
  }
  cout << sresult << "\n";
  return 0;
}
