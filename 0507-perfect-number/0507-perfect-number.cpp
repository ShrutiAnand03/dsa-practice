class Solution {
public:
    vector<int>allDivisors(int num){
        vector<int>ans;
        ans.push_back(1);

        for(int i=2; i*i <= num; i++){
            if(num%i==0){
                ans.push_back(i);

                if(i*i!=num) ans.push_back(num/i);
            }
        }

        return ans;
    }
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        vector<int>divisors = allDivisors(num);

        long long sum =0;
        for(auto v: divisors){
            cout<<v<<" ";
            sum+=v;
        }

        if(sum == num) return true;

        return false;
    }
};