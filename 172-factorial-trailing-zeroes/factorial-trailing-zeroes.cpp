class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)
        return 0;
        int ans=0;
        int mul=5;
        while(true){
            int temp=n/mul;
            if(temp==0)
            break;
            ans+=temp;
            mul*=5;
        }
        return ans;
    }
};