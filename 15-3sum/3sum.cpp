class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        bool iszero=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            iszero=0;
        }
        if(iszero)
        return {{0,0,0}};
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        map<vector<int>,bool>mm;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int target=-nums[i]-(nums[j]);
                if(binary_search(nums.begin()+j+1,nums.end(),target))
                mm[{nums[i],nums[j],target}]=1;
            }
        }
        for(auto i:mm){
            ans.push_back(i.first);
        }
        return ans;
    }
};