#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 9999999;
int V,E,R; //V:Vertex, E:Edge, R:Root_Vertex

vector<pair<int,int>> edges[20001];
int costs[20001];
bool Visited[20001];

void dijkstra(){
  // define prioirity_queue
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, R)); 
  
  while (!pq.empty()) {
    int cost = pq.top().first;
    int from = pq.top().second;
    pq.pop();

    if (costs[from]<cost) continue;
        
    for(auto edge : edges[from]){
      if(costs[edge.first] > edge.second + cost){
        costs[edge.first] = edge.second + cost;
        pq.push(make_pair(costs[edge.first],edge.first)); 
      }
    }
  }
  return;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>V>>E>>R;
  for(int i=0; i<=V; ++i) costs[i]=INF;
  costs[R]=0;
 
  int begin, dest, cost;
  for(int i=0; i<E; ++i){
    cin>>begin>>dest>>cost;
    edges[begin].push_back(make_pair(dest,cost));
  }
  dijkstra();

  for(int i=1; i<=V; ++i){
    if(costs[i] == INF) cout<<"INF\n";
    else cout<<costs[i]<<"\n";
  }
  return 0;
}
