class Solution {
public:
    bool check(vector<int>& subarray){
        int minval = INT_MAX;
        int bitWiseRes = subarray[0];

        for(auto v: subarray){
            minval = min(minval, v);
        }

        for(auto v: subarray){
            bitWiseRes = bitWiseRes & v;
        }

        return bitWiseRes == minval;
    }
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int count =0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                vector<int>subarray;

                for(int k=i; k<=j; k++){
                    subarray.push_back(nums[k]);
                }

                if(check(subarray)) count++;
            }
        }

        return count;
    }
};