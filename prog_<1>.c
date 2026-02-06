#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

struct stack {
    char items[MAX];
    int top;
};

void push(struct stack *s, char element) {
    s->items[++(s->top)] = element;
}

char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->items[(s->top)--];
}

bool is_empty(struct stack *s) {
    return s->top == -1;
}

bool evaluate(char* expression) {
    struct stack string;
    string.top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&string, c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (is_empty(&string)) {
                return false;
            }

            char top_element = pop(&string);
            
            // Implementation of your endmap logic
            if (c == ')' && top_element != '(') return false;
            if (c == ']' && top_element != '[') return false;
            if (c == '}' && top_element != '{') return false;
        }
    }

    return is_empty(&string);
}

int main() {
    char expression1[] = "a+(b-c)*(d";
    printf("%s\n", evaluate(expression1) ? "correct" : "false");

    char expression2[] = "m + [a - b * (c + d * {m)]";
    printf("%s\n", evaluate(expression2) ? "correct" : "false");

    char expression3[] = "a+(b-c)";
    printf("%s\n", evaluate(expression3) ? "correct" : "false");

    return 0;
}
