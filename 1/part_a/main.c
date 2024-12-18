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
	int *temp = ft_calloc(length + 1, sizeof(int));
	if (!temp)
		return (NULL);

	while (i < length)
	{
		temp[i] = one[i];
		i++;
	}
	i = 0;
	int j = 0;
	while (i < length - 1)
	{
		j = 0;
		while(j < length - 1)
		{
			if (temp[j] > temp[j + 1])
			{
				int *temp1 = ft_calloc(1, sizeof(int));
				*temp1 = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = *temp1;
				free(temp1);
			}
			j++;
		}
		i++;
	}
	return (temp);
}

int	*calculate_distances(int *one_sorted, int *two_sorted, int length)
{
	int *distances = ft_calloc(length, (sizeof(int)));
	if (!distances)
		return (NULL);
	int i = 0;
	while (i < length)
	{
		if (one_sorted[i] > two_sorted[i])
			distances[i] = one_sorted[i] - two_sorted[i];
		else if (one_sorted[i] < two_sorted[i])
			distances[i] = two_sorted[i] - one_sorted[i];
		i++;
	}
	return (distances);
}

int find_result(int *distances, int length)
{
	int i = 0;
	int sum = 0;
	while(i < length)
	{
		sum += distances[i];
		i++;
	}
	return (sum);
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
	int *one_sorted = bubble_sort(one, length);
	if (!one_sorted)
		return (1);
	int *two_sorted = bubble_sort(two, length);	
	if (!two_sorted)
		return (free(one), free(two), free(one_sorted), 1);
	int *distances = calculate_distances(one_sorted, two_sorted, length);
	if (!distances)
		return (free(one), free(two), free(one_sorted), free(two_sorted), 1);
	int sum = find_result(distances, length);
	printf("Sum of distances is: %i\n", sum);
	free(one);
	free(one_sorted);
	free(two);
	free(two_sorted);
	free(distances);
	return (0);
}
