#include<iostream>
using namespace std;

int N, M;
int arr[301],fdp[301],hdp[301];

void solve(int k){
  fdp[k] = hdp[k-1] + arr[k];
  hdp[k] = max(hdp[k-2],fdp[k-2]) + arr[k];  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N;
  
  for(int i=1; i<N+1; ++i) {
    cin>>arr[i];
    if(i==1) fdp[1] = hdp[1] = arr[1];
    else solve(i);
  }
  cout<<max(fdp[N],hdp[N])<<"\n";
  return 0;
}

