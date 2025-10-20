class Solution {
private:
    unordered_set<char> operators = {'+', '-', '*'};
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> output; 
        int n = expression.length();
        for(int i = 0; i<n; i++) {
            char ch = expression[i];
            if(operators.find(ch) != operators.end()) {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for(auto &i : left) {
                    for(auto &j : right) {
                        if(ch == '+') output.push_back(i + j);
                        if(ch == '-') output.push_back(i - j);
                        if(ch == '*') output.push_back(i * j);
                    }
                }
            }
        }
        if(!output.size()) return {stoi(expression)};
        return output;
    }
};