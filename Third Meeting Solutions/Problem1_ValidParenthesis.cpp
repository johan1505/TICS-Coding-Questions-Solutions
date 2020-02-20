#include <stack>

char ConvevrtToOpen(char c){
    switch(c){
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return '\0'; // error
    }
}

bool ValidParenthesis(string s){
    stack<char> unmatchedParenthesis;
    for (char c : s){
        if (c == '(' || c == '[' || c == '{'){
            unmatchedParenthesis.push(c);
        }
        else // close parenthesis
        {
            if (unmatchedParenthesis.empty()) return false;
            if (unmatchedParenthesis.top() != ConvevrtToOpen(c)) return false;

            unmatchedParenthesis.pop();
        }
    }
    return unmatchedParenthesis.empty();
}
