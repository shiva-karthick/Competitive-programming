#include "../header-files/common.h"

#include <stdbool.h>

char *hey_bob(char *greeting)
{

    size_t len = strlen(greeting);
    bool is_empty = true;
    bool is_question = false;
    bool is_yelling = true;
    bool yelled = false;

    for (size_t i = 0; i < len; i += 1)
    {
        if (is_empty && !isspace(greeting[i]))
        {
            is_empty = false;
        }
        if (greeting[i] == '?')
        {
            is_question = true;
        }
        if (isalnum(greeting[i]))
        {
            is_question = false;
            // make sure that ? is placed at the end of the string
        }
        if (islower(greeting[i]))
        {
            is_yelling = false;
        }
        if (isupper(greeting[i]))
        {
            yelled = true;
        }
    }

    is_yelling = is_yelling && yelled; // ok
    if (is_empty)
    {
        return "Fine. Be that way!";
    }
    else if (is_question && !is_yelling)
    {
        return "Sure.";
    }
    else if (is_question && is_yelling)
    {
        return "Calm down, I know what I'm doing!";
    }
    else if (is_yelling)
    {
        return "Whoa, chill out!";
    }
    else
    {
        return "Whatever.";
    }
}

int main(int argc, char const *argv[])
{
    char *test_string = "WATCH OU!";
    char *actual = hey_bob(test_string);
    printf("%s\n", actual);
    return 0;
}
