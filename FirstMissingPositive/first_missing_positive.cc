#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();                
        for(int i=0;i<len;++i){            
            dts(nums,i,len);            
        }                
        for(int i=0;i<len;++i){
            if(nums[i]!=i+1) return i+1;
        }        
        return len+1;
    }    
    void dts(vector<int>& nums, int i, int len){
        int e = nums[i];
        if(e<=0 || e>len) return;
        if(nums[e-1]!=e){
            swap(nums[i],nums[e-1]);           
            dts(nums,i,len);
        }                 
    }
};