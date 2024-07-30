#include <iostream>

using namespace std;

class Taxi{
    private:
        int numOfGr;
        int *numOfGrMem;
    public:
        Taxi(int numOfGr, int *numOfGrMem){
            this->numOfGr = numOfGr;
            this->numOfGrMem = new int[numOfGr];
        }
        friend istream & operator >> (istream &is, Taxi &t);
        int leastTaxi();
        ~Taxi(){
            delete[] numOfGrMem;
        }
};

istream & operator >> (istream &is, Taxi &t){
    for(int i = 0; i < t.numOfGr; i++){
        cin >> t.numOfGrMem[i];
    }
    return is;
}

int Taxi::leastTaxi(){
    int count[5] = {0}; 
    for(int i = 0; i < numOfGr; i++){
        count[numOfGrMem[i]]++;
    }
    int taxis = count[4]; 
    taxis += count[3];
    count[1] -= count[3];
    taxis += (count[2]) / 2;
    count[2] %= 2;
    if (count[2] == 1) {
        count[1] -= 2;
        taxis++;
    }
    if (count[1] > 0) {
        taxis += (count[1] + 3) / 4;
    }
    return taxis;
}


int main(){
    int numOfGr;
    cin >> numOfGr;
    int *numOfGrMem;
    Taxi t(numOfGr, numOfGrMem);
    cin >> t;
    cout << t.leastTaxi() << endl;
}