class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mm;
        int sum=0,ans=0;
        mm[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mm[sum-k]){
                ans+=mm[sum-k];
            }
            mm[sum]++;
        }
        return ans;
    }
};