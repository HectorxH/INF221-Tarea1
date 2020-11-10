#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

typedef vector<int> vi;

/*
 * Function: subsetSum
 * ----------------------------
 *   Aplica backtracking para calcular el conjunto de las posibles soluciones 
 *   para las subset sum para la lista L.
 *
 *   int i - posición actual en el arreglo.
 *   vi& L - vector con los valores.
 *   int t - el entero que indica cuanto falta para llegar a suma deseada.
 *   vi& subset - la sub-solución actual.
 *   set<vi>& answer - conjunto de las soluciones.
 *
 *   Returns: void, no retorna nada.
 */
void subsetSum(int i, vi& L, int t, vi& subset, set<vi>& answer) {
    int size = L.size();
    if (t == 0) {
        answer.insert(subset);
        return;
    }
    if (i >= size || t < 0) return;

    subsetSum(i + 1, L, t, subset, answer);

    subset.push_back(L[i]);
    subsetSum(i + 1, L, t - L[i], subset, answer);
    subset.pop_back();
}


int main() {
    int t;
    int n;
    while (cin >> t >> n) {
        if (t == 0 && n == 0) break;
        cout << "Suma de " << t << ":" << endl;

        vi L(n);
        for (int i = 0; i < n; i++) cin >> L[i];

        vi subset;
        set<vi> answer;
        subsetSum(0, L, t, subset, answer);

        // Printea las soluciones.
        // El orden de print es al revés (comparado con el de PDF)
        // Se ha consultado con el ayudante (el Gabo uwu) sobre esto.
        for (vi subset : answer) {
            int size = subset.size();
            for (int i = 0; i < size - 1; i++) {
                cout << subset[i] << "+";
            }
            cout << subset[size - 1] << endl;
        }
        // Caso de NADA.
        if (answer.size() == 0) {
            cout << "NADA" << endl;
        }
    }

    return 0;
}