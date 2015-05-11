#include <bits/stdc++.h>
#define ll long long
using namespace std;

void give_score(int score) {
  cerr << "score: " << score << "\n";
  exit(0);
}
ll get_hash(string A, ll M, ll B) {
  ll val = 0;
  ll bpower = 1;

  reverse(A.begin(), A.end());
  for (size_t i = 0; i < A.size(); ++i) {
    val = val + ((A[i] - '0') + 1) * bpower;
    val %= M;

    bpower = bpower * B;
    bpower %= M;
  }
  return val;
}
int main() {
#ifndef ONLINE_JUDGE
  ifstream prb_in("coliziune.in");
  ifstream prb_out("coliziune.out");
#endif


  ll M, B;
  assert(prb_in >> M >> B);
  assert(2 <= B && B <= M - 2);
  assert(4 <= M && M <= 1e14);

  prb_in.close();

  string X, Y;
  if (!(prb_out >> X >> Y)) {
    give_score(0);
  }
  string Z; prb_out >> Z;
  if (Z != "") {
    give_score(0);
  }
  if (X.size() > 1e6 || Y.size() > 1e6) {
    give_score(0);
  }
  if (get_hash(X, M, B) == get_hash(Y, M, B)) {
    give_score(10);
  } else {
    give_score(0);
  }
  return 0;
}
