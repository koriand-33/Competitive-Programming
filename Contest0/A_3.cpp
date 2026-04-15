#include<bits/stdc++.h>

using namespace std;

constexpr int maxn{200'000}; //separados de numeros la comita
vector<int> adj[maxn];  //vector estático de vectores dinámicos 
bool vis[maxn];

void dfs(vector<vector<int>> & adj, vector<bool> & vis, int v){
  vis[v] = true;
  for (auto w: adj[v]){
    if(!vis[w]){
        dfs(adj, vis, w);
    }
  }
}
int main(){

 int n, m ; cin >> n >> m;
 vector<vector<int>> adj(n);
 vector<bool> vis(n,false); //vector de visitados 
 int a, b; cin >> a >> b; --a, --b;

 for(int i=0; i<m;i++){
    int u,v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  
 }
 vector<int> a(n);
 int sum_comp = 0;
 auto dfs = [&] (this auto&& dfs, int v) -> void {
    vis[v] = true; //este arreglo siempre siempre tiene q estar
    sum_comp += a[v]; //recorrer nodos
    for ( auto w: adj[v]){
        if(!vis[w]){
            dfs(w);   //recorrido de aristas
        }
    }                      
 };
 dfs(a);
 cout << (vis[b]? "YES":"NO") << "\n";

    return 0
}