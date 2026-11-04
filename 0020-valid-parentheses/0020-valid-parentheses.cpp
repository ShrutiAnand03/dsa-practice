class Solution {
public:
    bool isValid(string s) {
        int top = -1;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                s[++top] = s[i];
            }
            else{
                if(top == -1) return false;

                if(
                    s[i] == ')' && s[top]!= '('
                    || s[i] == '}' && s[top]!= '{'
                    || s[i] == ']' && s[top]!= '['
                ) return false;

                top--;
            }
        }

        return top == -1;
    }
};