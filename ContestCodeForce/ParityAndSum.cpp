#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    
    for (long long i = 0; i < n; i++) 
        cin >> a[i];

    long long largestOdd = LLONG_MIN; // số lẻ lớn nhất
    long long largestEven = LLONG_MIN; // số chẵn lớn nhất

    // Tìm số lẻ lớn nhất và số chẵn lớn nhất
    for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] > largestOdd)
            largestOdd = a[i];
        if (a[i] % 2 == 0 && a[i] > largestEven)
            largestEven = a[i];
    }

    bool allSameParity = true;
    for (long long i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            allSameParity = false;
            break;
        }
    }

    if (allSameParity) {
        cout << 0 << "\n";
        return;
    }

    // Thay đổi tất cả số chẵn nhỏ hơn số lẻ lớn nhất
    sort(a.begin(), a.end());
    int operations = 0;
    for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] < largestOdd) {
            operations++;
            a[i] += largestOdd;
            largestOdd = max(largestOdd, a[i]);
        }
    }

    allSameParity = true;
    for (long long i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            allSameParity = false;
            break;
        }
    }

    if (allSameParity) {
        cout << operations << "\n";
        return;
    }

    // Thay đổi số lẻ lớn nhất bằng cách cộng số lẻ lớn nhất với số chẵn lớn nhất
    long long index = 0;
    for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] == largestOdd) {
            index = i;
            break;
        }
    }

    a[index] += largestEven;
    operations++;

    for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            operations++;
        }
    }

    cout << operations << "\n";
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
