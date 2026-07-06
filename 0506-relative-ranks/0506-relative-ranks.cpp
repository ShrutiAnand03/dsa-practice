class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp;
        vector<string>ans;

        for(int i=0; i<score.size(); i++){
            temp.push_back(score[i]);
        }

        sort(temp.begin(), temp.end(), greater<int>());

        int first = temp[0];
        int second =-1;
        int third = -1;

        if(temp.size()>1)
            second = temp[1];

        if(temp.size()>2)
            third = temp[2];

    
        for(int i=0; i<score.size(); i++){
            if(score[i] == first) ans.push_back("Gold Medal");
            else if(score[i] == second) ans.push_back("Silver Medal");
            else if(score[i] == third) ans.push_back("Bronze Medal");
            else{
                auto it = find(temp.begin(), temp.end(), score[i]);
                int index = it - temp.begin();
                ans.push_back(to_string(index+1));
            }
        }

        return ans;
    }
};