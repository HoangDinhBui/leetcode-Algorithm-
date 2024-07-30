#include <iostream>
#include <string>

using namespace std;

class ClockConversion {
private:
    string time;

public:
    ClockConversion(const string& t) : time(t) {}

    void result() {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));

        if (hour == 0) {
            cout << "12:" << (minute < 10 ? "0" : "") << minute << " AM" << endl;
        } else if (hour < 12) {
            cout << time.substr(0, 5) << " AM" << endl;
        } else if (hour == 12) {
            cout << time.substr(0, 5) << " PM" << endl;
        } else {
            hour -= 12;
            cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << " PM" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        ClockConversion c(s);
        c.result();
    }

    return 0;
}