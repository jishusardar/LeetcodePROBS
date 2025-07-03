class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int i=0;
        int inca=1;
        while(candies!=0){
            if(candies>inca){
                ans[i]+=inca;
                candies-=inca;
            }
            else{
                ans[i]+=candies;
                candies=0;
            }
            inca++;
            i=(i+1)%num_people;
        }
        return ans;
    }
};