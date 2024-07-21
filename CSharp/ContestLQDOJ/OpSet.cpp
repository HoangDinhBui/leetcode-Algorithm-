//#pragma GCC optimize("02")
//#pragma GCC tarrget("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define REP(i,n) for (int i=0;i<n;i++)
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __Anh_Tran__ signed main()
#define file(name) if (fopen(name".inp","r")){freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define MAX 10001000

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y; return true;
        } else return false;
    }
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y; return true;
        } else return false;
    }

const int MAX_N = 1e5 + 5;
const int MOD = (int)1e9 + 7;
const ll INF = 1e9;
//const ld EPS = 1e-9;
int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
int sub(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}

int n,k,d, Hoang[MAX], Diep[MAX], sum[MAX], limit[MAX];
bool removed[MAX];

void input(void){
	scanf("%d%d%d", &n,&k,&d);
	REP(i,k){
		int x;
		scanf("%d",&x); removed[x]=true;
	}
}
void process(void){
    int maxTri= 0,j=0;
    FOR(i,1,n){
        if(removed[i]){
            Hoang[i] =-1; 
            continue;
        }
        while(j<i-d-1) 
            maximize(maxTri, Hoang[++j]);
        Hoang[i] = maxTri +1; 
        maximize(limit[Hoang[i]],i);
    }
    FOR(i,1,n) maximize(maxTri,Hoang[i]);
    FOR(i,1,n){
        if(removed[i]) Diep[i] =0;
        else{
            if(Hoang[i] ==1) Diep[i] =1;
            else{
                int A = limit[Hoang[i]-2] +1, Bien = limit[Hoang[i]-1];
                minimize(Bien,i-d-1);
                Diep[i] = sub(sum[Bien], sum[A-1]);
            }
        }
        sum[i] =add(sum[i-1], Diep[i]);
    }
    int ans =0;
    FOR(i,1,n) if(Hoang[i] == maxTri) ans = add(ans, Diep[i]);
    cout<<maxTri<<"\n"<<ans<<endl;
}
void solve() {
    input();
    process();
}

__Anh_Tran__{
    faster
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        
        solve();
    }
    
    return 0;
}