#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch){
stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}
int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;
    printf("Name:BHUMIKA SHRINIVAS TELI\nUSN: 1BM24CS072\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);


    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
