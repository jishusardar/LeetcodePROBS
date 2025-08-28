class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long start=0,end=0;
        unordered_map<int,int>mm;
        long long count=0,maximum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maximum)
            maximum=nums[i];
        }
        while(end<nums.size()){
            mm[nums[end]]++;
        while(mm[maximum]>=k){
            count+=nums.size()-end;
            mm[nums[start]]--;
            start++; 
        }
            end++;
        }
        return count;
    }
};