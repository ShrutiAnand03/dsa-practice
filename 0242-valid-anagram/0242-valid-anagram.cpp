class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        unordered_map<char,int>mp;

        for(auto c: s){  // o(n)
            mp[c]++;
        }

        for(auto c: t){  // o(n)
            mp[c]--;
        }

        for(auto v: mp){
            if(v.second !=0)return false;
        }

        return true;

    }
};