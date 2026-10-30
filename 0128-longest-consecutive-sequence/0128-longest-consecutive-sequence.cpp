class Solution {
public:
    int countConsecutive(unordered_set<int>& st, int val){
        int count=0;
        while(st.find(val)!=st.end()){
            count++;
            val++;
        }
        return count;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int>st;

        for(auto &v: nums){
            st.insert(v);
        }

        int ans =0;
        for(auto &v: st){
            if(st.find(v-1)==st.end()){
                ans = max(ans, countConsecutive(st,v));
            }
        }
        return ans;
    }
};