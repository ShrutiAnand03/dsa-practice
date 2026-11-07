class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start]!= s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void getPartition(
        int idx,
        int n,
        string& s,
        vector<string>& curr,
        vector<vector<string>>& ans
    ){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i<n; i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx, i-idx+1));
                getPartition(i+1,n,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        getPartition(0,s.size(),s,curr,ans);

        return ans;
    }
};