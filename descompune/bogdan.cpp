/*
	Bogdan Tirca
	Problema Descompune
	Complexitate: O(PROP_LEN * WORD_LEN^2 * log(N))
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define INF (1 << 30)
#define PROP_LEN 1001
#define WORD_LEN 50

string prop;
int n;
map<string, int> dict;
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
		dict[cuv] = cost;
	}
}

void solve() {
	string word;
	map<string,int>::iterator it;
	for (int right = 0; right < prop.length(); ++right) {
		dp[right + 1] = INF;
		for (int left = max(0, right - WORD_LEN); left <= right; ++left) {
			word = prop.substr(left, right - left + 1);
			it = dict.find(word);
			if (it != dict.end() && dp[left] + it->second < dp[right + 1]) {
				dp[right + 1] = dp[left] + it->second;
				back[right + 1] = left;
			}
		}
		word.clear();
	}
	// Reconstituie solutia de cost minim
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

int main() {
	read();
	solve();
	write();
}
