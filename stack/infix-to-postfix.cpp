#include <iostream>
#include "./auto-stack.cpp"
#include "./precedence.cpp"

std::string InfixToPostfix(const std::string& infix) {
    std::string postfix;
    AutoStack <char> oprStack;

    for (char c: "(" + infix + ")") {
        if (c == '(') oprStack.push(c);
        else if (std::isalnum(c)) postfix += c;
        else if (c == ')') {
            while (oprStack.top() != '(') {
                postfix += oprStack.top();
                oprStack.pop();
            }
            oprStack.pop(); // popping '('
        } else {
            while (!oprStack.isEmpty() && precedence(oprStack.top()) >= precedence(c)) {
                postfix += oprStack.top();
                oprStack.pop();
            }
            oprStack.push(c);
        }
    }

    return postfix;
}

int main() {
    std::string infixExpr = "(A+B*C$D)/((E+F-G)*H)$I/J";    // ABCD$*+EF+G-H*I$/J/
    // infixExpr = "A+(B*C-(D/E-F)*G)*H";                      // ABC*DE/F-G*-H*+
    // infixExpr = "((A-(B+C))*D)$(E+F)";                      // ABC+-D*EF+$

    std::cout << InfixToPostfix(infixExpr) << std::endl;

    return 0;
}