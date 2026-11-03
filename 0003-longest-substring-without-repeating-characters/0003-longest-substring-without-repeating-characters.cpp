class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0, right =0;
        unordered_set<int>st;
        int ans =0;

        while(right<s.size()){
            auto it = st.find(s[right]);

            if(it == st.end()){
                st.insert(s[right]);
                right++;
            }
            else{
                st.erase(s[left]);
                left++;
            }
            ans = max(ans, right-left);
            // cout<<"ans: "<<ans<<"\n";
        }
        return ans;
    }
};