class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            ans=max(abs(nums[i]-nums[i+1]),ans);
        }
        ans=max(abs(nums[nums.size()-1]-nums[0]),ans);
        return ans;
    }
};