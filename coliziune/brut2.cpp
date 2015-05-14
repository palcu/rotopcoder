/* Author: Rotaru Dragos Alin
 * Expected score: 20p
 * O(2^11 * 2 ^ 11) time
 * O(1) memory
 * */

#define ll long long
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solver {

  ll modulus, base;
  const int kBits;

 public:
   Solver(ll _modulus, ll _base): kBits(11) {
     modulus = _modulus;
     base = _base;
   }

   long long get_hash(vector <int> key) {
      long long value = 0;
      long long bpower = 1;

      for (int i = 0; i < kBits; ++i) {
        value += 1LL * (key[i] + 1) * bpower;
        bpower *= base;

        value %= modulus;
        bpower %= modulus;
      }
      return value;
   }
   string convert_to_string(vector <int> v) {
     string x = "";
     for (int i = 0; i < kBits; ++i) {
       if (v[i] == 0) {
         x += "0";
       } else if (v[i] == 1) {
         x += "1";
       }
     }
     return x;
   }
   pair <string, string> _compute_result() {
     vector <vector<int> > trial_values;
     for (int i = 0; i < (1 << kBits); ++i) {
       vector <int> trial(kBits);
       for (int b = 0; b < kBits; ++b) {
         if (i & (1 << b)) {
           trial[b] = 1;
         } else {
           trial[b] = 0;
         }
       }
       trial_values.push_back(trial);
     }

     for (int i = 0; i < trial_values.size(); ++i) {
       for (int j = i + 1; j < trial_values.size(); ++j) {
         if (get_hash(trial_values[i]) == get_hash(trial_values[j])) {
           return make_pair(convert_to_string(trial_values[i]), convert_to_string(trial_values[j]));
         }
       }
     }

     return make_pair("", "");
   }

   pair <string, string> compute_result() {
     pair <string, string> ret = _compute_result();
     reverse(ret.first.begin(), ret.first.end());
     reverse(ret.second.begin(), ret.second.end());

     return ret;
   }
};
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  ifstream cin("coliziune.in");
  ofstream cout("coliziune.out");
#endif

  ll M, B; cin >> M >> B;

  Solver S(M, B);
  pair <string, string> ret = S.compute_result();
  cout << ret.first << " " << ret.second << "\n";
  return 0;
}
