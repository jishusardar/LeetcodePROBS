class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {
        int count=0;
        queue<int>q;
        for(int i=0;i<tic.size();i++){
            q.push(i);
        }
        while(tic[k]!=0){
            tic[q.front()]--;
            if(tic[q.front()])
            q.push(q.front());
            q.pop();
            count++;
        }
        return count;
    }
};