#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n+1];
        dp[0].push_back("");
        dp[1].push_back("()");        
        for(int i=2; i<=n; ++i)
            for(int j=0; j<i;++j)            
                for(const auto& e:dp[j])
                    for(const auto& f:dp[i-j-1])
                        dp[i].push_back('('+e+')'+f);            
        return dp[n];        
    }
};