#include <iostream>
using namespace std;
 
void result() {
    int n, k, A[1000], res = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if(A[k - 1] > 0) {
        for(int i = 0; i < n; i++) {
            if(A[i] >= A[k - 1] && A[i] > 0) {
                res++;
            } else {
                break;
            }
        }
    }
    else if(A[k - 1] == 0)
    {
    	for(int i = 0; i < k; i++)
    	{
    		if(A[i] > 0)
    			res++;
    	}
    }
    cout << res << endl;
}
 
int main() {
    result();
    return 0;
}