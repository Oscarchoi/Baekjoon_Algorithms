#include <iostream>

using namespace std;

short A[50],B[50];
int total=0;

// Insertion sort
void InsertionSort(short* arr, int idx){
  short tmp = arr[idx];
  for(int i=idx; i>0; --i){
    if(tmp > arr[i-1]) {
      arr[i] = tmp; return;
    }
    arr[i]=arr[i-1];
  }
  arr[0] = tmp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin>>N;
  for(int i=0; i<N; ++i) cin>>A[i];
  for(int i=0; i<N; ++i) cin>>B[i];  
  
  for(int i=1; i<N; ++i){
    InsertionSort(A,i);
    InsertionSort(B,i);
  }
  
  for(int i=0; i<N; ++i){    
    total += A[i]*B[N-1-i];    
  }
  cout<<total<<"\n";

  return 0;
}
