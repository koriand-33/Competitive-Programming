#include <bits/stdc++.h>
using namespace std;
//Contribución a la suma
const int MX = 1e6 +5;
const int mod = 1e9 + 7;
int n, a[MX], pot2[MX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<= n; i++)
        cin>> a[i];
    pot2[0] = 1;
    for (int i = 1; i <= n; i++)
       pot2[i] = pot2[i - 1] * 2 % mod;

    long long res=0;
    for (int i= 1; i<=n; i++){
        res += 111 * pot2[i - 1] * a[i];
        res %= mod;

        res -= 111 * pot2[n-1] * a[i];
        res %= mod; //res puede que salga negativo por culpa del módulo

    }
    if(res < 0)
      res += mod;
    cout << res << endl;
 return 0;   
}