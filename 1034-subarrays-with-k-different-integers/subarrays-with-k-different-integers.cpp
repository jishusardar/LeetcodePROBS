class Solution {
public:
     int atleast(vector<int>&nums,int k)
     {
        int start=0,end=0;
        int count=0;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            while(mm.size()==k){
                count+=nums.size()-end;
                mm[nums[start]]--;
                if(mm[nums[start]]==0)
                mm.erase(nums[start]);
                start++;
            }
            end++;
        }
        return count;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=atleast(nums,k)-atleast(nums,k+1);
        return ans;
    }
};