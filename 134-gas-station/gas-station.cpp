class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int gasq=0;
        for(int i=0;i<gas.size();i++){
            sum+=cost[i];
            gasq+=gas[i];
        }
        if(sum>gasq)
        return -1;
        queue<int>q;
        int remain=0;
        for(int i=0;i<gas.size();i++){
            q.push(i);
            if(gas[i]+remain<cost[i]){
                while(!q.empty())
                q.pop();
                remain=0;
            }
            else{
                remain+=gas[i]-cost[i];
            }
        }
        return q.front();
    }
};