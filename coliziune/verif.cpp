#include <bits/stdc++.h>
#define ll long long
using namespace std;

void printResult(int score, string message, int exit_status = 0) {
  cout << score << " " << message;
  exit(exit_status);
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
  ifstream prb_in("coliziune.in");

  if (!prb_in.is_open()) {
    printResult(0, "Fisier de intrare lipsa", -1);
  }

  ll M, B;
  if (!(prb_in >> M >> B)) {
    printResult(0, "Fisier de intrare incomplet", -1);
  }
  assert(2 <= B && B <= M - 2);
  assert(4 <= M && M <= 1e14);

  prb_in.close();

  string X, Y;

  ifstream prb_out("coliziune.out");
  if (!prb_out.is_open()) {
    printResult(0, "Fisier de iesire incomplet", -1);
  }
  if (!(prb_out >> X >> Y)) {
    printResult(0, "Fisier de iesire incomplet");
  }
  string Z; prb_out >> Z;
  if (Z != "") {
    printResult(0, "Prea multe siruri in fisierul de iesire");
  }
  if (X.size() > 1e6 || Y.size() > 1e6) {
    printResult(0, "Sirurile depasesc lungimea maxima admisa");
  }
  if (get_hash(X, M, B) == get_hash(Y, M, B)) {
    printResult(10, "Ai nimerit!");
  } else {
    printResult(0, "Functia H are valori diferite");
  }
  return 0;
}
