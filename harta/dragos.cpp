#include <bits/stdc++.h>

using namespace std;

struct State {
  int x_pos;
  int y_pos;

  set <char> col;

  State() {
    x_pos = y_pos = 0;
    col.clear();
  }
  State(int _x, int _y) {
    x_pos = _x;
    y_pos = _y;
    col.clear();
  }
  State(int _x, int _y, set<char> _col) {
    x_pos = _x;
    y_pos = _y;
    col = _col;
  }
  bool operator < (const State &other) const {
    if (x_pos == other.x_pos) {
      if (y_pos == other.y_pos) {
        return col.size() < other.col.size();
      } else {
        return y_pos < other.y_pos;
      }
    } else {
      return x_pos < other.x_pos;
    }
  }
};

vector <vector <string> > matrix;
vector <string> sp_cards;
char get_col(string x) {
  return *x.rbegin();
}
bool is_bad(pair <int, int> pos) {
  for (auto card: sp_cards) {
    if (card == matrix[pos.first][pos.second]) {
      return true;
    }
  }
  return false;
}
int main() {
  ifstream cin("harta.in");
  ofstream cout("harta.out");

  int N, M, K;
  cin >> N >> M >> K;
  matrix.assign(N, vector<string>(M));
  assert(1 <= N && N <= 1000);
  assert(1 <= M && M <= 1000);

  assert(1 <= K && K <= 52);

  sp_cards.assign(K, "");

  for (int i = 0; i < K; ++i) {
    cin >> sp_cards[i];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> matrix[i][j];
    }
  }

  pair <int, int> start_pos;
  cin >> start_pos.first >> start_pos.second;
  start_pos.first -= 1;
  start_pos.second -= 1;

  pair <int, int> end_pos;
  cin >> end_pos.first >> end_pos.second;

  end_pos.first -= 1;
  end_pos.second -= 1;

  queue <State> Q;
  if (is_bad(start_pos)) {
    cout << -1;
    return 0;
  }
  if (is_bad(end_pos)) {
    cout << -1;
    return 0;
  }

  State start(start_pos.first, start_pos.second);
  start.col.insert(get_col(matrix[start_pos.first][start_pos.second]));

  Q.push(start);
  map <State, int> visited;
  visited[start] = 1;

  vector <int> dx{-1, 0, 0, 1};
  vector <int> dy{0, -1, 1, 0};
  while(!Q.empty()) {
    auto qf = Q.front();
    Q.pop();

    int state_time = visited[qf];

    if (end_pos.first == qf.x_pos) {
      if (end_pos.second == qf.y_pos) {
        if (qf.col.size() == 4) {
          cout << state_time - 1;
          return 0;
        }
      }
    }
    for (int i = 0; i < 4; ++i) {
      int xd = dx[i] + qf.x_pos;
      int yd = dy[i] + qf.y_pos;

      xd = (xd + N) % N;
      yd = (yd + M) % M;

      if (is_bad(make_pair(xd, yd))) {
        continue;
      }
      auto newSet = qf.col;
      newSet.insert(get_col(matrix[xd][yd]));

      State newState(xd, yd, newSet);
      if (visited.find(newState) == visited.end()) {
        visited[newState] = state_time + 1;
        Q.push(newState);
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
