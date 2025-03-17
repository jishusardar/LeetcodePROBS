class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        unordered_map<int,int>mm;
        for(int i=0;i<nums.size();i++){
            mm[nums[i]]++;
        }
        int count=0;
        for(auto i:mm){
            if(i.second%2)
            return 0;
            else
            count+=i.second/2;
        }
        if(nums.size()/2==count)
        return 1;
        return 0;

    }
};