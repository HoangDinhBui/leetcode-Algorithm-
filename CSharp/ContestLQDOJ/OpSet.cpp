#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, k, d;
vector<bool> removed;
vector<int> maxLength, ways, prefixSum, lastIndex;

void input() {
    cin >> n >> k >> d;
    removed.assign(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        removed[x] = true;
    }
}

void process() {
    int currentMax = 0, j = 0;
    maxLength.assign(n + 1, 0);
    ways.assign(n + 1, 0);
    prefixSum.assign(n + 1, 0);
    lastIndex.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (removed[i]) {
            maxLength[i] = -1;
            continue;
        }
        while (j < i - d - 1) 
            currentMax = max(currentMax, maxLength[++j]);
        maxLength[i] = currentMax + 1;
        lastIndex[maxLength[i]] = max(lastIndex[maxLength[i]], i);
    }
    
    currentMax = *max_element(maxLength.begin(), maxLength.end());
    for (int i = 1; i <= n; ++i) {
        if (removed[i]) {
            ways[i] = 0;
        } else {
            if (maxLength[i] == 1) {
                ways[i] = 1;
            } else {
                int start = lastIndex[maxLength[i] - 2] + 1;
                int end = lastIndex[maxLength[i] - 1];
                end = min(end, i - d - 1);
                ways[i] = (prefixSum[end] - prefixSum[start - 1] + MOD) % MOD;
            }
        }
        prefixSum[i] = (prefixSum[i - 1] + ways[i]) % MOD;
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxLength[i] == currentMax) {
            answer = (answer + ways[i]) % MOD;
        }
    }
    cout << currentMax << "\n" << answer << endl;
}

void solve() {
    input();
    process();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
