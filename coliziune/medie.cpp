/* Author: Rotaru Dragos Alin
 * Expected score: 60p
 * O(sqrt(N)) time
 * O(sqrt(N)) memory
 * */


#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Task {

  int nbits;
  ll modulus, base;
  const int kBits;
  public:
    Task(ll _m, ll _b): kBits(55) {
      modulus = _m;
      base = _b;
    };

    string convert_to_bin(ll val) {
      string ret = "";

      for (int i = 0; i < kBits; ++i) {
        ll b = (val & (1LL << i));
        if (b > 0) {
          ret += "1";
        } else {
          ret += "0";
        }
      }
      return ret;
    }
    pair <string, string> solve() {
      map<ll, ll> cache;

      while(1) {

        ll preimage = 0;
        ll pow2 = 1;

        vector <int> arg(kBits);

        for (int k = 0; k < kBits; ++k) {
          arg[k] = rand() % 2;
          preimage = preimage + pow2 * arg[k];
          pow2 *= 2;
        }

        ll image = get_hash(arg);
        if (cache.find(image) != cache.end()) {
          if (cache[image] == preimage) {
            cerr << "oooops, good luck in finding another one\n";
            continue;
          }
          return make_pair(convert_to_bin(cache[image]), convert_to_bin(preimage));
        }
        cache[image] = preimage;
      }
      return make_pair("fail", "fail");
    }
    ll get_hash(vector <int> v) {
      ll val = 0;
      ll curBase = 1;

      for (int i = 0; i < kBits; ++i) {
        val = (val + 1LL * (v[i] + 1) * curBase) % modulus;
        curBase = (curBase * base) % modulus;
      }
      return val;
    }

};
int main() {
  ifstream fin("coliziune.in");
  ofstream fout("coliziune.out");
  srand(time(NULL));
  int T; fin >> T;

  assert (1 <= T && T <= 10);

  while(T--) {
    ll B, M; fin >> M >> B;

    assert(4 <= M && M <= 1e14);
    assert(2 <= B && B <= M - 2);

    Task TT(M, B);
    pair <string, string> ret = TT.solve();
    reverse(ret.first.begin(), ret.first.end());
    reverse(ret.second.begin(), ret.second.end());
    fout << ret.first << " " << ret.second << "\n";
  }
  return 0;
}
