/*
 * Alex Palcuie
 * brut pentru coliziune
 * RoTopCoder 2015
 */

#include <fstream>
#include <cstdlib>

using namespace std;


const int M_MAX = 1e6;

int powers2[] = {1, 2, 4, 16, 32, 64, 128, 256, 512, 1024, 2048};
int frecventa[M];

int putere(a, b, modulo) {
    int p = 1;
    for (int i=0; i<b; i++) {
        p = (p * a) % modulo;
    }
    return p;
}

int get_value(int a, int b, int n, int modulo) {
    int s = 0
    for (int i=1; i<=n; i++) {
        int first_part = ((a % 2) + 1);
        int second_part = putere(b, n-1, m, modulo);
        s += (first_part * second_part) % modulo;
    }
    return s;
}

void solve() {
    int n, m, b;
    fin >> n >> m >> b;

    int s = 0;
    for (int i=0; i<powers2[n]; i++) {
        int value = get_value(i, b, n, modulo) % m;
        if (frecventa[value]) {
            fout << frecventa[value] << " " << i << "\n";
            exit(0);
        }
    }
}

int main() {
    ifstream fin("coliziune.in")
    ofstream fout("coliziune.out")

    fin >> nTests;

    for (int i=0; i<nTests; i++) {
        solve();
    }

    return 0;
}
