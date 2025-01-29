class Solution {
public:
    int winner(vector<bool>person,int person_left,int n,int k,int index)
    {
        if(person_left==1){
            for(int i=0;i<person.size();i++){
                if(person[i]==0)
                return i;
            }
        }
        int kill=(k-1)%person_left;
        while(kill--){
            index=(index+1)%n;
            while(person[index]==1)
            index=(index+1)%n;
        }
        person[index]=1;
        while(person[index]==1)
        index=(index+1)%n;
        return winner(person,person_left-1,n,k,index);
    }
    int findTheWinner(int n, int k) {
        vector<bool>count(n,0);
        return winner(count,n,n,k,0)+1;
    }
};