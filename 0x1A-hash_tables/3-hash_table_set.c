#include "hash_tables.h"

/**
 * Adds or updates an element in the hash table.
 * @ht: Pointer to the hash table.
 * @key: The key, cannot be an empty string.
 * @value: The value to associate with the key.
 * Returns 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *node;
    unsigned long int idx;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    idx = key_index((const unsigned char *)key, ht->size);
    node = malloc(sizeof(hash_node_t));
    if (!node)
        return (0);

    node->key = strdup(key);
    node->value = strdup(value);
    node->next = ht->array[idx];
    ht->array[idx] = node;

    return (1);
}
