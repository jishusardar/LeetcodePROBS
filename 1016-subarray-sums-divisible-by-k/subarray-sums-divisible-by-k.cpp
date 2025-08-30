class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mm;
        int sum=0,ans=0;
        mm[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            //handle the minus conditions if the rem is minus 
            if(rem<0)
            rem+=k;
            if(mm[rem]){
                ans+=mm[rem];
            }
            mm[rem]++;
        }
        return ans;
    }
};