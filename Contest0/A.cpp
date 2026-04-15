#include<bits/stdc++.h>

using namespace std;
//ventajas, si es multicaso hay q limpiar el vectorsito 

constexpr int maxn{200'000}; //separados de numeros la comita
vector<int> adj[maxn];  //vector estático de vectores dinámicos 
bool vis[maxn];

void dfs(int v){
  vis[v] = true;
  for (auto w: adj[v]){
    if(!vis[w]){
        dfs(w);
    }
  }
}
int main(){

 int n, m ; cin >> n >> m;
 int a, b; cin >> a >> b; --a, --b;

 for(int i=0; i<m;i++){
    int u,v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);

 }
 dfs(a);
 cout << (vis[b]? "YES":"NO") << "\n";

    return 0;
}