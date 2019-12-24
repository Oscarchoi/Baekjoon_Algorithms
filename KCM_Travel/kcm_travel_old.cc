#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1000000;
int T, N, M, K; // Test Case, Number of Airports, Maximum budget, Number of tickets
int s,d,c,t, minCost;
int costTable[101][10001];

struct route{ int dest, cost, time; };
vector<route> tickets[101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>T;
  while(T--){
    // Each test case
    cin>>N>>M>>K;

    // Clear i-th row of costTable 
    for(int i=1; i<=N; ++i) {
      for(int j=0; j<=M; ++j) costTable[i][j] = INF;
      tickets[i].clear();
    }
    costTable[1][0] = 0;
    minCost = INF;
    
    for(int i=0; i<K; ++i){
      cin>>s>>d>>c>>t;
      tickets[s].emplace_back(route{d,c,t});
    }
  
    // Set starting airports
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,1));
    
    while(not pq.empty()){
      // top & pop
      int spent = pq.top().first;
      int from = pq.top().second;
      pq.pop();
      //cout<<"Pop: "<<from<<", "<<spent<<endl;
      if(spent>=M) continue;

      // Iterate over tickets
      for(int idx=0; idx<tickets[from].size(); ++idx){
        d = tickets[from][idx].dest;
        c = tickets[from][idx].cost + spent;
        t = tickets[from][idx].time + costTable[from][spent];

	      if(c>M) continue;

        bool useness = false;
        for(int i=0; i<=c; ++i) 
          if(costTable[d][i] <= t){
            useness = true; break;
          }
        if(useness) continue;

        costTable[d][c]=t;
        //cout<<"Update: "<<d<<", "<<c<<", "<<t<<endl;
	      pq.push(make_pair(c,d));
      }
	  }

    for(int i=0; i<=M; ++i)
      minCost = min(minCost,costTable[N][i]);
    if (minCost==INF) cout<<"Poor KCM\n";
    else cout<<minCost<<"\n";
  } // end of while(T--) 
  return 0;
}