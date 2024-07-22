#include <iostream>
using namespace std;

typedef long long ll;

void sol() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll resw = 0, resl = 0, rest = n * n;

    ll run = 1, type = 1;
    while (run <= n) {
        ll x = n / run;
        ll y = (x + 1) / 2;
        ll ret = y * y;

        if (!type) {
            ret = (n / run) * (n / run) - (n / (run + run)) * (n / (run + run));
        }

        if (type) resl += ret;
        else resw += ret;
        rest -= ret;

        run += run;
        type = 1 - type;
    }

    cout << resw << endl;
    cout << rest << endl;
    cout << resl << endl;
}

int main() {
    sol();
    return 0;
}
