#include<iostream>
#include<cstdio>
using namespace std;

/* Useful Macros */

#define FOR(i,n) for(int i=0; i<(n); ++i)
#define FORR(i, arr) for(auto& i : arr)

#include<cstring>
#define ZERO(p) memset(p,0,sizeof(p))

// Test 
int main(){
  int i = 123;
  ZERO(&i);  // 0 
  
  int arr[5] = {1,2,3,4,5};
  ZERO(arr); // 0 0 0 0 0
  
  FOR(i,5) cout<<arr[i]<<endl;
  return 0;
}
