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
#define PROP_LEN 1001
#define WORD_LEN 50

// Optimisations
#define OPT1 true

string prop;
int n;
vector <pair <string, int> > dict;
int dp[PROP_LEN], back[PROP_LEN];
int backSol[PROP_LEN];

int minCost;
vector <string> words;

// ofstream fout("descompune.out");

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

void backt(int propPos) {
	if (propPos == prop.length() - 1) {
		// Solutie
		if (minCost > dp[prop.length()]) {
			minCost = dp[prop.length()];
			memcpy(backSol, back, sizeof(int) * PROP_LEN);
		}
	} else {
	  for (auto &word : dict) {
	  	int right = propPos + word.first.length();
	  	int left = propPos + 1;
	  	if (right < prop.length() && matchEnd(word.first, right)) {
	  		if (OPT1 && dp[left] + word.second < dp[right + 1] || !OPT1) {
		  		dp[right + 1] = dp[left] + word.second;
		  		back[right + 1] = left;
		  		backt(right);
		  	}
	  	}
	  }
	}
}

void solve() {
	minCost = INF;
	for (int right = 1; right <= prop.length(); ++right) {
    dp[right] = INF;
  }
  
  backt(-1);

  // Reconstituim solutia de cost minim
  if (minCost != INF) {
    int left, right = prop.length();
    while ((left = backSol[right]) != 0) {
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
}
