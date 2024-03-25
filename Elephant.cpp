#include <iostream>

using namespace std;

class Elephant {
private:
    int x;
    int numOfStep;
public:
    Elephant(int x) {
        this->x = x;
        this->numOfStep = 0;
    }
    
    int countStep();
};

int Elephant::countStep() {
    int tmp = 0;
    if (x <= 5) {
        return 1;
    }
    while (tmp < x) {
        numOfStep++;
        tmp += 5;
    }
    return numOfStep;
}

int main() {
    int x;
    cin >> x;
    Elephant e(x);
    cout << e.countStep() << endl;
    return 0;
}
