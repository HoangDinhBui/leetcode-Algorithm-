#include <iostream>

using namespace std;

class YoungPhysicist{
    private:
        int n;
        int **A;
    public:
        YoungPhysicist(int n, int **A):n(n), A(new int*[n]){
            for(int i = 0; i < n; i++){
                this->A[i] = new int[3];
                for(int j = 0; j < 3; j++)
                    this->A[i][j] = A[i][j];
            }
        }
        ~YoungPhysicist(){
        if(A != nullptr){
            for(int i = 0; i < n; i++)
                delete[] A[i];
            delete[] A;
            }
        }

        void checkTask();
};

void YoungPhysicist :: checkTask(){
    int totalX = 0;
    int totalY = 0;
    int totalZ = 0;
    for(int i = 0; i < n; i++){
        totalX += A[i][0];
        totalY += A[i][1];
        totalZ += A[i][2];
    }
    if(totalX == 0 && totalY == 0 && totalZ == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    int n;
    cin >> n;
    int **A = new int *[n];
    for(int i = 0; i < n; i++){
        A[i] = new int[3];
        for(int j = 0; j < 3; j++)
            cin >> A[i][j];     
    }
    YoungPhysicist y(n, A);
    y.checkTask();

    for(int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}