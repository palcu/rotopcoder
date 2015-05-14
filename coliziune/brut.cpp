/*
 * Alex Palcuie
 * brut pentru coliziune
 * RoTopCoder 2015
 */

#include <fstream>
#include <cstdlib>

using namespace std;


const int M_MAX = 1e6;
ifstream fin("coliziune.in");
ofstream fout("coliziune.out");

int powers2[] = {1, 2, 4, 16, 32, 64, 128, 256, 512, 1024, 2048};
int frecventa[M_MAX];

int putere(int a, int b, int modulo) {
    int p = 1;
    for (int i=0; i<b; i++) {
        p = (p * a) % modulo;
    }
    return p;
}

int get_value(int a, int b, int n, int modulo) {
    int s = 0;
    for (int i=1; i<=n; i++) {
        int first_part = ((a % 2) + 1);
        int second_part = putere(b, n-i, modulo);
        s += (first_part * second_part) % modulo;
        a /= 2;
    }
    return s;
}

void solve() {
    int m, b;
    fin >> m >> b;
    int n = 10;

    for (int i=0; i<powers2[n]; i++) {
        int value = get_value(i, b, n, m) % m;
        if (frecventa[value]) {
            fout << frecventa[value] << " " << i << "\n";
            exit(0);
        }
    }
}

int main() {
    int nTests = 1;

    for (int i=0; i<nTests; i++) {
        solve();
    }

    return 0;
}
