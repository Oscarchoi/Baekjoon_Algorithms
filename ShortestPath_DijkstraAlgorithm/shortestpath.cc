#include<iostream>
#include<set>
#include<vector>

using namespace std;

const int INF = 9999999;
int V,E,R; //V:Vertex, E:Edge, R:Root_Vertex

vector<pair<int,int>> edges[20001];
int costs[20001];
bool visit[20001];

struct cmp{
  bool operator()(pair<int,int> lhs, pair<int,int> rhs){
    return lhs.second <= rhs.second ? true : lhs.first <= rhs.first ? true : false;
  }
};

void dijkstra(){
  set<pair<int,int>,cmp> sq;
  sq.emplace(make_pair(R,0));
  
  while(sq.size()){
    auto now = sq.begin(); // top 
    int from = now->first; 
    sq.erase(now); // pop 

    if(visit[from] == true) continue;
    visit[from] = true; 
   
    for(auto edge : edges[from]){
      if(costs[edge.first] > costs[from] + edge.second ){
        costs[edge.first] = costs[from] + edge.second;
        sq.emplace(make_pair(edge.first, costs[edge.first]));
        }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
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