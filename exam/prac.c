#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
# define ERROR 1

typedef struct s_zone
{
	int width;
	int height;
	char back_ch;
}	t_zone;

typedef struct s_circle
{
	char c;
	float center_x;
	float center_y;
	float radius;
	char circle_ch;
}	t_circle;

int str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void printf_str(char *str)
{
	write(1, str, str_len(str));
}

int init_zone(FILE *fp, t_zone *zone)
{
	int fscanf_ret;

	fscanf = fscanf(fp, "%d %d %c\n", &zone->width, &zone->height, &zone->back_ch);
	return (fscanf_ret != 3 || fscanf_ret == EOF || !(0 < zone->width && zone->width <= 300) || !(0 < zone->height && zone->height <= 300));
}

int init_draw_zone(char draw_zone[300][301], t_zone *zone)
{
	int i;
	int j;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			draw_zone[i][j] = zone->back_ch;
			j++;
		}
		i++;
	}
}

float	distance(float x1, float x2, float y1, float y2)
{
	return (sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2)));
}

void	make_filled_circle(char draw_zone[300][301], t_zone *zone, t_circle *circle)
{
	int	x;
	int	y;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			if (distance(circle->center_x, x, circle->center_y, y) <= circle->radius)
				draw_zone[y][x] = circle->circle_ch;
			x++;
		}
		y++;
	}
}

void	make_empty_circle(char draw_zone[300][301], t_zone *zone, t_circle *circle)
{
	int		x;
	int		y;
	float	dist;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			dist = distance(circle->center_x, x, circle->center_y, y);
			if (dist > circle->radius - 1 && dist <= circle->radius)
				draw_zone[y][x] = circle->circle_ch;
			x++;
		}
		y++;
	}
}

int print_circles(FILE *fp, t_zone *zone)
{
	int			fscanf_ret;
	t_circle	circle;
	char		draw_zone[300][301];

	init_draw_zone(draw_zone, zone);
	while (1)
	{
		fscanf_ret = fscanf(fp, "%c %f %f %f %c\n", &circle.c, &circle.center_x, &circle.center_y, &circle.circle_ch);
		if (fscanf_ret == EOF)
		{
			print_draw_zone(draw_zone, zone);
			return (0);
		}
		if (fscanf_ret != 5 || circle.radius <= 0)
			return (1);
		if (circle.c == 'c')
			make_empty_circle(draw_zone, zone, &circle);
		else if (circle.c == 'C')
			make_filled_circle(draw_zone, zone, &circle);
		else
			return (1);
	}
}

int main(int argc, char *argv[])
{
	FILE		*fp;
	t_zone		zone;

	if (argc != 2)
	{
		printf_str("Error: argument\n");
		return (1);
	}

	fp = fopen(argv[1], "r");

	if (fp = NULL)
	{
		printf_str("Error: Operation file corrupted\n");
		return (1);
	}

	if (init_zone(fp, &zone) == ERROR)
	{
		print_str("Error: Operation file corrupted\n");
		fclose(fp);
		return (1);
	}

	if (print_circles(fp, &zone) == ERROR)
	{
		printf_str("Error: Operation file corrupted\n");
		fclose(fp);
		return (1);
	}

	fclose(fp);
	return (0);
}