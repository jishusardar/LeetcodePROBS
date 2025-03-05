class Solution {
public:
    long long maths(int n)
    {
        if(n==1)
        return 1;

        return 4*(n-1)+maths(n-1);
    }
    long long coloredCells(int n) {
        long long ans=maths(n);
        return ans;
    }
};