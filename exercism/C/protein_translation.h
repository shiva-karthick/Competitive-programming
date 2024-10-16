#ifndef PROTEIN_TRANSLATION_H // include guard
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_PROTEINS 10

typedef enum
{
    Methionine,
    Phenylalanine,
    Leucine,
    Serine,
    Tyrosine,
    Cysteine,
    Tryptophan,
    Stop,
} protein_t;

typedef struct
{
    const char codon[3];
    protein_t protein;
} codon_t;

typedef struct
{
    bool valid;
    size_t count;
    protein_t proteins[MAX_PROTEINS];
} proteins_t;

static protein_t translate(char *text);
proteins_t proteins(const char *const rna);

#endif
