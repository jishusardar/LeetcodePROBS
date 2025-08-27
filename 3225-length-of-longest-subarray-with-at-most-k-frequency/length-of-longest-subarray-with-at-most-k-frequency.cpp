class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len=0,start=0,end=0;
        unordered_map<int,int>mm;
        while(end<nums.size()){
            mm[nums[end]]++;
            while(mm[nums[end]]>k){
                mm[nums[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};