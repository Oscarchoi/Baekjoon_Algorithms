#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
  int root,cost,height=1;
};
Node disjoint_set[10001];

struct Edge {
  int begin, dest, cost;
};

bool operator<(const Edge& lhs, const Edge& rhs){
  return lhs.cost > rhs.cost;
}
priority_queue<Edge> edges;

int find_root(int index){
  int root = disjoint_set[index].root;    
  // path compression if node is not root
  return root == index ? index : disjoint_set[index].root = find_root(root);  
};

void merge(int first, int second, int cost){
  // already in same set
  std::cout<<"root_of("<<first<<")="<<find_root(first)<<" root_of("<<second<<")="<<find_root(second)<<endl;
  if(find_root(first) == find_root(second)) return;  
  
  // put lower height tree into higher one
  Node& lhs = disjoint_set[first], &rhs = disjoint_set[second];      
  if(lhs.height >= rhs.height) {    
    rhs.root = lhs.root;
  
    lhs.height += rhs.height;
    rhs.height = 1;
    rhs.cost = cost;
  } else {
    lhs.root = rhs.root;
    rhs.height += lhs.height;
    lhs.height = 1;
    lhs.cost = cost;
  }
  std::cout<<"root_of("<<first<<")="<<find_root(first)<<" root_of("<<second<<")="<<find_root(second)<<endl;
  
};


int V,E;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a,b,c;
  cin>>V>>E;  
  for(int i=0; i<E; ++i){
    cin>>a>>b>>c;
    edges.emplace(Edge{a,b,c});
  }

  for(int i=1; i<=10001; ++i){
    disjoint_set[i].root = i;
  }

  while(not edges.empty()){
    Edge now = edges.top();
    edges.pop();
    merge(now.begin, now.dest, now.cost);    
  }

  int total = 0;
  for(int i=1; i<=V; ++i) total += disjoint_set[i].cost;  
  std::cout<<total<<"\n";

  return 0;
}