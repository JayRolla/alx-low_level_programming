#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 *
 * This function frees all memory allocated for the hash table,
 * including the nodes in each linked list and the array itself.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *node, *temp;
    unsigned long int i;

    if (ht == NULL) {
        return;
    }

    /* Iterate over each slot in the array */
    for (i = 0; i < ht->size; i++) {
        node = ht->array[i];
        /* Free all nodes in the linked list at this slot */
        while (node != NULL) {
            temp = node;
            node = node->next;
            free(temp->key);   /* Free the key string */
            free(temp->value); /* Free the value string */
            free(temp);        /* Free the node itself */
        }
    }
    free(ht->array); /* Free the array of pointers */
    free(ht);        /* Finally, free the hash table structure */
}
