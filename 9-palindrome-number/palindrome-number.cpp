class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return 0;
        string temp;
        while(x!=0){
            int rem=x%10;
            x/=10;
            char c=rem+'0';
            temp.push_back(c);
        }
        int start=0,end=temp.size()-1;
        while(start<end){
            if(temp[start]!=temp[end])
            return 0;
            start++,end--;
        }
        return 1;
    }
};