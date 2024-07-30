#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }

private:
    queue<int> q;
};

int main() {
    RecentCounter recentCounter;

    cout << recentCounter.ping(1) << endl;     // Trả về 1
    cout << recentCounter.ping(100) << endl;   // Trả về 2
    cout << recentCounter.ping(3001) << endl;  // Trả về 3
    cout << recentCounter.ping(3002) << endl;  // Trả về 3
    cout << recentCounter.ping(4001) << endl;  // Trả về 3

    return 0;
}
