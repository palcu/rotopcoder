#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

#define PROP_LEN 24
#define WORD_LEN 6
#define SAME_LET_PROB 3
#define MIN_LEVELS 2
#define MAX_LEVELS 5
#define MAX_NR_WORDS 40
#define RAND_WORDS_PERC 5

string prop;
int n;
vector <pair <string, int> > dict;
set <string> wordsSet;

void write() {
    string fileName = "descompune_" + to_string(PROP_LEN) + ".in";
    ofstream fout(fileName);
    fout << prop << "\n" << dict.size() << "\n";
    for (auto &word : dict) {
        fout << word.first << " " << word.second << "\n";
    }
}

void addWord(string &word, int cost) {
    if (dict.size() < MAX_NR_WORDS && wordsSet.find(word) == wordsSet.end()) {
        dict.push_back(make_pair(word, cost));
        wordsSet.insert(word);
    }
}

int genCost(int left, int right) {
    return 1 + rand() % ((right - left + 1) * 19);
}

void genWords1(int howMany, int left, int right) {
    for (int count = 0; count < howMany; ++count) {
        int l = left + rand() % (right - left + 1);
        int aproxLength = 1 + rand() % min(WORD_LEN, right - left + 1);
        int length = min(aproxLength, right - l + 1);
        int r = l + length - 1;
        
        string word = prop.substr(l, r - l + 1);
        int cost = genCost(l, r);
        addWord(word, cost);
    }
}

void genWords2(int left, int right) {
    if (right - left <= 1) {
        return;
    }
    
    // Generate random words
    genWords1((right - left) * RAND_WORDS_PERC / 100, left, right);
    
    // Generate levels of words between left and right
    vector <pair<int, int> > indexes;
    set <int> indexHash;
    int levels = MIN_LEVELS + rand() % (MAX_LEVELS - MIN_LEVELS + 1);
    for (int i = 0; i < levels; ++i) {
        int l = left, r;
        do {
            int aproxLength = 1 + rand() % min(WORD_LEN, right - left + 1);
            int length = min(aproxLength, right - l + 1);
            r = l + length - 1;
            
            string word = prop.substr(l, r - l + 1);
            int cost = genCost(l, r);
            addWord(word, cost);
            
            if (l != left && r != right && indexHash.find(l * 1001 + r) == indexHash.end()) {
                indexes.push_back(make_pair(l, r));
                indexHash.insert(l * 1001 + r);
            }
            
            l = r + 1;
        } while (r < right);
    }
    
    for (auto &index : indexes) {
        genWords2(index.first, index.second);
    }
}

void genTest() {
    srand((unsigned)time(0));
    for (int i = 0; i < PROP_LEN; ++i) {
        if (i > 0 && (rand() % 101 <= SAME_LET_PROB)) {
            prop.push_back(prop[i - 1]);
        } else {
            prop.push_back('a' + rand() % ('z' - 'a'));
        }
    }
    
    genWords2(0, PROP_LEN - 1);

    // Fill in with random words until required number is met.
    genWords1(MAX_NR_WORDS - dict.size(), 0, PROP_LEN - 1);
    
    random_shuffle(dict.begin(), dict.end());
}

int main() {
    genTest();
    write();
}
