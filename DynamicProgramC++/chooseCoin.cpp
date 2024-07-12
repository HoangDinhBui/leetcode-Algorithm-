#include <iostream>

using namespace std;

int main() {
    int n, S;
    cin >> n >> S;
    int a[n];   
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int dp[S + 1];
    for(int i = 0; i < S + 1; i++)
        dp[i] = 0;
    dp[0] = 1; //Có 1 cách để tạo ra tổng số xu bằng 0
    for(int i = 0; i < n; i++) {
        for(int j = S; j >= a[i]; j--) {
            if(dp[j - a[i]] == 1)
                dp[j] = 1;
        }
    }
    cout << dp[S] << endl;
}