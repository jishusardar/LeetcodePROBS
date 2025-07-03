class Solution {
public:
    int intobin(int n)
    {
        int count=0;
        while(n!=0){
            int rem=n%2;
            if(rem==1)
            count++;
            n/=2;
        }
        return count;
    }
    char kthCharacter(int k) {
        int num=intobin(k-1);
        char c='a'+num;
        return c;
    }
};