/* Author: Rotaru Dragos Alin
 * Expected score: 100p
 * O(sqrt(N)) time
 * O(1) memory
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
    string convert_to_binv(const vector<int>&arg) {
      string ret = "";
      for (int i = 0; i < kBits; ++i) {
        if (arg[i] == 1) {
          ret += "1";
        } else {
          ret += "0";
        }
      }
      return ret;
    }
    pair <string, string> cycle_recover(const vector <int> &arg, const vector<int>& meet_point) {

      vector <int> p1(arg);
      vector <int> p2(meet_point);
      while(1) {
        vector<int> np1 = get_hashv(p1);
        vector<int> np2 = get_hashv(p2);

        if (np1 == np2) {
          return make_pair(convert_to_binv(p1), convert_to_binv(p2));
        }
        p1 = np1;
        p2 = np2;

      }
    }
    pair <string, string> solve() {

      for (int iter = 0; iter < 10; ++iter) {
        //every time we succeed with at least 0.5
        //0.5 ^ 10 is very unlikely to fail
        vector <int> arg(kBits);
        for (int k = 0; k < kBits; ++k) {
          arg[k] = rand() % 2;
        }

        //now we have the start in arg[]
        vector <int> p1 = arg;
        vector <int> p2 = arg;
        int cur_iter = 0;

        while(cur_iter < 1e7) {
          cur_iter = cur_iter + 1;
          vector <int> np1 = get_hashv(p1);
          vector <int> np2 = get_hashv(get_hashv(p2));

          //cerr << "hash(" << convert_to_binv(p1) << ")" << convert_to_binv(np1) << "\n";
          //cerr << "hash(hash(" << convert_to_binv(get_hashv(p2)) << "))" << convert_to_binv(np2) << "\n";
          if (np1 == np2) {
            //cerr << "found a cycle\n";
            //cerr << "now founding the collision\n";
            return cycle_recover(arg, np1);
          }
          p1 = np1;
          p2 = np2;
        }
      }

      return make_pair("fail", "fail");
    }
    ll get_hash(const vector <int>& v) {
      ll val = 0;
      ll curBase = 1;

      for (int i = 0; i < kBits; ++i) {
        val = (val + 1LL * (v[i] + 1) * curBase) % modulus;
        curBase = (curBase * base) % modulus;
      }
      return val;
    }
    vector <int> get_hashv(const vector <int>& v) {
      ll val = get_hash(v);

      vector <int> ret(kBits);
      for (int i = 0; i < kBits; ++i) {
        ll b = (val & (1LL << i));
        if (b > 0) {
          ret[i] = 1;
        } else {
          ret[i] = 0;
        }
      }
      return ret;
    }

};
int main() {
  ifstream fin("coliziune.in");
  ofstream fout("coliziune.out");
  srand(time(NULL));
  int T; T = 1;

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
