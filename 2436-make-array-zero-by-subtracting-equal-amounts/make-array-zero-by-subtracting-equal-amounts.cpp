class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
            q.push(nums[i]);
        }
        int count=0;
        while(!q.empty()){
            int num=q.top();
            q.pop();
            int n=q.size();
            while(n--){
                if(q.top()-num)
                q.push(q.top()-num);
                q.pop();
            }
            count++;
        }
        return count;
    }
};