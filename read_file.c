#include "transportation.h"

char	*my_strndup(const char *s, size_t n)
{
	char	*p;
	size_t	n1;

	for (n1 = 0; n1 < n && s[n1] != '\0'; n1++)
		continue;
	p = malloc(n + 1);
	if (p != NULL)
	{
		memcpy(p, s, n1);
		p[n1] = '\0';
	}
	return (p);
}

void	parse_string(t_routes *route, char *buff)
{
	char	*ptr;
	char	*ptr2;

	route->type = atoi(buff);
	ptr = strchr(buff, ' ');
	route->number = atoi(ptr);
	// початкова станція
	ptr = 1 + strchr(buff, '\"');
	ptr2 = strchr(ptr, '\"');
	route->start_point = my_strndup(ptr, ptr2 - ptr);
	//кінцева станція
	ptr = 1 + strchr(ptr2 + 1, '\"');
	ptr2 = strchr(ptr, '\"');
	route->end_point = my_strndup(ptr, ptr2 - ptr);
	ptr = ptr2 + 2;
	route->n_stops = atoi(ptr);
	ptr = strchr(ptr + 1, ' ');
	route->time = atoi(ptr);
	// printf("%d ", route->type);
	// printf("%d ", route->number);
	// printf("%s ", route->start_point);
	// printf("%s ", route->end_point);
	// printf("%d ", route->n_stops);
	// printf("%d\n", route->time);
}

int		read_file(const char *fname, t_routes *route)
{    
	int		route_count;       
	char	buff[BUFF_SIZE];
	FILE	*file;

	file = fopen(fname, "r");
	if (file == NULL)
		error(strerror(errno));
	for (route_count = 0; fgets(buff, BUFF_SIZE, file); route_count++)
		parse_string(route + route_count, buff);
	fclose(file);
	return (route_count);
}