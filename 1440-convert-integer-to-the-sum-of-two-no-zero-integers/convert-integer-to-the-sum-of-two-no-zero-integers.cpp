class Solution {
public:
    bool checkzero(int n)
    {
        while(n!=0){
            if(n%10==0)
            return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans(2,-1);
        for(int i=1;i<n;i++){
            int j=n-i;
            if(checkzero(i)&&checkzero(j)){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
        return ans;
    }
};