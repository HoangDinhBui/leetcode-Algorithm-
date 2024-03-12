#include <iostream>
#include <stdio.h>

using namespace std;

void NhapMang(int *p, int &n){
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
}

void XuatMang(int *p, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", p[i]);
    }
}

void DemCap(int *p, int n){
    int cnt = 0, d = 0;
    for(int i = 0; i < n; i++){
        if(*(p+i) == *(p+i+1)){
            cnt++;
            d++;
        }
        else if(cnt != 0){
            printf("Gia tri %d co %d cap bang nhau.\n", *(p+i), cnt);
            cnt = 0;
        }
    }
}
int main(){
    int n, *pa;
    printf("Nhap so ptu n: ");
    scanf("%d", &n);
    pa = (int*)calloc(n, sizeof(int));
    NhapMang(pa, n); 
    DemCap(pa, n);
    XuatMang(pa, n);
    free(pa);
}