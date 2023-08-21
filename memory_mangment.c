#include "shell.h"

/**
 **_mem_realloc -  Reallocates A Memory Block Using Malloc And Free
 *@ptr: Pointer
 *@old_size: Previous Size Of The Pointer
 *@new_size: New Size Of The Pointer
 *Return: Void Pointer Rellocated Memory
 */
void *_mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		copy_memory(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - Free Array Of Char Pointer And Char Pointer
 * @cmd: Array Pointer
 * @line: Char Pointer
 * Return: Void
 */
void free_all_strings(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * copy_memory - Copy Bytes From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Many Bytes To Copy)
 * Return: Void Pointer
 */
char *copy_memory(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_array - Fill An Array With A Given Element
 * @array: Void Pointer
 * @element: Int
 * @length: Length Int
 * Return: Void Pointer
 */
void *fill_array(void *array, int element, unsigned int length)
{
	char *ptr = array;
	unsigned int i = 0;

	while (i < length)
	{
		*ptr = element;
		ptr++;
		i++;
	}
	return (array);
}

/**
 * allocate_memory - Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *allocate_memory(unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		ptr[i] = '\0';
	}
	return (ptr);
}
