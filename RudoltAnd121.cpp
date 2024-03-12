#include <iostream>

using namespace std;

void makeZero(int A[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (A[i] > 0) {
            int reduction = min(A[i], min(A[i - 1], A[i + 1]));
            A[i - 1] -= reduction;
            A[i] -= reduction * 2;
            A[i + 1] -= reduction;
        }
    }
}

bool allZero(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        int A[200000];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        makeZero(A, n);
        if (allZero(A, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
