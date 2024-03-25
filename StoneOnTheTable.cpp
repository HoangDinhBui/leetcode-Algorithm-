#include <iostream>
#include <string>

using namespace std;

class Stone{
    private:
        int numOfStone;
        string stoneColor;
    public:
        Stone(int numOfStone, string stoneClor){
            this->numOfStone = numOfStone;
            this->stoneColor = stoneClor;
        }
        int countStone();
};
int Stone::countStone(){
    int count = 0;
    for(int i = 0; i < numOfStone-1; i++){
        if(stoneColor[i] == stoneColor[i+1]){
            count++;
        }
    }
    return count;
}
int main(){
    int numOfStone;
    cin >> numOfStone;
    string stoneColor;
    cin >> stoneColor;
    Stone s(numOfStone, stoneColor);
    cout << s.countStone() << endl;
}