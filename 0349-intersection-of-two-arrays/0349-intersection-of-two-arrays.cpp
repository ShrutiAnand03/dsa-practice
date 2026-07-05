class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp_1;
        unordered_map<int,int>mp_2;
        unordered_set<int>st;
        vector<int>ans;

        for(auto v: nums1){  // o(n)
            mp_1[v]++;
        }

        for(auto v: nums2){ //o(n)
            mp_2[v]++;
        }

        for(auto v: mp_1){ //o(n)
            auto it = mp_2.find(v.first); //o(1)
            if(it!= mp_2.end()) st.insert(v.first); //o(1)
        }

        for(auto x: st){ //o(n)
            ans.push_back(x); //o(1)
        }

        return ans;

    }
};