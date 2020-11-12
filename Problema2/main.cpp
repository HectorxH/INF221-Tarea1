#include <iostream>
#include <vector>
#include <sstream> 
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<string> graph;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef queue<ii> qii;

/*
 * Function: dfs
 * ----------------------------
 *   Hace el recorrido DFS (en profundidad) sobre el grafo.
 *
 *   int i - posición de la celda en el eje x.
 *   int j - posición de la celda en el eje y.
 *   graph& G - el grafo que representa el problema.
 *   vvi& visited - vector de vectores que marca las casillas ya visitadas.
 *   int id - id de la laguna.
 *
 *   Returns: int, tamaño de la laguna.
 */
int dfs(int i, int j, graph& G, vvi& visited, int id) {
    int n = G.size();
    int m = G[0].size();

    int sum = 0;

    qii q;
    q.push(ii(i, j));


    while (!q.empty()) {
        ii curr = q.front();
        q.pop();

        i = curr.first;
        j = curr.second;

        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (visited[i][j] != -1) continue;
        if (G[i][j] == 'L') continue;

        visited[i][j] = id;
        sum++;

        // Revisa todos las celdas adyacentes.
        for (int off_i = -1; off_i < 2; off_i++) {
            for (int off_j = -1; off_j < 2; off_j++) {
                q.push(ii(i + off_i, j + off_j));
            }
        }
    }
    return sum;
}

int main() {
    // Lectura de cantidad de casos.
    int T;
    cin >> T;

    string str;
    // El primer ignore ignora el "\n"
    cin.ignore();
    // El segundo ignore ignora la linea en blanco.
    cin.ignore();
    while (T--) {
        graph G;
        vvi visited;
        vi sizes;
        int id = 0;
        // Lee la matriz y la guarda en forma de grafo.
        // Además iniciliza la lista de visitados.
        while (getline(cin, str)) {
            if (str[0] != 'W' && str[0] != 'L') break;
            G.push_back(str);
            visited.push_back(vi(str.size(), -1));
        }

        int i, j;
        while (true) {
            stringstream stream(str);
            stream >> i >> j;
            // Las filas y las columnas se enumeran desde 1 pero.
            // en el código se trabajan desde 0, por lo que se resta 1.
            i--;
            j--;
            // Si la celda no está visitada, se calcula el tamaño de la laguna.
            if (visited[i][j] == -1) {
                int size = dfs(i, j, G, visited, id++);
                sizes.push_back(size);
                cout << size << endl;
            }
            // Si no, se lee desde sizes que guarda los tamaños calculados.
            else {
                cout << sizes[visited[i][j]] << endl;
            }
            // Si se termina de leer el input, se retorna.
            // PD: nos perd0nan uwu.
            if (cin.eof()) return 0;
            getline(cin, str);
            if (str.empty()) break;
        }

        cout << endl;
    }

    return 0;
}