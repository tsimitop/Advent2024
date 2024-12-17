#include <fcntl.h>
#include <stdio.h>
#include "Libft/libft.h"

void	print_array(int *str, int length)
{
	int i = 0;
	(void)str;
	while (i < length)
	{
		// printf("%i\n", str[i]);
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

int	*find_occurence(int *one, int *two, int length)
{
	int i = 0;
	int *temp = ft_calloc(length + 1, sizeof(int));
	if (!temp)
		return (NULL);

	i = 0;
	int j = 0;
	int counter = 0;
	while (i < length)
	{
		j = 0;
		counter = 0;
		while(j < length)
		{
			if (one[i] == two[j])
			{
				counter++;
			}
			j++;
		}
		temp[i] = counter * one[i];
		i++;
	}
	return (temp);
}

// int	*calculate_sum(int *one_sorted, int *two_sorted, int length)
// {
// 	int *distances = ft_calloc(length, (sizeof(int)));
// 	if (!distances)
// 		return (NULL);
// 	int i = 0;
// 	while (i < length)
// 	{
// 		if (one_sorted[i] > two_sorted[i])
// 			distances[i] = one_sorted[i] - two_sorted[i];
// 		else if (one_sorted[i] < two_sorted[i])
// 			distances[i] = two_sorted[i] - one_sorted[i];
// 		i++;
// 	}
// 	return (distances);
// }

int find_result(int *instances, int length)
{
	int i = 0;
	int sum = 0;
	printf("%i\n", length);
	while(i < length)
	{
		printf("%i\n", instances[i]);
		sum += instances[i];
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
	int *instances = find_occurence(one, two, length);
	if (!instances)
		return (free(one), free(two), 1);
	int sum = find_result(instances, length);
	printf("Sum of instances is: %i\n", sum);
	free(one);
	free(two);
	free(instances);
	return (0);
}
