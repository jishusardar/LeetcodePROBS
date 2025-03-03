class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans(nums.size());
        int start=0,end=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans[start]=nums[i];
                start++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
            ans[start]=nums[i];
            start++;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>pivot){
                ans[end]=nums[i];
                end--;
            }
        }
        return ans;
    }
};