class Solution {
public:

    int getGCD(int a, int b){
        if(a == 0) return b;

        return gcd(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;

        for(auto v: nums){
            if(v<min) min =v;
            if(v>max) max =v;
        }

        return getGCD(min, max);
    }
};