#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <tuple>

using namespace std;

const int MOD = 1000000007;

tuple<int, int> getOptimal(vector<int>& sample, int d) {
    int n = sample.size();
    vector<int> dp(n, 1);
    vector<int> countWay(n, 1);

    map<int, pair<int, int>> dpMap; // key: value, value: pair<maxLength, countWay>

    int maxLength = 1;
    int numberOfWays = 1;

    for (int i = 0; i < n; ++i) {
        // Iterate over the map to find elements which are not in range [sample[i] - d, sample[i] + d]
        auto it = dpMap.begin();
        while (it != dpMap.end()) {
            if (abs(it->first - sample[i]) > d) {
                if (it->second.first + 1 > dp[i]) {
                    dp[i] = it->second.first + 1;
                    countWay[i] = it->second.second;
                } else if (it->second.first + 1 == dp[i]) {
                    countWay[i] = (countWay[i] + it->second.second) % MOD;
                }
                ++it;
            } else {
                break;
            }
        }

        if (dp[i] > maxLength) {
            maxLength = dp[i];
            numberOfWays = countWay[i];
        } else if (dp[i] == maxLength) {
            numberOfWays = (numberOfWays + countWay[i]) % MOD;
        }

        dpMap[sample[i]] = {dp[i], countWay[i]};
    }

    return make_tuple(maxLength, numberOfWays);
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    unordered_set<int> kHash;
    for (int i = 0; i < k; i++) {
        int value;
        cin >> value;
        kHash.insert(value);
    }

    vector<int> sample;
    for (int i = 1; i <= n; i++) {
        if (kHash.find(i) == kHash.end())
            sample.push_back(i);
    }

    auto result = getOptimal(sample, d);
    int maxLength = get<0>(result);
    int countWay = get<1>(result) % 200000;

    cout << maxLength << endl;
    cout << countWay << endl;

    return 0;
}
