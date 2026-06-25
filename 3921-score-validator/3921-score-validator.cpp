class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int>ans;
        int score=0, count =0;

        for(int i =0; i < events.size(); i++){
            if (count == 10){
                break;
            }
            if (events[i] == "W"){
                count++;
                cout<<count<<endl;
            }
            else if (
                events[i] == "WD" || 
                events[i] == "NB"
            ){
                score++;
            }
            else{
                int num = stoi(events[i]);
                score+=num;
            }
        }

        ans.push_back(score);
        ans.push_back(count);

        return ans;
    }
};