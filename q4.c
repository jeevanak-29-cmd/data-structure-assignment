#include <stdio.h>

char stack[20];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

int main() {
    char exp[50];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                printf("Invalid Expression");
                return 0;
            }
            pop();
        }
    }

    if (top == -1)
        printf("Valid Expression");
    else
        printf("Invalid Expression");
}