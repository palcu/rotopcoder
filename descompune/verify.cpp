#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <assert.h>

using namespace std;

string prop;
int n;
map<string, int> dict;
int costOk;

void read() {
  string cuv;
  int cost;
  ifstream fin("descompune.in");
  assert(fin >> prop);
  assert(fin >> n);

  assert(1 <= n && n <= 10000);
  for (int i = 0; i < n; ++i) {
    assert(fin >> cuv >> cost);
    dict[cuv] = cost;

    assert(1 <= cuv.length() && cuv.length() <= 50);
    assert(1 <= cost && cost <= 1000);
  }

  // Read cost
  ifstream fok("descompune.ok");
  fok >> costOk;
  assert(1 <= costOk);
}

void writeScore(int score, string msg) {
  cout << score << " " << msg;
  exit(0);
}

int main() {
// #ifndef ONLINE_JUDGE
  ifstream fout("descompune.out");
// #endif

  read();

  vector<string> userWords;
  string word;
  string userProp;
  int userCostDetermined = 0;

  // Citeste inputul concurentului
  while(fout >> word) {
    userWords.push_back(word);
  }
  
  for (int i = 0; i < (int)userWords.size() - 1; ++i) {
    userProp.append(userWords[i]);
    map<string, int>::iterator it = dict.find(userWords[i]);
    // Verifica daca fiecare cuvant exista in dictionarul din input
    if (it == dict.end()) {
      writeScore(0, "Cuvant inexistent: " + userWords[i]);
    }
    userCostDetermined += it->second;
  }

  // Verifica daca exista macar un cuvant si un cost
  if (userWords.size() == 0) {
    writeScore(0, "Fisier gol");
  } else if (userWords.size() == 1) {
    writeScore(0, "Lipsa scor sau descompunere");
  }
  return 0;
  // Verifica daca costul exista in fisierul de iesire
  int userCost = atoi((*userWords.rbegin()).c_str());
  if (userCost == 0) {
    writeScore(0, "Cost lipsa sau 0");
  }

  // Verifica daca propozitia concurentului e identica cu prop din input
  if (userProp != prop) {
    writeScore(0, "Descompunere gresita");
  }

  // Verifica daca suma costurilor cuvintelor din dictionar este egala cu suma afisata
  if (userCostDetermined != userCost) {
    writeScore(0, "Costul final si costul propozitiei nu coincid");
  }

  if (userCost == costOk) {
    writeScore(5, "URA!");
  } else {
    writeScore(0, "Cost minim gresit");
  }

  return 0;
}