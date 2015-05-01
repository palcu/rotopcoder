/*
 * Alex Palcuie
 * telina
 * RoTopCoder 2015
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;


const int M_MAX = 1e6;
ifstream fin("telina.in");
ofstream fout("telina.out");

int powers2[] = {1, 2, 4, 16, 32, 64, 128, 256, 512, 1024, 2048};
int frecventa[M_MAX];

int main() {
    string s;
    deque<char> sol;
    fin >> s;

    sol.push_back(s[s.size()-1]);
    for (int i=s.size()-2; i>=0; i--) {
        if (sol[0] > s[i]) {
            sol.push_front(s[i]);
        } else {
            sol.push_back(s[i]);
        }
    }

    for (deque<char>::iterator it = sol.begin(); it != sol.end(); it++)
        fout << *it;
    fout << "\n";

    return 0;
}
