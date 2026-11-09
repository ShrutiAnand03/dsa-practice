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
    int dfs(
        int src, 
        vector<Employee*>& employees, 
        unordered_map<int, Employee*>mp
    ){
        Employee* emp = mp[src];
        int res=emp->importance;
        
        for(auto v: emp->subordinates){
            res+= dfs(v,employees, mp);
        }

        return res;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for(auto employee: employees){
            mp[employee->id] = employee; 
        }

        return dfs(id, employees, mp);
    }
};