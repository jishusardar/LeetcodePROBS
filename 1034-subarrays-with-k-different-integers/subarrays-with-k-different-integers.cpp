class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int start=0,end=0,ans=0;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            while(mm.size()>k&&start<=end){
                mm[nums[start]]--;
                if(mm[nums[start]]==0){
                    mm.erase(nums[start]);
                }
                start++;
            }
            ans+=(end-start+1);
            end++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};