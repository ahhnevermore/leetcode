//6-1-2026 3
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int r1;
        int r2;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                r2 = stack.back();
                stack.pop_back();
                r1 = stack.back();
                stack.pop_back();
                if (token == "+") {
                    stack.push_back(r1 + r2);
                } else if (token == "-") {
                    stack.push_back(r1 - r2);
                } else if (token == "*") {
                    stack.push_back(r1 * r2);
                } else if (token == "/") {
                    stack.push_back(r1 / r2);
                }
            } else {
                stack.push_back(std::stoi(token));
            }
        }
        return stack[0];
    }
};