class Solution {
public:
     int atmost(vector<int>&nums,int k)
     {
        int start=0,end=0;
        int count=0;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            while(mm.size()>k){
                mm[nums[start]]--;
                if(mm[nums[start]]==0)
                mm.erase(nums[start]);
                start++;
            }
            count+=end-start+1;
            end++;
        }
        return count;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=atmost(nums,k)-atmost(nums,k-1);
        return ans;
    }
};