class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start=0,end=0,len=INT_MIN;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            while(mm[nums[end]]>k&&start<=end){
                mm[nums[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};