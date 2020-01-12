#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



struct Node {
  Node(int from, int next, int cost ): from(from), next(next), cost(cost){};
  int from, next, cost;
};
bool operator>(const Node lhs, const Node rhs){
    return lhs.cost>rhs.cost ? true: false;
};

int costs[1001];  
vector<pair<int,int>> routes[1001], pairs;

Node node(0,0,0);
const int INF = 100000;
int N, M, a, b, c, now, cost;

int main(){
  ios_base::sync_with_stdio(false);  
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>N>>M;    
    
  for(int i=2; i<=N; ++i) costs[i] = INF;
  
  while(M--){
    cin>>a>>b>>c;
    routes[a].push_back(make_pair(b,c));
    routes[b].push_back(make_pair(a,c));
  }
  priority_queue<Node,vector<Node>,greater<Node>> pq;  
  pq.push(Node(1,1,0));
  
  while(not pq.empty()){
    node = pq.top();    
    pq.pop();    
    
    if(costs[node.next]<node.cost) continue;
    pairs.push_back(make_pair(node.from, node.next));
    for(const auto& next : routes[node.next]){      
      if(costs[next.first]<=node.cost+next.second) continue;
      costs[next.first]=node.cost+next.second;      
      pq.push(Node(node.next,next.first,costs[next.first]));
    }
  }  

  cout<<pairs.size()-1<<"\n";
  for(int i=1; i<pairs.size(); ++i){
    cout<<pairs[i].first<<" "<<pairs[i].second<<"\n";
  }  
  return 0;
}