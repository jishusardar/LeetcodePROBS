class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int posmin=-1,posmax=-1,posin=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK)
            posin=i;
            if(nums[i]==minK)
            posmin=i;
            if(nums[i]==maxK)
            posmax=i;
            int posvalid=min(posmin,posmax);
            if(posvalid>posin)
            ans+=posvalid-posin;
        }
        return ans;
    }
};