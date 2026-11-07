class Solution {
public:
    void getPermutation(
        int idx, 
        int n,
        string &s,
        string &curr,
        vector<string>& ans
    ){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(s[idx]);
        getPermutation(idx+1, n, s, curr, ans);

        if(s[idx] >= 'a' && s[idx]<='z'){
            curr[idx] = toupper(curr[idx]);
            getPermutation(idx+1, n, s, curr, ans);
        }

        curr.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string>ans;
        string curr = "";

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s<<"\n";
        getPermutation(0, n, s, curr, ans);
        return ans;
    }
};
