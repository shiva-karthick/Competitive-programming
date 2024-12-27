#include "run_length_encoding.h"
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_LEN 1024

int main(int argc, char const *argv[])
{
    char *compressed_buffer = encode("AABBBCCCC");
    return 0;
}
char *encode(const char *text)
{
    char *output = calloc(OUTPUT_LEN, 1);
    char *ptr_x = output; // Store the pointer memory address of the output buffer to ptr_x

    uint8_t original_value = 0; // Current value being written to the output buffer
    uint64_t count = 0;         // Number of bits needed for value

    uint64_t length = strlen(text);
    printf("length : %llu", length);

    for (uint64_t index = 0; index < length; index += 1)
    {
        // current value being written to the buffer
        original_value = (uint8_t)text[index];
        if (count == 0)
        {
            count += 1;
            continue;
        }
        else if (count > 0 && (uint8_t)text[index] == original_value)
        {
            count += 1;
            continue;
        }
        else if (count > 0 && (uint8_t)text[index] != original_value)
        {
            // Concatenate
            original_value = text[index]; // replace the original value
        }
    }
}
char *decode(const char *data)
{
}