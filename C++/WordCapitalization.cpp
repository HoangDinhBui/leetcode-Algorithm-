#include <iostream>
#include <string>

using namespace std;

class WordCapitalization
{
    private:
        string A;
    public:
        WordCapitalization(string s){
            A = s;
        }
        string WCapitalization();
};

string WordCapitalization :: WCapitalization(){
    if(A[0] >= 'a' && A[0] <= 'z'){
        A[0] -= 32; 
    }
    return A;
}

int main(){
    string s;
    cin >> s;
    WordCapitalization wc(s);
    string result = wc.WCapitalization();
    cout << result << endl;
}