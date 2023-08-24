#include "shell.h"

/**
 * _realloc - Reallocates A Memory Block Using Malloc And Free
 * @ptr: Pointer
 * @old_size: Previous Size Of The Pointer
 * @new_size: New Size Of The Pointer
 * Return: Void Pointer Rellocated Memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
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
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - Free Array Of Char Pointer And Char Pointer
 * @cmd_array: Array Pointer
 * @input_line: Char Pointer
 * Return: Void
 */
void free_all(char **cmd_array, char *input_line)
{
	free(cmd_array);
	free(input_line);
	cmd_array = NULL;
	input_line = NULL;
}

/**
 * _memcpy - Copy Bytes From Source To Destination
 * @destination: Destination Pointer
 * @source: Source Pointer
 * @num_bytes: Number Of Bytes To Copy
 * Return: Void Pointer
 */
char *_memcpy(char *destination, char *source, unsigned int num_bytes)
{
	for (unsigned int i = 0; i < num_bytes; i++)
	{
		destination[i] = source[i];
	}
	return (destination);
}

/**
 * fill_with_char - Fill An Array With A Specified Character
 * @array: Void Pointer
 * @character: Character To Fill With
 * @length: Length Of The Array
 * Return: Void Pointer
 */
void *fill_with_char(void *array, int character, unsigned int length)
{
	char *pointer = array;

	for (unsigned int i = 0; i < length; i++)
	{
		*pointer = character;
		pointer++;
	}
	return (array);
}

/**
 * _calloc - Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{

	char *allocated_memory = malloc(size);

	if (allocated_memory == NULL)
		return (NULL);
	for (unsigned int i = 0; i < size; i++)
	{
		allocated_memory[i] = '\0';
	}
	return (allocated_memory);
}
