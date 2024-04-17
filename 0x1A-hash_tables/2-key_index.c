#include "hash_tables.h"

/**
 * Calculates the index of a key in a hash table.
 * @key: The key.
 * @size: The size of the hash table.
 * Returns the index where the key/value pair is stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
