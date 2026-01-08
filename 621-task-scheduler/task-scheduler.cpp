class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mm;
        int sum=0;
        for(int i=0;i<tasks.size();i++){
            mm[tasks[i]]++;
            sum=max(sum,mm[tasks[i]]);
        }
        int count=0;
        for(auto i:mm){
            if(i.second==sum)
            count++;
        }

        int ans=(sum-1)*(n+1)+count;
        return ans>tasks.size()?ans:tasks.size();
    }
};