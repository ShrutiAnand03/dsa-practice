class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;

        if(
            firstList.size() == 0 
            || secondList.size()==0
        ){
            return ans;
        }

        int i=0, j=0;

        while(
            i<firstList.size() 
            && j< secondList.size()
        ){
            // cout<<"i: "<<i<<endl;
            // cout<<"j: "<<j<<endl;

            // cout<<firstList[i][0]<<" "<<firstList[i][1]<<endl;
            // cout<<secondList[j][0]<<" "<<secondList[j][1]<<endl;

            int first = max(
                firstList[i][0], 
                secondList[j][0]
            );

            int second = min(
                firstList[i][1] , 
                secondList[j][1]
            );


            if(first <=second){
                // cout<<"output pair: "<<first<<" "<<second<<endl;
                ans.push_back({first, second});
            }

            if(firstList[i][1] >= secondList[j][1]) j++;
            else i++;    
        }

        return ans;
    }
};