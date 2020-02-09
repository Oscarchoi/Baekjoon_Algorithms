#include <iostream>
using namespace std;

int N,K;
int arr[5000000];

int partition(int i, int f){    
  swap(arr[i],arr[(i+f)/2]);  
  int ii = i++, pivot = arr[ii];   

  while(i<f){
    while(i<f && arr[i] <= pivot) ++i;
    while(i<f && arr[f] >= pivot) --f;
    if(i<f) swap(arr[i],arr[f]);    
  }
  swap(arr[ii], arr[i-1]);    
  return i-1;
}

int quickSort(int i, int f, int k){  
  int index = partition(i,f);
  //for(int a=0;a<N;++a) cout<<"   "<<arr[a]<<" "; cout<<endl;
  if(index < k) return quickSort(index+1,f,k);
  else if(index > k) return quickSort(i,index-1,k);
  else return arr[index];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);  
    
  cin>>N>>K;
  for(int i=0; i<N; ++i){
    cin>>arr[i];
  }
  int ret = quickSort(0,N-1,K-1);  
  cout<<ret<<"\n";
}