class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        unordered_map<char,int>mp_s;
        unordered_map<char,int>mp_t;

        for(int i=0;i<s.size();i++){
            mp_s[s[i]]++;
        }

        for(int i=0;i<t.size();i++){
            mp_t[t[i]]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp_s[s[i]] != mp_t[s[i]]) return false;
        }

        return true;

    }
};