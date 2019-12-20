#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 100000 
int T, N, M, K;
int s,d,c,t;
int costTable[101][10001];

struct route{ int dest, cost, time; };
vector<route> tickets[100];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>T;
  while(T--){
    cin>>N>>M>>K;
  
    for(int i=0; i<K; ++i){
      cin>>s>>d>>c>>t;
      tickets[s].emplace_back(route{d,c,t});
    }
  
    for(int i=1; i<=N; ++i){
      // Clear i-th row of costTable
      fill(begin(costTable[i]),end(costTable[i]),INF);
      costTable[1][0] = 0;

      // Iterate over cities
      for(int from=1; from<=M; ++from){
	// Iterate over tickets
	for(int idx=0; idx<tickets[from].size(); ++idx){
	  d = tickets[from][idx].dest;
	  c = tickets[from][idx].cost;
	  t = tickets[from][idx].time;	  	  
	  
	  for(int spent=0; spent<=M; ++spent){	    
	    if(c+spent > M) break;
	    if(costTable[from][spent]>=INF) continue;	    
	    costTable[d][spent+c] = min(costTable[d][spent+c], costTable[from][spent]+t);
	  }	  



	}


      }
    }
    



  }
  return 0;
}
