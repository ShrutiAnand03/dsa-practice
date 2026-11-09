/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(
        int src, 
        vector<Employee*>& employees, 
        unordered_map<int, Employee*>mp,
        int& res
    ){
        Employee* emp = mp[src];
        res+=emp->importance;
        
        for(auto v: emp->subordinates){
            dfs(v,employees, mp,res);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        int res =0; 

        for(auto employee: employees){
            mp[employee->id] = employee; 
        }

        dfs(id, employees, mp, res);

        return res;
    }
};