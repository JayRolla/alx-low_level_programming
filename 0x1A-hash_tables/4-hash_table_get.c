#include "hash_tables.h"

/**
 * Retrieves a value from a hash table based on a key.
 * @ht: The hash table.
 * @key: The key to search for.
 * Returns the associated value, or NULL if the key is not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *node;
    unsigned long int idx;

    if (ht == NULL || key == NULL)
        return (NULL);

    idx = key_index((const unsigned char *)key, ht->size);
    node = ht->array[idx];
    while (node != NULL)
    {
        if (strcmp(key, node->key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}
