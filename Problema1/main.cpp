#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

typedef vector<int> vi;

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

        for (vi subset : answer) {
            int size = subset.size();
            for (int i = 0; i < size - 1; i++) {
                cout << subset[i] << "+";
            }
            cout << subset[size - 1] << endl;
        }
        if (answer.size() == 0) {
            cout << "NADA" << endl;
        }
    }

    return 0;
}