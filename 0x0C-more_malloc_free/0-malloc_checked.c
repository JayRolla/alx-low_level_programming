#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: The number of bytes to be allocated.
 *
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(98);
	}

	return (ptr);
}

int main(void)
{
	unsigned int size = 10;
	char *str = malloc_checked(size);

	/* If malloc_checked is successful, str will contain allocated memory
	 * You can use str as needed
	 */

	free(str);  /* Make sure to free the memory when done */
	return (0);
}
