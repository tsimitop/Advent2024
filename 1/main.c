#include <fcntl.h>
#include <stdio.h>
#include "Libft/libft.h"

void	print_array(int *str, int length)
{
	int i = 0;
	while (i < length)
	{
		printf("%i\n", str[i]);
		i++;
	}
}

void	fill_arrays(int *one, int *two, char *line, int i)
{
	char **sp;
	sp = ft_split(line, ' ');
	one[i] = ft_atoi(sp[0]);
	two[i] = ft_atoi(sp[1]);
	free_split(sp);
}

int	*bubble_sort(int *one, int length)
{
	int i = 0;
printf("%i\n", length);
	int *temp = ft_calloc(length + 1, sizeof(int));
	if (!temp)
		return (NULL);

	while (i < length)
	{
		temp[i] = one[i];
// printf("temp[%i] = %i\n", i, temp[i]);
		i++;
	}
	i = 0;
	int j = 0;
	while (i < length - 1)
	{
		j = 0;
printf("temp[%i] = %i\n", i, temp[i]);
		while(j < length - 1)
		{
printf("HI\n");
			if (temp[j] > temp[j + 1])
			{
printf("HO\n");
				// printf("%i--\n", temp[i]);
				int temp1;
				temp1 = temp[j];
				temp[j] = temp[j + 1];
				temp[j + i] = temp1;
				// printf("%i--\n", temp[i]);
printf("HA\n");
			}
			j++;
		}
		i++;
	}
	return (temp);
}


int main(int argc, char **argv)
{
	int file;
	int *one;
	int *two;
	char *line;
	int length;

	if (argc != 2)
	{
		printf("WRONG INPUT\n");
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	line = get_next_line(file);
	int i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(file);
		i++;
	}
	length = i;
	if (line)
		free(line);
	close(file);
	two = ft_calloc(i, sizeof(int *));
	if(!two)
		return (1);
	one = ft_calloc(i, sizeof(int *));
	if(!one)
		return (free(two), 1);
	i = 0;
	file = open(argv[1], O_RDONLY);
	line = get_next_line(file);
	while (line)
	{
		fill_arrays(one, two, line, i);
		free(line);
		line = get_next_line(file);
		i++;
	}
	if (line)
		free(line);
	printf("\n____________________BEFORE____________________\n");
	// print_array(one, length);

// print_array(two, length);
	int *one_sorted = bubble_sort(one, length);
	if (!one_sorted)
		return (1);
	// int *two_sorted = bubble_sort(two, length);	printf("\n____________________AFTER____________________\n");
	printf("\n____________________AFTER____________________\n");

// print_array(one_sorted, length);
// print_array(two, length);

	//create distances
	//find result
	free(one);
	// free(one_sorted);
	free(two);
	// free(two_sorted);
	return (0);
}

// (void)length;
// 	printf("%i\n", one[0]);
// 	printf("%i\n", one[1]);
// 	printf("%i\n", one[2]);
// 	printf("%i\n", one[3]);
// 	printf("%i\n", one[4]);
// 	printf("%i\n", one[5]);
// 	printf("%i\n", one[6]);
// 	printf("%i\n", one[7]);
// 	printf("%i\n", one[8]);