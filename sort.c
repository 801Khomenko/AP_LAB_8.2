#include "transportation.h"

int 	cmp_transport(t_routes a, t_routes b)
{
	if (a.type > b.type)
		return 1;
	return 0;
}

int 	cmp_number(t_routes a, t_routes b)
{
	if (a.number > b.number)
		return 1;
	return 0;
}

int 	cmp_start_point(t_routes a, t_routes b)
{
	if (strcmp(a.start_point, b.start_point) > 0)
		return 1;
	return 0;
}

int 	cmp_end_point(t_routes a, t_routes b)
{
	if (strcmp(a.end_point, b.end_point) > 0)
		return 1;
	return 0;
}


void	sort_by_parameter(t_routes *route, int route_count, int (*cmp)(t_routes, t_routes))
{
	int			i, j;
	t_routes	bucket;


	char c;


	for (j = 0; j < route_count; j++)
	{
		for (i = 0; i < route_count - 1 - j; i++)
		{
			if ((*cmp)(route[i], route[i + 1]))
			{
				bucket = route[i];
				route[i] = route[i + 1];
				route[i + 1] = bucket;
			}
		}
	}
}

char	print_sort_message(void)
{
	char c;

	clear_screen();
	printf(
	"Sort by:\n"
	"1 - Type\n"
	"2 - Number\n"
	"3 - Start point\n"
	"4 - End point\n"
	"0 - Back\n"
	"Enter option: ");
	c = 0;
	while (c < '0' || c > '4')
		scanf(" %c", &c);
	return (c);
}

int		save_question(void)
{
	char c;

	printf("\n"
	"1 - Save\n"
	"0 - Back\n"
	"Enter option: ");
	
	c = 0;
	while (c < '0' || c > '1')
		scanf(" %c", &c);
	
	if(c == '1')
		return 1;
	return 0;
}

void	sort_options(char c, t_routes *route, int route_count)
{
	t_routes	cp_route[route_count];
	int			i;
	
	clear_screen();
	while (c != '0')
	{
		for(i = 0; i < route_count; i++)
			cp_route[i] = route[i];
		if (c == '1')
			sort_by_parameter(cp_route, route_count, cmp_transport);
		else if (c == '2')
			sort_by_parameter(cp_route, route_count, cmp_number);
		else if (c == '3')
			sort_by_parameter(cp_route, route_count, cmp_start_point);
		else if (c == '4')
			sort_by_parameter(cp_route, route_count, cmp_end_point);
		show_data(cp_route, route_count);
		
		
		if(save_question())
			for(i = 0; i < route_count; i++)
				route[i] = cp_route[i];
			
		c = print_sort_message();
	}
}

void	sort(t_routes *route, int route_count)
{
	char	c;

	c = print_sort_message();
	sort_options(c, route, route_count);
}