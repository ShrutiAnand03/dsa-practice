class Solution {
public:
    int getGcd(int a, int b){
        if(a == 0) return b;

        return getGcd(b%a, a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;

        for(auto v: deck){
            mp[v]++;
        }

        int gcd = 0; // this will hit the base case
        // so suppose frequencies are [2,3,4,2]
        // so gcd(0,2) will be 2 and then we can further calculate

        for(auto v: mp){
            gcd = getGcd(gcd, v.second);
        }

        if(gcd>=2) return true;

        return false;
    }
};