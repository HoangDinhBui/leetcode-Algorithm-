#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int MOD = 1e9 + 7;

using namespace std;

// Function to count the number of optimal subsets
pair<int, int> count_optimal_subsets(int n, int k, int d, const vector<int>& a) {
    set<int> elements;
    // Initialize the set with elements from 1 to n
    for (int i = 1; i <= n; ++i) {
        elements.insert(i);
    }
    // Remove the elements given in array a
    for (int x : a) {
        elements.erase(x);
    }

    // Convert set to sorted vector
    vector<int> S(elements.begin(), elements.end());
    
    // Step 3: Apply greedy algorithm to find the maximum subset
    vector<int> chosen;
    int last_chosen = -1e9;  // Very small number

    for (int number : S) {
        if (number > last_chosen + d) {
            chosen.push_back(number);
            last_chosen = number;
        }
    }

    int max_length = chosen.size();

    // Step 4: Count number of ways using dynamic programming
    vector<int> dp(max_length + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < S.size(); ++i) {
        for (int j = max_length; j > 0; --j) {
            if (j > 0 && (j == 1 || S[i] - chosen[j-2] > d)) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
    }

    return {max_length, dp[max_length]};
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    // Calculate and print the results
    auto result = count_optimal_subsets(n, k, d, a);
    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}
