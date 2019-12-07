#include<iostream>
using namespace std;

int N,V;
int coins[100], dp[10001];
bool hasOne=false;

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  cin>>N>>V;
  for(int i=0; i<N; ++i){
    cin>>coins[i];
    if(coins[i]==1) hasOne=true;
  }
  int rc,exp;
  for(int i=0; i<N; ++i){
    if(coins[i]==1) continue;
    exp=V/coins[i];
    for(int f=1; exp>=f; f<<=1){
      int rv = f*coins[i];
      for(int j=V-rv;j>0;--j) if(dp[j]) dp[j+rv]+=dp[j];
      ++dp[rv];
    }
  }
  if(hasOne){
    int C=1;
    for(int i=2;i<=V;++i) C+=dp[i];
    cout<<C<<"\n";
  } else {
    cout<<dp[V]<<"\n";
  }
  return 0;
}
