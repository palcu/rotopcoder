#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Task {

  int nbits, modulus, base;
  const int kBits;
  public:
    Task(int _m, int _b): kBits(5)
    {
      modulus = _m;
      base = _b;
    };

    string convert_to_bin(ll val) {
      string ret = "";

      for (int i = 0; i < kBits; ++i) {
        int b = (val & (1LL << i));
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

      int sqr = sqrt(modulus);
      for (int iter = 0; iter < 100; ++iter) {
        cache.clear();
        for (int i = 0; i < sqr; ++i) {
          vector <int> v(kBits);
          ll x = 0;
          for (int k = 0; k < kBits; ++k) {
            v[k] = rand() % 2;
            x = x * 2 + v[k];
          }
          ll val = get_hash(v);
          if (cache.find(val) != cache.end()) {
            if (cache[val] != x) {
              cerr << val << "\n";
              return make_pair(convert_to_bin(cache[val]), convert_to_bin(x));
            }
          } else {
            cache[val] = x;
          }
        }
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
    int B, M; fin >> M >> B;

    assert(4 <= M && M <= 1e7);
    assert(2 <= B && B <= M - 2);

    Task TT(M, B);
    pair <string, string> ret = TT.solve();
    reverse(ret.first.begin(), ret.first.end());
    reverse(ret.second.begin(), ret.second.end());
    fout << ret.first << " " << ret.second << "\n";
  }
  return 0;
}
