#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <tuple>
#include <queue>

#include <cstring>

using namespace std;

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

int main() {
    ifstream cin("harta.in");
    ofstream cout("harta.out");
    int N, M, K;
    const string ranks = "23456789tjqka";
    const string suits = "cdhs";
    pair<int,int> source, destination;
    cin >> N >> M >> K;
    cin.get();
    vector< vector<int> > world(N, vector<int>(M));
    vector<int> badCards(K);
    string card;
    for (int i = 0; i < K; i++) {
        cin >> card;
        badCards[i] = cardHash(card, ranks, suits);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> card;
            world[i][j] = cardHash(card, ranks, suits);
        }
    }
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    source.first--, source.second--;
    destination.first--, destination.second--;
    cout << bfs(source, destination, world, badCards);
    return 0;
}
