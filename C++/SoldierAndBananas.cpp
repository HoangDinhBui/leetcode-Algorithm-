#include <iostream>

using namespace std;

class SoldierAndBanana{
    private:
        int k, n, w;
    public:
        SoldierAndBanana(int k, int n, int w){
            this->k = k;
            this->n = n;
            this->w = w;
        }
        void cash();
};
void SoldierAndBanana::cash(){
    int cashMustPay = 0;
    for(int i = 1; i <= w; i++){
        cashMustPay += k*i;
    }
    int borrow = cashMustPay - n;
    cout << max(0, borrow);
}

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    SoldierAndBanana s(k, n, w);
    s.cash();
}