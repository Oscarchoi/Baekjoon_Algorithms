#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;
int N;

set<string> words[50];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);    
  cin>>N;

  for(int i=0; i<N; ++i) {
    string tmp;
    cin>>tmp;    
    words[tmp.length()-1].insert(std::move(tmp));
  }
  
  for(int i=0; i<50; ++i) for(const auto& word : words[i]) cout<<word<<"\n";
 
  return 0;
}