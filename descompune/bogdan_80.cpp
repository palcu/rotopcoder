/*
  Bogdan Tirca
  Problema Descompune
  Complexitate: O(PROP_LEN * WORD_LEN * N)
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF (1 << 30)
#define PROP_LEN 100001
#define WORD_LEN 50

string prop;
int n;
vector <pair <string, int> > dict;
int dp[PROP_LEN], back[PROP_LEN];

int minCost;
vector <string> words;

void read() {
  string cuv;
  int cost;
  ifstream fin("descompune.in");
  fin >> prop;
  fin >> n;
  for (int i = 0; i < n; ++i) {
    fin >> cuv >> cost;
    dict.push_back(make_pair(cuv, cost));
  }
}

void write() {
  ofstream fout("descompune.out");
  if (minCost == INF) {
    fout << "-1\n";
  } else {
    for (int i = words.size() - 1; i >= 0; --i) {
      fout << words[i] << " ";
    }
    fout << "\n" << minCost << "\n";
  }
}

bool matchEnd(string &word, int right) {
  int r1 = right, r2 = word.length() - 1;
  for ( ;prop[r1] == word[r2] && r1 >= 0 && r2 >= 0; --r1, --r2);
  return (r2 == -1);
}

void solve() {
  string word;
  for (int right = 0; right < prop.length(); ++right) {
    dp[right + 1] = INF;
    for (int it = 0; it < dict.size(); ++it) {
      pair<string, int> &word = dict[it];
      // Verifica daca 'word' se potriveste la capatul propozitiei
      int left = right - word.first.length() + 1;
      if (matchEnd(word.first, right) && dp[left] + word.second < dp[right + 1]) {
        dp[right + 1] = dp[left] + word.second;
        back[right + 1] = left;
      }
    }
    word.clear();
  }

  // Reconstituim solutia de cost minim
  minCost = dp[prop.length()];
  if (minCost != INF) {
    int left, right = prop.length();
    while ((left = back[right]) != 0) {
      words.push_back(prop.substr(left, right - left));
      right = left;
    }
    words.push_back(prop.substr(0, right));
  }
}

int main() {
  read();
  solve();
  write();
  return 0;
}
