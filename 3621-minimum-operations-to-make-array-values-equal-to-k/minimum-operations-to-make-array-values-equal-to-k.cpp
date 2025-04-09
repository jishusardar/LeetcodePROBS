class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mm;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)
            return -1;
        }
        int count=0;
        int maxi=INT_MIN;
        bool p=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k)
            p=true;
            maxi=max(maxi,nums[i]);
            mm[nums[i]]++;
        }
        if(p==false)
        count++;
        for(auto i:mm){
            if(i.first<maxi)
            count++;
        }
        return count;
    }
};