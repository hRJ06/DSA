class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        unordered_set<char> operator_to_push = {'&', '!', '|', '(', 't', 'f'};
        for(auto &i : expression) {
            if(operator_to_push.find(i) != operator_to_push.end()) {
                s.push(i);
            }
            else if(i != ',') {
                vector<bool> bool_values;
                while(s.top() != '(') {
                    bool_values.push_back(s.top() != 'f' ? true : false);
                    s.pop();
                }
                s.pop(); 
                char op_to_apply = s.top();
                s.pop();
                if(op_to_apply != '!') {
                    bool ans = bool_values[0];
                    for(auto i : bool_values) {
                        if(op_to_apply != '&') {
                            ans |= i;
                        }   
                        else {
                            ans &= i;
                        }
                    }
                    s.push(ans ? 't' : 'f');
                }
                else {
                    bool ans = bool_values[0];
                    s.push(!ans ? 't' : 'f');
                }
            }
        }
        return s.top() != 'f' ? true : false;
    }
};