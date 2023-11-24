#include <iostream>
#include "./auto-stack.cpp"
#include "./precedence.cpp"

std::string InfixToPrefix(std::string& infix) {
    std::string prefix;
    AutoStack <char> oprStack;
    infix = "("+infix+")";

    for (int i=infix.length()-1; i >= 0; i--) {
        if (infix[i] == ')') oprStack.push(infix[i]);
        else if (std::isalnum(infix[i])) prefix += infix[i];
        else if (infix[i] == '(') {
            while (oprStack.top() != ')') {
                prefix += oprStack.top();
                oprStack.pop();
            }
            oprStack.pop(); // popping ')'
        } else {
            while (!oprStack.isEmpty() && precedence(oprStack.top()) > precedence(infix[i])) {
                prefix += oprStack.top();
                oprStack.pop();
            }
            oprStack.push(infix[i]);
        }
    }

    std::string reasult;
    for (int i=prefix.length()-1; i >= 0; i--) reasult += prefix[i];
    return reasult;
}

int main() {
    std::string infixExpr = "(A+B*C$D)/((E+F-G)*H)$I/J";    // //+A*B$CD$*-+EFGHIJ

    std::cout << InfixToPrefix(infixExpr) << std::endl;

    return 0;
}