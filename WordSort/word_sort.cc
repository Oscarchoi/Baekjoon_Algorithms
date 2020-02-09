#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Word {
  string str;
};

bool operator<(const Word& lhs, const Word& rhs){
  return lhs.str.length() < rhs.str.length() ? true 
  : lhs.str.length() == rhs.str.length() ? lhs.str < rhs.str 
  : false;
}

int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>N;
  Word words[N];
  
  for(int i=0; i<N; ++i) cin>>words[i].str;    
  
  sort(words, words+N);

  for(int i=0; i<N; ++i) cout<<words[i].str<<"\n";     

  return 0;
}