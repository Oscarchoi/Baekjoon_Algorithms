#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using Pair = pair<int,int>;

const int INF = 100000;
int N, M, a, b, now, cost;

int main(){
  cin>>N>>M;
  vector<int> routes[N+1], costs(N+1,INF);
  while(M--){
    cin>>a>>b;
    routes[a].push_back(b);
    routes[b].push_back(a);
  }
  priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
  pq.push(make_pair(0,0));
  
  while(not pq.empty()){
    now = pq.top().first;
    cost = pq.top().second;
    pq.pop();
    if(costs[now]<cost) continue;
    for(const auto& next : routes[now]){
      if(costs[next] < cost+1) continue;
      costs[next] = cost+1;
      pq.push(make_pair(next,cost+1));
    }
  }

  int pos=0, max=0, count=1;
  for(int i=1; i<N; ++i){
    if(costs[i]<max) continue;
    else if(costs[i]==max) ++count;
    else {
      max = costs[i];
      pos = i+1;
      count = 1;
    }
  }
  cout<<pos<<" "<<max<<" "<<count<<"\n";
  return 0;
}