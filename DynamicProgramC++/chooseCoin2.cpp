#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n, S;
    cin >> n >> S;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    vector<int> dp(S + 1, 0);
    dp[0] = 1; // Có 1 cách để tạo ra tổng bằng 0 là không chọn đồng xu nào

    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= S; j++) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    
    cout << dp[S] << endl;
    return 0;
}
