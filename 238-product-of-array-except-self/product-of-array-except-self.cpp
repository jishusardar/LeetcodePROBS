class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        vector<int>ans(nums.size(),0);
        int cz=0;
        bool p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
            mul*=nums[i];
            else{
                cz++;
                p=1;
            }
        }
        if(cz>1)
        return ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0&&p==1){
                ans[i]=0;
            }
            else{
                if(nums[i]!=0)
                ans[i]=mul/nums[i];
                else
                ans[i]=mul;
            }
        }
        return ans;
    }
};