#include <iostream>
 
using namespace std;
 
unsigned long long a[100];
 
void fibonacci() {
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= 93; i++) {
        a[i] = a[i-1] + a[i-2];
    }
}
 
int main() {
    fibonacci();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
 
    return 0;
}