class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum=0;
        for(int i=0;i<target.size();i++)
        sum+=target[i];
        priority_queue<int>q(target.begin(),target.end());
        while(q.top()!=1){ 
            long long maxEl=q.top();
            q.pop();
            sum-=maxEl;
            if(sum<1)
            return 0;
            if(sum>=maxEl)
            return 0;
            int el=maxEl%sum;
            if(el==0&&sum!=1)
            return 0;
            if(el==0)
            el++;
            q.push(el);
            sum+=el;
        }
        return 1;
    }
};