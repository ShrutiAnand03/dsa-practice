class Solution {
public:
    bool isValid(string s) {
        // stack<int>st;
        int top =-1;
        unordered_map<char, int>mp;
        mp['('] =1;
        mp['{'] =2;
        mp['['] =3;

        mp[')'] = -1;
        mp['}'] = -2;
        mp[']'] = -3;

        for(int i=0; i<s.size(); i++){
            int val = mp[s[i]];

            if(val > 0) s[++top] = s[i];

            else{
                if(top!=-1 && (val + mp[s[top]])==0) top--;
                else{
                    return false;
                }
            }
        }

        return top == -1;
    }
};