class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> studentQueue;
        stack<int> sandwichStack;
        for(int i = 0; i<n; i++) {
            studentQueue.push(students[i]);
            sandwichStack.push(sandwiches[n - i - 1]);
        }
        int missed = 0;
        while(!sandwichStack.empty()) {
            if(sandwichStack.top() != studentQueue.front()) {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                missed++;
                if(missed >= sandwichStack.size()) break;
            }
            else {
                sandwichStack.pop();
                studentQueue.pop();
                missed = 0;
            }
        }
        return studentQueue.size();
    }
};