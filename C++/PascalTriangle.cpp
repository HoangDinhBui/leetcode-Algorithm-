#include <iostream>

using namespace std;

int main() 
{
    int n;
    cout << "Nhap so hang cua tam giac Pascal: ";
    cin >> n;
    int a[n][n+1];

    // Gan gia tri 1 cho cac phan tu o canh trai
    for (int i = 0; i < n; i++) 
    {
        a[i][0] = 1;
    }

    // Tinh toan va gan gia tri cho cac phan tu con lai
    for (int i = 1; i < n; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    // In tam giac Pascal ra man hinh
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
