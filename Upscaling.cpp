#include <iostream>
#include <math.h>

using namespace std;

class Upscaling{
    private:
        int n;
        char **A;
    public:
        Upscaling(int n, char **A):n(n), A(new char*[2*n]){
            for(int i = 0; i < 2*n; i++){
                this->A[i] = new char[2*n];
            }
        }
        ~Upscaling(){
        if(A != nullptr){
            for(int i = 0; i < n; i++)
                delete[] A[i];
            delete[] A;
            }
        }
        void result();
        void printResult();
};

void Upscaling::result(){
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if ((i / 2 + j / 2) % 2 == 0) {
                A[i][j] = '#';
            } else {
                A[i][j] = '.';
            }
        }
    }
}

void Upscaling::printResult() {
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }
    }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char **arr = new char *[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            arr[i] = new char[2 * n];
        }

        Upscaling u(n, arr);
        u.result();
        u.printResult();

        for (int i = 0; i < 2 * n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}