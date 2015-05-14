/* Author: Rotaru Dragos Alin
 * Expected score: 100
 * Time and space complexity; O(N)
 * */


#include <bits/stdc++.h>

using namespace std;
int main() {
  ifstream cin("telina.in");
  ofstream cout("telina.out");

  string S; cin >> S;

  deque <char> deq;

  deq.push_front(*S.rbegin());

  //main idea s(1) ... rev(s(i) rev(s(i+1)s(i+2)...s(n))) -> s(1)...s(i+1)s(i+2)...s(n)s(i)
  for (int i = S.size() - 2; i >= 0; --i) {
    if (S[i] <= deq.front()) {
      deq.push_front(S[i]);
    } else {
      deq.push_back(S[i]);
    }
  }
  for (auto it: deq) {
    cout << it;
  }
  cout << "\n";
  return 0;
}
