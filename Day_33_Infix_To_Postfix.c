/*
 * Day 33 - Infix to Postfix Conversion
 *
 * Problem:
 * Convert an infix expression to postfix notation using a stack.
 *
 * Input:
 * - Single line: infix expression
 * - Operands are single characters.
 *
 * Output:
 * - Print the postfix expression.
 *
 * Example:
 * Input:
 * A+B*C
 *
 * Output:
 * ABC*+
 *
 * Explanation:
 * Operator precedence:
 * * > +
 *
 * The stack is used to handle operator precedence
 * and associativity.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    stack[++top] = value;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '^') {
        return 3;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '+' || op == '-') {
        return 1;
    }

    return 0;
}

int main() {
    char infix[MAX];

    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            printf("%c", ch);
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }

            if (top != -1) {
                pop();  
            }
        }

        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch)) {
                printf("%c", pop());
            }

            push(ch);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
