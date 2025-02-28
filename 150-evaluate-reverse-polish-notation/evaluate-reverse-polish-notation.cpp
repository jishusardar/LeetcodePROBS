class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=="*"||arr[i]=="/"||arr[i]=="+"||arr[i]=="-"){
                int second=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                if(arr[i]=="*")
                st.push(first*second);
                else if(arr[i]=="+")
                st.push(first+second);
                else if(arr[i]=="-")
                st.push(first-second);
                else if(arr[i]=="/")
                st.push(first/second);
            }
            else{
                int num=stoi(arr[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};