class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mm;
        int sum=0;
        int total=0;
        mm[0]=1;
        int rem;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
            rem+=k;
            if(mm[rem])
            total+=mm[rem];
            mm[rem]++;
        }
        return total;
    }
};