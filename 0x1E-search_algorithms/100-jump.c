#include "search_algos.h"
/**
 * binary_search - function that searches for a value in a sorted array of 
 *                 integers using the Binary search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size:   is the number of elements in array
 * @value:  is the value to search for
 *
 * Return:  Must return the index where value is located 
 *          If value is not present in array or if array is NULL, 
 *          your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t low = 0, i = 0, high = 3;
	size = size - 1;
	while (high <= size || low <= size)
	{
		printf("Value checked array[%zu] = [%zu]\n", low, low);  

		if (value <= array[high] || high > size)
		{

			printf("Value found between indexes [%zu] and [%zu]\n",
				low, high);
			i = low;
			while(i <= size || i <= high)
			{
				
				printf("Value checked array[%zu] = [%d]\n", i, 
					array[i]);

				if (array[i] == value)
					return (i);

				if (i == size || i == high)
					return (-1);
				i++;
			}
		}
		low = high;
		high = high + 3;
	}
	return (-1);
}
