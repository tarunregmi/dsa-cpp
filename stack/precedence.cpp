int precedence(char opr) {
    switch (opr) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': case '$': return 3;
        default: return -1;
    }
}