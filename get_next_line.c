#include "get_next_line.h"

int get_next_line(int fd)
{
	char	*read__ = malloc(sizeof(char)*BUFFER_SIZE + 1);
	read(fd, read__, BUFFER_SIZE);
	tmp = malloc(sizeof(char *)*100);
	int howmany_of_n = howmany_of_n_func(read__);
	int	*locations__n = malloc(sizeof(int) * howmany_of_n);
	locations__n_func(locations__n, read__);
	static int where_w = 0;

	return where_w;
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%d|",get_next_line(fd));
}
