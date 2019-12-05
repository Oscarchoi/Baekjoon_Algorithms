#include<iostream>
using namespace std;

int N,K,Max=0;
int chart[10001]={};

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  cin>>N>>K;
  int w,v,n;
  for(int i=0; i<N; ++i){
    cin>>w>>v>>n;
    for(int k=0; k<n; ++k){
      for(int j=K-w; j>0; --j){
	if(chart[j]==0) continue;
	chart[j+w]  = max(chart[j+w],chart[j]+v);
	//cout<<"chart["<<j+item[2*i]<<"] = "<< chart[j+item[2*i]]<<endl; 
	}
      chart[w]=max(chart[w],v);
    }
  }

  for(int i=1; i<=K; ++i) if(chart[i]>Max) Max = chart[i];
  cout<<Max<<"\n";
  return 0;
}
