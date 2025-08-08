class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>q;
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++){
            q.push({score[i],i});
        }
        int n=1;
        while(!q.empty()){
            if(n==1){
                ans[q.top().second]="Gold Medal";
            }
            else if(n==2){
                ans[q.top().second]="Silver Medal";
            }
            else if(n==3){
                ans[q.top().second]="Bronze Medal";
            }
            else{
                ans[q.top().second]=to_string(n);
            }
            q.pop();
            n++;
        }
        return ans;
    }
};