/*
 * Dragos Alin Rotaru - Solutie Oficiala - Birthday Paradox
 *
*/


#include <bits/stdc++.h>
#define ll long long

using namespace std;
int kBits;
ll BPowers[100];


string debug_vector(vector <int> v) {
  string temp = "";
  for (int i = 0; i < kBits; ++i) {
    if (v[i] == 0) {
      temp += "0";
    } else {
      temp += "1";
    }
  }
  return temp;
}
inline vector<int> get_bits(ll val) {
  vector <int> answer(kBits, 0);
  for (int i = 0; i < kBits; ++i) {
    if ( ((1LL << i) & val) > 0 ) {
      answer[i] = 1;
    } else {
      answer[i] = 0;
    }
  }
  return answer;
}
inline vector<int> get_hash(vector<int>A, int M) {
  ll h = 0;
  int N = A.size();
  for (int i = 0; i < kBits; ++i) {
    h = (h + ((A[i] + 1) * BPowers[N - i + 1]) % M) % M;
  }
  cerr << "value : " << h << "\n";
  vector<int> res = get_bits(h);
  return res;
}

bool is_equal(vector <int> A, vector <int> B) {
  if (A.size() != B.size()) {
    return 0;
  }
  for (size_t i = 0; i < A.size(); ++i) {
    if (A[i] != B[i]) {
      return 0;
    }
  }
  return 1;
}

pair <string, string> build_sol(vector <int> A, vector <int> B) {
  string sA = "", sB = "";
  for (int i = 0; i < kBits; ++i) {
    sA += (char)(A[i] + '0');
    sB += (char)(B[i] + '0');
  }
  return make_pair(sA, sB);
}
pair <string, string> chain(vector <int> root, int steps, int val_mod) {

  vector<int> p1 = root;
  vector<int> p2 = root;

  for (int i = 0; i < steps; ++i) {
    vector <int> forward1 = get_hash(p1, val_mod);
    vector <int> temp = get_hash(p2, val_mod);
    vector <int> forward2 = get_hash(temp, val_mod);

    //cerr << debug_vector(forward1) << " " << debug_vector(forward2) << "\n";
    //cerr << "from : " << debug_vector(p1) << " " << debug_vector(temp) << "\n";
    if (is_equal(forward1, forward2)) {
      return build_sol(p1, temp);
    }
    for (int i = 0; i < kBits; ++i) {
      p1[i] = forward1[i];
      p2[i] = forward2[i];
    }
  }
  return make_pair("fail", "fail");
}
pair <string, string> solve(int N, int B, int M) {

  ll cur_power = 1;
  for (int i = 0; i <= N; ++i) {
    if (i >= N - kBits) {
      BPowers[i - (N - kBits)] = cur_power;
    }
    cur_power = (cur_power * B) % M;
  }
  vector<int> vec{0,0};
  chain(vector<int>{0,0}, 4, M);
  cerr << "debug: " << debug_vector(get_hash(vec, M));
  cerr << "debug : " << debug_vector(get_hash(get_hash(vec, M), M));

  for (int iter = 0; iter < 1000; ++iter) {
    vector <int> v(kBits, 0);
    for (int i = 0; i < kBits; ++i) {
      v[i] = rand() % 2;
    }

    vector<int> p1 = v;
    vector<int> p2 = v;

    pair <string, string> collision = chain(v, 10000, M);
    if (collision.first == "fail") {
      continue;
    } else {
      return collision;
    }
  }
  return make_pair("fail", "fail");
}
int main() {
#ifndef ONLINE_JUDGE
  ifstream cin("coliziune.in");
  ofstream cout("coliziune.out");
#endif
  srand(time(NULL));
  int T; cin >> T;
  while(T--) {
    int N, B, M; cin >> N >> M >> B;
    kBits = min(N, 55);
    pair <string, string> answer = solve(N, B, M);

    //now make the size good
    while(answer.first.size() < (size_t)N) {
      answer.first += "0";
    }
    while(answer.second.size() < (size_t)N) {
      answer.second += "0";
    }
    cout << answer.first << " " << answer.second << "\n";
  }
  return 0;
}
