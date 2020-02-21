#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;
int N;

struct Word {
  char data[50];
  Word(){}
  Word(char text[50]){
    memcpy(data,text,50);
  }
};

bool operator==(const Word& lhs, const Word& rhs){ 
  return !strcmp(lhs.data, rhs.data);
}

bool operator<(const Word& lhs, const Word& rhs){
  cout<<strlen(lhs.data)<<" "<<strcmp(lhs.data,rhs.data)<<"\n";
  return strlen(lhs.data) < strlen(rhs.data) ? true 
  : strlen(lhs.data) > strlen(rhs.data) ? false : strcmp(lhs.data,rhs.data);
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>N;
  set<Word> words;  
  Word words2[N];

  for(int i=0; i<N; ++i) {
    char tmp[50];
    cin>>words2[i].data;
    //pair<set<Word>::iterator, bool> pr = words.insert(Word(tmp));    
    //cout<<"insert success? "<<pr.second<<"\n";
  }
  cout<<"result = "<<(words2[0]<words2[1])<<endl;

  //auto found = words.find("no");
  //cout<<found->data<<"===\n";

  
//  for(auto it : words)
    //cout<<it.data<<"\n";     

  return 0;
}