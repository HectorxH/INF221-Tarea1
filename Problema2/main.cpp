#include <iostream>
#include <vector>
#include <sstream> 

using namespace std;

typedef vector<int> vi;
typedef vector<string> graph;
typedef vector<vi> vvi;

int dfs(int i, int j, graph& G, vvi& visited, int id) {
    int n = G.size();
    int m = G[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (visited[i][j] != -1) return 0;
    if (G[i][j] == 'L') return 0;

    int sum = 1;
    visited[i][j] = id;
    for (int off_i = -1; off_i < 2; off_i++) {
        for (int off_j = -1; off_j < 2; off_j++) {
            sum += dfs(i + off_i, j + off_j, G, visited, id);
        }
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    string str;
    getline(cin, str);
    cin.ignore();
    while (T--) {
        graph G;
        vvi visited;
        vi tamanios;
        int id = 0;
        while (getline(cin, str)) {
            if (str[0] != 'W' && str[0] != 'L') break;
            G.push_back(str);
            visited.push_back(vi(str.size(), -1));
        }
        int i, j;
        while (true) {
            stringstream stream(str);
            stream >> i >> j;
            i--;
            j--;
            if (visited[i][j] == -1) {
                int tamanio = dfs(i, j, G, visited, id++);
                tamanios.push_back(tamanio);
                cout << tamanio << endl;
            }
            else {
                cout << tamanios[visited[i][j]] << endl;
            }
            if (cin.eof()) return 0;
            getline(cin, str);
            if (str.empty()) break;
        }
        cout << endl;
    }

    return 0;
}