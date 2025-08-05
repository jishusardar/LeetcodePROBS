class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>isfull(baskets.size(),0);
      int count=fruits.size();
      for(int i=0;i<fruits.size();i++){
        int fsize=fruits[i];
        for(int j=0;j<baskets.size();j++){
            if(baskets[j]>=fsize){
                if(isfull[j]==0){
                    isfull[j]=1;
                    count--;
                    break;
                }
            }
        }
      }
      return count; 
    }
};