class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int>q;
        int flip=0;
        for(int i=0;i<nums.size();i++){
                //now check if q contain index that is not in the scope of i-k+1
                if(!q.empty()&&q.front()<i)
                q.pop();
                if(q.size()%2==nums[i]){   //matlab 0 ko even times flip karne ke bad bhi 0 hi rehta hai and vice versa for 1
                                           //agar differnt hai to already fliped hai 1me 
                  //check karna hai ki ka window exist kar sakta hai na nahi
                  if(i+k-1>=nums.size())
                  return -1;
                  //agar exist karta hai to kaha tak flip karna hai
                  q.push(i+k-1);
                  //no of flips ko count karna hai
                  flip++;
                }
        }
        return flip;
    }
};