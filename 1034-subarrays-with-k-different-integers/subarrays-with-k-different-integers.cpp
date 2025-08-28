class Solution {
public:
     int atleast(vector<int>&nums,int k)
     {
        int start=0,end=0;
        int count=0,size=0;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            if(mm[nums[end]]==1)
            size++;
            while(size==k){
                count+=nums.size()-end;
                mm[nums[start]]--;
                if(mm[nums[start]]==0)
                size--;
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