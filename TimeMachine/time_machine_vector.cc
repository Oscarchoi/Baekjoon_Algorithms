#include<tuple>
#include<iostream>
#include<vector>
using namespace std;

const int INF = 98765432;
int N, M, a, b, cost, i;
int cities[501];
vector<pair<int,int>> routes[501];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N>>M;
  while(M--){
    cin>>a>>b>>cost;
    routes[a].emplace_back(make_pair(b,cost));
  }
  for(i=2; i<=N;++i) cities[i]=INF;
  
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      for(const auto& route : routes[j]){
        if(cities[j] < INF && cities[route.first] > cities[j] + route.second) 
        {
          cities[route.first] = cities[j] + route.second;
          if(i==N) {cout<<"-1\n"; return 0;}
        }
      }
    }
  }

  for(i=2; i<=N; ++i) cout<<(cities[i]!=INF?cities[i]:-1)<<"\n";
  return 0;
}