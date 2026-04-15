#include <stdc/bits++.h>

using namespace std;

// digamos que para este problema podemos usar dos punteros para resolver

const int MX = 2e5 + 5;
int n, a[MX];

int signo (int x){
    if( x < 0)
      return -1;
    else 
      return +1;
}

void main_ (){
    cin >> n;
    for(int i = 0;i <n; i++)
      cin>> a[i];
    
    //dos punteros para saber hasta donde llega el bloque, como si lo encapsularamos con limites
    //pa que esté siempre sumando lo max posible 
    int i = 0, j = 1;
    long long res = 0;
    while (i <= n){
        int mx = a[i];
        j = i;
        while(j + 1 <= n && signo(a[i]) == signo(a[j])) {
            j++;   //la j siempre avanza cuando n+1 es del siguiente signo
            mx = max(mx,a[j]);
        }
        res += mx;
        i = j + 1;
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie();

    int t;
    cin >> t;
    while (t--)
      main_();
    
    return 0;
}