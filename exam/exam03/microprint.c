# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define ERROR 1

typedef struct s_zone
{
	int		width;
	int		height;
	char	back_ch;
}	t_zone;

typedef struct s_rectangle
{
	char	r;
	float	top_left_x;
	float	top_left_y;
	float	width;
	float	height;
	char	rectangle_ch;
}	t_rectangle;

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	print_str(char *str)
{
	write(1, str, ft_strlen(str));
}

int	init_zone(FILE *fp, t_zone *zone)
{
	int	fscanf_ret;

	fscanf_ret = fscanf(fp, "%d %d %c\n", &zone->width, &zone->height, &zone->back_ch);
	return (fscanf_ret != 3 || fscanf_ret == EOF
			|| !(0 < zone->width && zone->width <= 300) || !(0 < zone->height && zone->height <= 300));
}

void	init_draw_zone(char draw_zone[300][301], t_zone *zone)
{
	int	i;
	int	j;

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

void	print_draw_zone(char draw_zone[300][301], t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		draw_zone[i][zone->width] = 0;
		print_str(draw_zone[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	is_in_rectangle(int x, int y, t_rectangle *rectangle)
{
	float	bottom_right_x;
	float	bottom_right_y;

	bottom_right_x = rectangle->top_left_x + rectangle->width;
	bottom_right_y = rectangle->top_left_y + rectangle->height;
	return ((rectangle->top_left_x <= x && x <= bottom_right_x)
				&& (rectangle->top_left_y <= y && y <= bottom_right_y));
}

float	distance(float x1, float x2, float y1, float y2)
{
	return (sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2)));
}

int	is_bound(int x, int y, t_rectangle *rec)
{
	float xx;
	float yy;

	xx = (float)x;
	yy = (float)y;

	if ((rec->top_left_x <= xx && xx <= rec->top_left_x + 1)
			|| (rec->top_left_x + rec->width - 1 <= xx && xx <= rec->top_left_x + rec->width))
	{
		if (rec->top_left_y <= yy && yy <= rec->top_left_y + rec->height)
			return (1);
	}
	if ((rec->top_left_y <= yy && yy <= rec->top_left_y + 1)
			|| (rec->top_left_y + rec->height - 1 <= yy && yy <= rec->top_left_y + rec->height))
	{
		if (rec->top_left_x <= xx && xx <= rec->top_left_x + rec->width)
			return (1);
	}
	return (0);
}

void	make_empty_rectangle(char draw_zone[300][301], t_rectangle *rectangle, t_zone *zone)
{
	int	x;
	int	y;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			if (is_bound(x, y, rectangle))
				draw_zone[y][x] = rectangle->rectangle_ch;
			x++;
		}
		y++;
	}
}

void	make_filled_rectangle(char draw_zone[300][301], t_rectangle *rectangle, t_zone *zone)
{
	int		x;
	int		y;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			if (is_in_rectangle(x, y, rectangle))
				draw_zone[y][x] = rectangle->rectangle_ch;
			x++;
		}
		y++;
	}
}

int	print_rectangles(FILE *fp, t_zone *zone)
{
	int			fscanf_ret;
	t_rectangle	rectangle;
	char		draw_zone[300][301];

	init_draw_zone(draw_zone, zone);
	while (1)
	{
		fscanf_ret = fscanf(fp, "%c %f %f %f %f %c\n", &rectangle.r, &rectangle.top_left_x, &rectangle.top_left_y,
				&rectangle.width, &rectangle.height, &rectangle.rectangle_ch);
		if (fscanf_ret == EOF)
		{
			print_draw_zone(draw_zone, zone);
			return (0);
		}
		if (fscanf_ret != 6 || rectangle.height <= 0 || rectangle.width <= 0)
			return (1);
		if (rectangle.r == 'r')
			make_empty_rectangle(draw_zone, &rectangle, zone);
		else if (rectangle.r == 'R')
			make_filled_rectangle(draw_zone, &rectangle, zone);
		else
			return (1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_str("Error: argument\n");
		return (1);
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		print_str("Error: Operation file corrupted\n");
		return (1);
	}

	t_zone zone;
	if (init_zone(fp, &zone) == ERROR)
	{
		print_str("Error: Operation file corrupted\n");
		fclose(fp);
		return (1);
	}

	if (print_rectangles(fp, &zone) == ERROR)
	{
		print_str("Error: Operation file corrupted\n");
		fclose(fp);
		return (1);
	}

	fclose(fp);
	return (0);
}