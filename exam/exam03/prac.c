#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define ERROR 1
#define SUCCESS 0

typedef struct s_zone
{
	int		width;
	int		height;
	char	back_ch;
}	t_zone;

typedef struct s_circle
{
	char	c;
	float	center_x;
	float	center_y;
	float	radius;
	char	circle_ch;
}	t_circle;

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void print_str(char *str)
{
	write(1, str, ft_strlen(str));
}

int init_zone(FILE *fp, t_zone *zone)
{
	int fscanf_result;

	fscanf_result = fscanf(fp, "%d %d %c\n", &zone->width, &zone->height, &zone->back_ch);
	return (fscanf_result != 3 || fscanf_result == EOF || \
			!(0 < zone->width && zone->width <= 300) || \
			!(0 < zone->height && zone->height <= 300));
}

void print_result(char board[300][301], t_zone *zone)
{
	int i;
	
	i = 0;
	while (i < zone->height)
	{
		board[i][zone->width] = '\0';
		print_str(board[i]);
		write(1, "\n", 1);
		i++;
	}
}

float get_distance(float x1 , float x2, float y1, float y2)
{
	return (sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2)));
}

void make_empty_circle(char board[300][301], t_zone *zone, t_circle *circle)
{
	int		i;
	int		j;
	float	distance;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			distance = get_distance(circle->center_x, j, circle->center_y, i);
			if ((distance > circle->radius - 1) && (distance <= circle->radius))
				board[i][j] = circle->circle_ch;
			j++;
		}
		i++;
	}
}

void init_board(char board[300][301], t_zone *zone)
{
	int i;
	int j;
	
	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			board[i][j] = zone->back_ch;
			j++;
		}
		i++;
	}
}

int print_circles(FILE *fp, t_zone *zone)
{
	int fscanf_result;
	t_circle circle;
	char board[300][301];

	init_board(board, zone);
	while (1)
	{
		fscanf_result = fscanf(fp, "%c %f %f %f %c\n", \
								&circle.c, &circle.center_x, &circle.center_y, \
								&circle.radius, &circle.circle_ch);
		if (fscanf_result == EOF)
		{
			print_result(board, zone);
			return (SUCCESS);
		}
		if (fscanf_result != 5 || circle.radius <= 0)
			return (ERROR);
		if (circle.c == 'c')
			make_empty_circle(board, zone, &circle);
		else
			return (ERROR);
	}
}

int main(int argc, char **argv)
{
	FILE	*fp;
	t_zone	zone;

	if (argc != 2)
	{
		print_str("Error: argument\n");
		return (ERROR);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		print_str("Error: Operation file corrupted1\n");
		return (ERROR);
	}
	if (init_zone(fp, &zone) == ERROR)
	{
		print_str("Error: Operation file corrupted2\n");
		fclose(fp);
		return (ERROR);
	}
	if (print_circles(fp, &zone) == ERROR)
	{
		print_str("Error: Operation file corrupted3\n");
		fclose(fp);
		return (ERROR);
	}
}