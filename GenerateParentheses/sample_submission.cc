#include<vector>
#include<string>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n){
      if(n==0) return {};
      vector<string> v;
      check("",n,v,0,0);
      return v;
    };

    void check(string str, int n, vector<string>& v, int open, int close){
      // Terminate Recursive
      if(close==n) {
        v.push_back(str);
      }
      // Recursive
      else {
        if(close<open){
          check(str+')',n,v,open,close+1);
        } 
        if(open<n) {
          check(str+'(',n,v,open+1,close);
        }
      } 
    };
};