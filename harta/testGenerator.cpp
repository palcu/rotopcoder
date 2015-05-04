#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <queue>

#include <cstring>

using namespace std;


string hashToCard(const int& hash) {
    const string ranks = "23456789tjqka";
    const string suits = "cdhs";
    string ret = "  ";
    ret[0] = ranks[hash % 13];
    ret[1] = suits[hash / 13];
    return ret;
}

int cardHash(const string& card, const string& ranks, const string& suits) {
    return (strchr(ranks.c_str(),card[0]) - ranks.c_str()) +
    (strchr(suits.c_str(),card[1]) - suits.c_str()) * 13;
}

int bfs(pair<int,int> s, pair<int,int> d, 
    const vector< vector<int> >& world, 
    const vector<int>& badCards) {
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    const int N = static_cast<int>(world.size());
    const int M = static_cast<int>(world[0].size());
    vector<bool> allowed(52, true);
    vector<int> suit(52);
    for (int i = 0; i < 52; i++) {
        suit[i] = i / 13;
    }

    for (const int& card : badCards) {
        allowed[card] = false;
    }
    
    if (allowed[world[s.first][s.second]] == false) {
        return -1;
    }
    
    vector< vector< vector<int> > > dist(N, 
            vector< vector<int> >(M, vector<int>(16, -1)));
    queue< tuple<int, int, int> > Q;
    Q.push(make_tuple(s.first, s.second, 
                1 << (suit[world[s.first][s.second]])));
    dist[s.first][s.second][1 << suit[world[s.first][s.second]]] = 0; 
    

    int x, y, w, z, state, nextState;
    while (!Q.empty()) {
        tie(x, y, state) = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            w = x + dx[k];
            z = y + dy[k];
            if (w == N) w = 0;
            if (w == -1) w = N - 1;
            if (z == M) z = 0;
            if (z == -1) z = M - 1;
            nextState = state | 1 << (suit[world[w][z]]);
            if (allowed[world[w][z]] && dist[w][z][nextState] == -1) {
                dist[w][z][nextState] = dist[x][y][state] + 1;
                Q.push(make_tuple(w, z, nextState));
            }
        }
    }

    return dist[d.first][d.second][15];
}

int solve(int N, int M, int K, pair<int,int> source, pair<int,int> destination,
            vector< vector<string> >& A, vector<string>& B) {
    const string ranks = "23456789tjqka";
    const string suits = "cdhs";
    vector< vector<int> > world(N, vector<int>(M));
    vector<int> badCards(K);
    for (int i = 0; i < K; i++) {
        badCards[i] = cardHash(B[i], ranks, suits);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            world[i][j] = cardHash(A[i][j], ranks, suits);
        }
    }
    source.first--, source.second--;
    destination.first--, destination.second--;
    return bfs(source, destination, world, badCards);
}

void printTest(int N, int M, int K, pair<int,int> source, pair<int,int> destination,
            vector< vector<string> >& A, vector<string>& B, ostream& out) {

    out << N << " " << M << " " << K << "\n";
    for (int i = 0; i < K; i++) {
        out << B[i] << " ";
    }
    out << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << A[i][j] << " ";
        }
        out << "\n";
    }

    out << source.first << " " << source.second << "\n";
    out << destination.first << " " << destination.second << "\n";
}

void generate() {
    ofstream out("tests.txt");
    std::random_device rd;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(1, 10000);
    int t = 100;
    out << t << "\n";
    for (int i = 1; i <= t; i++) {
        int N, M, K;
        pair<int,int> src, dest;
        N = 1000;
        M = 1000;
        K = dist(mt) % 52 + 1;
        vector<int> cards(52);
        for (int j = 0; j < 52; j++) {
            cards[j] = j;
        }
        shuffle(begin(cards), end(cards), mt);
        vector< string > B(K);
        vector< vector<string> > A(N, vector<string>(M));
        for (int j = 0; j < K; j++) {
            B[j] = hashToCard(cards[j]);
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
               A[j][k] = hashToCard(dist(mt) % 52); 
            }
        }
        src = make_pair(dist(mt) % N + 1, dist(mt) % M + 1);
        dest = make_pair(dist(mt) % N + 1, dist(mt) % M + 1); 
        int ans = solve(N, M, K, src, dest, A, B);
        cout << "Test Case # " << i << " : " << ans << "\n";
        //printTest(N, M, K, src, dest, A, B, out);
    }
}

int main() {
    generate();
    return 0;
}
