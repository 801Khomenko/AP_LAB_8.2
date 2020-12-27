#include "transportation.h"

void	show_one_by_one(t_routes *route, int route_count)
{
	int		i, s_len, e_len, new_len;
	char	c;

	s_len = 0;
	e_len = 0;
	for(i = 0; i < route_count; i++)
	{
		new_len = strlen(route[i].start_point);
		if (new_len > s_len)
			s_len = new_len;
		new_len = strlen(route[i].end_point);
		if (new_len > e_len)
			e_len = new_len;
	}
	i = 0;
	while (1)
	{
		clear_screen();
		print_route(route + i, s_len, e_len);
		printf(
				"\nw - Move up\n"
				"s - Move down\n"
				"0 - Back\n"
				"4Enter option: \n");
		scanf(" %c", &c);
		if (c == 'w' && i > 0)
			i--;
		else if (c == 's' && i < (route_count - 1))
			i++;	
		else if (c == '0')
			return ;
	}
} 