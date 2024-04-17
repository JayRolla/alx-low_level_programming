#include "hash_tables.h"


/**
 * Implements the djb2 algorithm.
 * @str: String to be hashed.
 * Returns the hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) ^ c;  /* hash * 33 XOR c */

    return (hash);
}
