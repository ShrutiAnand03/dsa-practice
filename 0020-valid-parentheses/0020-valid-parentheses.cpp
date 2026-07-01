class Solution {
public:
    bool isValid(string s) {
        map<char,int>mp;
        stack<int>st;
        bool is_valid = true;

        mp['('] = 1;
        mp['{'] = 2;
        mp['['] = 3;
        mp[')'] = -1;
        mp['}'] = -2;
        mp[']'] = -3;

        for(auto v: s){
            int value = mp[v];

            if(value >0){
                // opening type bracket
                st.push(value);
            }
            else{
                if(!st.empty() && value + st.top()==0){
                    st.pop();
                }
                else{
                    is_valid = false;
                    return is_valid;
                }
            }
        }

        if(!st.empty()){
            is_valid =false;
        }

        return is_valid;
    }
};