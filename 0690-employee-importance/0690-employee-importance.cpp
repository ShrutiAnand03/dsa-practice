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
        Employee* src, 
        vector<Employee*>& employees, 
        vector<int>visited,
        int& res
    ){
        visited[src->id] =1;
        res+=src->importance;
        
        for(auto v: src->subordinates){
            if(!visited[v]){
                for(auto it: employees){
                    if(it->id  == v) dfs(it,employees, visited, res);
                }
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        vector<int>visited(2001, 0);   
        int res =0; 
        for(auto employee: employees){
            if(employee->id  == id){
                dfs(employee, employees, visited, res); 
            }
                
        }

        return res;
    }
};