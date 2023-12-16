#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> protein(n);
    for (int i = 0; i < n; i++) {
        cin >> protein[i];
    }

    vector<int> result(n, 1);

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && protein[i] >= protein[j]) {
            j -= result[j];
        }
        result[i] = i - j;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}