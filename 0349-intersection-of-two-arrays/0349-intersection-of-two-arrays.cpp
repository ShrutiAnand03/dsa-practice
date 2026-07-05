class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(), nums1.end());
        unordered_set<int>ans_set;

        for(auto v:nums2){
            if(st.count(v)){
                ans_set.insert(v);
            }
        }
        return vector<int>(ans_set.begin(), ans_set.end());
    }
};