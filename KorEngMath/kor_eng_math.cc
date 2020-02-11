#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct Student{
  char name[11];
  int kor, eng, math; 
};

bool operator<(const Student& lhs, const Student& rhs){
  return lhs.kor != rhs.kor ? lhs.kor > rhs.kor :
         lhs.eng != rhs.eng ? lhs.eng < rhs.eng :
         lhs.math != rhs.math ? lhs.math > rhs.math :
         strcmp(lhs.name, rhs.name) < 0 ? true : false;
}

int N, n;
Student arr[100001];

void heapify(int i){
  int l = 2*i+1;
  int r = 2*i+2;
  int largest = i;
  if(l<n && arr[l]<arr[i]) largest = l;
  if(r<n && arr[r]<arr[largest]) largest = r;

  if(largest != i) {
    swap(arr[i],arr[largest]);
    heapify(largest);
  }
}

void heap_sort(){
  n = N;
  for(int i=N/2-1; i>=0; --i) heapify(i);
  
  for(int i=N-1; i>0; --i){
    swap(arr[0],arr[i]);
    --n;
    heapify(0);
  }
}

void print(){  
  for(int i=N-1;i>=0;--i) cout<<arr[i].name<<"\n";  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N;
  for(int i=0;i<N;++i){
    cin>>arr[i].name>>arr[i].kor>>arr[i].eng>>arr[i].math;    
  }

  heap_sort();
  print();
  
  return 0;
}