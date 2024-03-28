#include <iostream>

using namespace std;

class StairPeakNeither{
    private:
        int a, b, c;
    public:
        StairPeakNeither(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void result();
};

void StairPeakNeither::result(){
    if(a < b && b < c)
        cout << "STAIR" << endl;
    else if(a < b && b > c)
        cout << "PEAK" << endl;
    else    
        cout << "NONE" << endl;
}

int main(){
    int t;
    cin >> t;
    int a, b, c;
    while(t--){
        cin >> a >> b >> c;
        StairPeakNeither s(a, b, c);
        s.result();
    }
    return 0;
}