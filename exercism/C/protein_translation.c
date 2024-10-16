#include <stdio.h>
#include "protein_translation.h"
#include <string.h>
#include <assert.h>

static const codon_t CODONS[] = {
    {"AUG", Methionine},
    {"UUU", Phenylalanine},
    {"UUC", Phenylalanine},
    {"UUA", Leucine},
    {"UUG", Leucine},
    {"UCU", Serine},
    {"UCC", Serine},
    {"UCA", Serine},
    {"UCG", Serine},
    {"UAU", Tyrosine},
    {"UAC", Tyrosine},
    {"UGU", Cysteine},
    {"UGC", Cysteine},
    {"UGG", Tryptophan},
    {"UAA", Stop},
    {"UAG", Stop},
    {"UGA", Stop},
};

static protein_t translate(char *text)
{
    for (size_t i = 0; i < (sizeof(CODONS) / sizeof(CODONS[0])); i += 1)
    {
        if (!strncmp(text, CODONS[i].codon, 3))
        {
            return CODONS[i].protein;
        }
    }
}

proteins_t proteins(const char *const rna)
{
    // The parameter rna is a pointer to a constant character (string) that itself is a constant.
    // The function proteins accepts a constant pointer to a constant character array (const char *const rna), meaning it can read the RNA sequence but cannot modify it.
    // It returns a value of type proteins_t, which is likely a structure or type representing information about proteins derived from the RNA sequence.
    assert(rna);
    proteins_t proteins = {
        true,
        0,
        {0},
    };

    size_t length = strlen(rna);
    printf("length is : %zu \n", length);

    for (u_int64_t index = 0; index < length; index += 3)
    {
        char buffer[3 + 1]; // Need to account for the NULL character
        memcpy(buffer, &rna[index], 3);
        protein_t protein = translate(buffer);

        if (protein == Stop)
        {
            break;
        }
        else
        {
            proteins.proteins[proteins.count] = protein;
            proteins.count += 1;
        }
    }
    return proteins;
}

int main(void)
{
    char *test = "AUGUUUUCU";

    proteins_t result = proteins(test);
    printf("Nmuber of prtns: %zu \n", result.count);
    for (u_int64_t index = 0; index < result.count; index += 1)
    {
        printf("%u \n", result.proteins[index]);
    }
    return 0;
}
