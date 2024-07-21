#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

const int MOD = 1e9 + 7;

using namespace std;

vector<int> S;
int n, k, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> d;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    set<int> elements;
    for (int i = 1; i <= n; ++i) {
        elements.insert(i);
    }
    for (int x : a) {
        elements.erase(x);
    }

    S.assign(elements.begin(), elements.end());
    sort(S.begin(), S.end());

    vector<int> dp(S.size(), 1);
    vector<int> count(S.size(), 1);

    int max_length = 1;
    for (int i = 1; i < S.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (S[i] - S[j] > d) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1) {
                    count[i] = (count[i] + count[j]) % MOD;
                }
            }
        }
        max_length = max(max_length, dp[i]);
    }

    int number_of_ways = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (dp[i] == max_length) {
            number_of_ways = (number_of_ways + count[i]) % MOD;
        }
    }

    cout << max_length << endl;
    cout << number_of_ways << endl;

    return 0;
}
