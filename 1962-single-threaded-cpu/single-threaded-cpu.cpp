class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        long long timer=tasks[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int i=0;
        while(!q.empty()||i<n){
            while(i<n&&timer>=tasks[i][0]){
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(q.empty()){
                timer=tasks[i][0];
            }
            else{
                timer+=q.top().first;
                ans.push_back(q.top().second);
                q.pop();
            }
        }
        return ans;
    }
};