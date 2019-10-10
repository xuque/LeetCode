class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return true;
        }
        stack<char>Stack;
        Stack.push(s[0]);
        for(int i = 1; i < s.size(); ++i){
            if(!Stack.empty() && judge(Stack.top(), s[i])){
                Stack.pop();
            }
            else{
                Stack.push(s[i]);
            }
        }
        if(Stack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
private:
    bool judge(const char& symbol_1, const char& symbol_2){
        if(symbol_1 == '(' && symbol_2 == ')'){
            return true;
        }
        else if(symbol_1 == '{' && symbol_2 == '}'){
            return true;
        }
        else if(symbol_1 == '[' && symbol_2 == ']'){
            return true;
        }
        else return false;
    }
};

