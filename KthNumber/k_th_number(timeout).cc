#include <iostream>
using namespace std;

int N,K;
int arr[5000000];

int partition(int l, int r) { 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            if(i!=j) swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
}

int quickSort(int i, int f, int k){  
  int index = partition(i,f);
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