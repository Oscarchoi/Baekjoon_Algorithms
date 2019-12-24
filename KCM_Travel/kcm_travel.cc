#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1000000;
int T, N, M, K; // Test Case, Number of Airports, Maximum budget, Number of tickets
int s,d,c,t, minCost=INF;
int costTable[101][10001];
int minCosts[101];

struct route{
  int dest, cost, time;
 };

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>T;
  while(T--){
    // Each test case
    cin>>N>>M>>K;
    vector<route> tickets[N+1];    
    minCost=INF;

    // Clear i-th row of costTable 
    for(int i=1; i<=N; ++i) for(int j=0; j<=M; ++j) costTable[i][j] = INF;
    costTable[1][0] = 0;
    
    for(int i=0; i<K; ++i){
      cin>>s>>d>>c>>t;
      tickets[s].emplace_back(route{d,c,t});
    }
  
    // Set starting airports
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,1}});
    
    while(not pq.empty()){
      // top & pop
      int delay = pq.top().first;
      int spent = pq.top().second.first;
      int from = pq.top().second.second;
      pq.pop();
      
      if (from == N) break;

      //cout<<"Pop: "<<from<<", "<<spent<<endl;
      if(spent==M || delay > costTable[from][spent] ) continue;

      // Iterate over tickets
      for(auto& route : tickets[from]){
        d = route.dest;
        c = route.cost + spent;
        t = route.time + delay;
	      if(c>M || costTable[d][c] <= t ) continue;
        costTable[d][c] = t;
        //cout<<"Update: "<<d<<", "<<c<<", "<<t<<endl;
	      pq.push({t,{c,d}});
      }
	  }

    for(int i=0; i<=M; ++i){
      minCost = min(minCost, costTable[N][i]);
    }
    
    if (minCost<INF) cout<<minCost<<"\n";
    else cout<<"Poor KCM\n";
  } // end of while(T--) 
  return 0;
}
