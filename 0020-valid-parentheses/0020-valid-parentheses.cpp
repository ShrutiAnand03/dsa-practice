class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        unordered_map<char, int>mp;
        mp['('] =1;
        mp['{'] =2;
        mp['['] =3;

        mp[')'] = -1;
        mp['}'] = -2;
        mp[']'] = -3;

        for(int i=0; i<s.size(); i++){
            int val = mp[s[i]];

            if(val > 0) st.push(val);

            else{
                if(!st.empty() && val + st.top()==0) st.pop();
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};