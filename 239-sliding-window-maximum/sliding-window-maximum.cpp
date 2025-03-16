class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)
        return nums;
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k-1;i++){
            if(dq.empty())
            dq.push_back(i);
            else{
                while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
                dq.push_back(i);
            }
        }
        for(int i=k-1;i<nums.size();i++){
            while(!dq.empty()&&nums[dq.back()]<nums[i])
            dq.pop_back();
            dq.push_back(i);
            while(dq.front()<=i-k)
            dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};