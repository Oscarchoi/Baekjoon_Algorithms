#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_COST 999999
int V,E,R; //V:Vertex, E:Edge, R:Root_Vertex

struct Edge {
  int begin, dest, cost;
};

vector<Edge> EdgeMap[20001]; // {dest, cost}
int CostTable[20001]={0};
bool Visited[20001]={0};

struct compareEdge{
  bool operator()(const Edge& e1, const Edge& e2){
    return e1.cost < e2.cost ? true : false;
  }
};

void dijkstra(){
  //declare set for prioirity_queue
  set<Edge,compareEdge> edgeSet;
  edgeSet.emplace(Edge{R,R,0});
  
  
  while(not edgeSet.empty()){
    auto prev = edgeSet.begin(); edgeSet.erase(prev); // pop
    if(Visited[prev->dest] == true) continue;
    Visited[prev->dest] = true; 
    
    for(const auto& route : EdgeMap[prev->dest]){
      if( CostTable[route.dest] <= CostTable[route.begin] + route.cost ) continue;
      CostTable[route.dest] = CostTable[route.begin] + route.cost;
      edgeSet.emplace(Edge{route.begin,route.dest,CostTable[route.dest]});
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>V>>E>>R;
  
  for(int i=1; i<=V; ++i) CostTable[i]=MAX_COST;
  CostTable[R]=0;
 
  int begin, dest, cost;
  for(int i=1; i<=E; ++i){
    cin>>begin>>dest>>cost;

    EdgeMap[begin].push_back(Edge{begin,dest,cost});
  }
  dijkstra();

  for(int i=1; i<=V; ++i){
    if( CostTable[i] != MAX_COST) cout<<CostTable[i]<<"\n";
    else cout<<"INF\n";
  }
  return 0;
}
