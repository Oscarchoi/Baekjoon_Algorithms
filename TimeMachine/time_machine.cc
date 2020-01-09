#include<iostream>
#include<vector>
using namespace std;

const int INF = 987654321;
int N, M;
int cities[501];
int routes[501][501];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N>>M;
  for(int i=0; i<=N;++i) {
    cities[i]=INF;
    for(int j=0; j<=N;++j) routes[i][j]=INF;
  }
  cities[1]=0;

  int a,b,cost;
  for(int i=0; i<M; ++i){
    cin>>a>>b>>cost;
    if(routes[a][b] > cost) routes[a][b] = cost;
  }

  for(int n=1; n<=N; ++n){
    for(int i=1; i<=N; ++i){
      for(int j=1; j<=N; ++j){
        if(routes[i][j]==INF) continue;
        if(cities[j] > cities[i] + routes[i][j]){
          cities[j] = cities[i] + routes[i][j];
          if(n==N) {cout<<-1; return 0;}
        }
      }
    }
  }

  for(int i=2; i<=N; ++i) cout<<(cities[i]!=INF?cities[i]:-1)<<"\n";
  return 0;
}