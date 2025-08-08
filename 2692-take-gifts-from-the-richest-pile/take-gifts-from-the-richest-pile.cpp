class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q(gifts.begin(),gifts.end());
        long long ans=0;
        while(k--&&!(q.empty())){
            q.push(sqrt(q.top()));
            q.pop();
        }
        if(q.empty())
        return 0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};