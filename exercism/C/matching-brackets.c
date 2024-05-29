#include "../header-files/common.h"
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define STACK_SIZE (100)

typedef struct stack_t
{
    char data[STACK_SIZE];
    size_t index;
} stack_t;

void push(stack_t *stack, char element);
void pop(stack_t *stack);
char top(stack_t *stack);
bool is_empty(stack_t *stack);

bool opening(char c);
bool closing(char c);
bool match(char opening, char closing);

void push(stack_t *stack, char element)
{
    (*stack).data[(*stack).index] = element;
    /* Increment the index */
    (*stack).index += 1;
}

void pop(stack_t *stack)
{
    (*stack).index -= 1;
    stack->data[stack->index] = 0;
}

char top(stack_t *stack)
{
    return stack->data[stack->index - 1];
}

bool is_empty(stack_t *stack)
{
    return stack->index == 0;
}

bool opening(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool closing(char c)
{
    return c == ')' || c == '}' || c == ']';
}

bool match(char opening, char closing)
{
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

bool is_paired(const char *input)
{
    stack_t stack = {0};
    bool error = false;

    if (NULL == input)
    {
        return false;
    }

    while (*input != '\0')
    {
        if (opening(*input))
        {
            push(&stack, *input);
        }
        else if (closing(*input))
        {
            if (match(top(&stack), *input))
            {
                pop(&stack);
            }
            else
            {
                error = true;
                break;
            }
        }
        input += 1;
    }

    return !error && is_empty(&stack);
}

int main(int argc, char const *argv[])
{
    const char *input = "(((185 + 223.85) * 15) - 543)/2";
    printf("is_paired(%s): %d\n", input, is_paired(input));
    return 0;
}
