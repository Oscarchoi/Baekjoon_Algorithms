#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int arr[5000001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);  
    
  cin>>N>>K;
  for(int i=0; i<N; ++i){
    cin>>arr[i];
  }

  nth_element(arr+0,arr+K-1,arr+N);  
  cout<<arr[K-1]<<"\n";
}
