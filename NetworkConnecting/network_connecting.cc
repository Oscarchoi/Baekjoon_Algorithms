#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 987654321;
int N, M; // N<1000, M<100,000 --> Prim
int a,b,c,total_cost=0;

int cost[1001];
bool visit[1001];
vector<pair<int,int>> edges[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N>>M;  
  for(int i=0; i<M; ++i){
    cin>>a>>b>>c;    
    edges[a].emplace_back(make_pair(c,b));
    edges[b].emplace_back(make_pair(c,a));
  }

  for(int i=2; i<=N; ++i) cost[i]=INF;  
  pq.emplace(make_pair(0,1));

  while(not pq.empty()){
    pair<int,int> next = pq.top();        
    pq.pop();
    visit[next.second] = true;

    if(cost[next.second] < next.first ) continue;
    for(const auto& edge : edges[next.second]){            
      if(visit[edge.second] || cost[edge.second] <= edge.first) continue;
      //cout<<"  edge: "<<next.second<<"-"<<edge.second<<" = "<<edge.first<<endl;
      cost[edge.second] = edge.first;
      pq.emplace(edge);      
    }
  }

  for(int i=2; i<=N; ++i) total_cost += cost[i];
  std::cout<<total_cost<<"\n";
  return 0;
}