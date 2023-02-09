
#include "so_long.h"

int open_map()
{
	char	*line;
	int		fd;
	char	map[1000][1000];
	int		i;
	int		j;

	fd = open("./text.txt", O_RDONLY);
	i = 0;
	while(1)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		while(*(line + j))
		{
			map[i][j] = (char)*(line + j);
			j++;
			printf("%c ", map[i][j]);
		}
		i++;
		printf("\n");
		free(line);
	}
}

int main(void)
{	
	open_map();
	//printf("%d\n", check_component(map));
	return 0;
}