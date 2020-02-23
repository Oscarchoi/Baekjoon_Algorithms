#include<iostream>
using namespace std;

int N,K,DP[10001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N>>K;
  for(int i=1;i<=K;++i) DP[i] = 10001;

  int tmp;
  for(int i=0;i<N;++i){
    cin>>tmp;
    for(int j=tmp; j<=K; ++j){
      if(DP[j]>DP[j-tmp]+1) DP[j]= DP[j-tmp]+1;
    }
  }
  cout<<((DP[K]==10001)?-1:DP[K])<<"\n";
  return 0;
}