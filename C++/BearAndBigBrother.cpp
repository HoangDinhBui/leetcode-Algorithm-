#include <iostream>

using namespace std;

class BearAndBigBrother{
    private:
        int LimarkW;
        int BobW;
    public:
        BearAndBigBrother(int LimarkW, int BobW){
            this->LimarkW = LimarkW;
            this->BobW = BobW;
        }
        int YearToGrown();
};

int BearAndBigBrother::YearToGrown(){
    int count = 0;
    while(LimarkW <= BobW){
        count++;
        LimarkW*=3;
        BobW*=2;
    }
    return count;
}

int main(){
    int LimarkW, BobW;
    cin >> LimarkW >> BobW;
    BearAndBigBrother BAB(LimarkW, BobW);
    cout << BAB.YearToGrown();
}