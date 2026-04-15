#include <bits/stdc++.h>

 using namespace std;
int n, a[17],res;

 const int mod= 1e9 + 7 //esta manera es más de q rapiditsima 
 
 void f( int i, vector<int>, subsecuencia){
  if(i == n){
   if(!subsecuencia.empty()){
  int mx = *max_element(subsecuencia.begin(), subsecuencia.end());
  int mn = *min_element(subsecuencia.begin(), subsecuencia.end());
//al final 
  res+= mx - mn;
  res%=mod;
  }
  return; //de todas formas retorne
  }
  
  f(i + 1, subsecuencia);
  
  subsecuencia.pushback(a[i]);
  f(i + 1, subsecuencia);
  subsecuencia.popback(); //por referencia, no haces tantas copias, solo es a un elemento 
 }
 
 
 int main(){
  cin>>n;
  for(int i = 0; i<n; i++){
  cin>>a[i];
  }
  
  vector<int> subsecuencia; 
  f(0,subsecuencia); //f(i,{})
  
  cout<< res << endl;
  
 return 0;}