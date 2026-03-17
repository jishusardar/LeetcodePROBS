class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>grid(n,1);
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int pre=grid[j];
                grid[j]=pre+grid[j+1];
            }
        }
        return grid[0];
    }
};