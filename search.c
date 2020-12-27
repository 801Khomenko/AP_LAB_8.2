#include "transportation.h"

void	search_by_transport_type(int type, t_routes *route, int route_count)
{
	int		i, s_len, e_len, new_len;

	s_len = 0;
	e_len = 0;
	for (i = 0; i < route_count; i++)
		if (route[i].type == type)
		{
			// довжина нової стрічки
			new_len = strlen(route[i].start_point);
			// якщо нова стрічка довша ніж попередня найдовша
			if (new_len > s_len)
			// зберігаємо нову найдовшу 
				s_len = new_len;
			new_len = strlen(route[i].end_point);
			if (new_len > e_len)
				e_len = new_len;
		}
	clear_screen();
	for (i = 0; i < route_count; i++)
		if (route[i].type == type)
			print_route(route + i, s_len, e_len);
	press_enter_to_continue();
}

void	transport_options(t_routes *route, int route_count)
{
	char c;

	clear_screen();
	printf(
	"Search by:\n"
	"1 - Bus\n"
	"2 - Marshrutka\n"
	"3 - Tram\n"
	"4 - Trolley\n"
	"0 - Back\n"
	"Enter option: ");
	c = 0;
	while (c < '0' || c > '4')
		scanf(" %c", &c);
	if (c == '0')
		return ;
	search_by_transport_type((int)(c - 48 - 1), route, route_count);
}

void	search_by_number(t_routes *route, int route_count)
{
	char 	buff[10];
	int 	i, s_number, s_len, e_len, new_len;

	clear_screen();
	printf("Enter route number: ");
	scanf("%s", buff);
	s_number = atoi(buff);
	s_len = 0;
	e_len = 0;
	for(i = 0; i < route_count; i++)
		if (route[i].number == s_number)
		{
			new_len = strlen(route[i].start_point);
			if (new_len > s_len)
				s_len = new_len;
			new_len = strlen(route[i].end_point);
			if (new_len > e_len)
				e_len = new_len;
		}
	clear_screen();
	if (s_len == 0)
		printf("No route found\n");
	else
		for(i = 0; i < route_count; i++)
			if (s_number == route[i].number)
				print_route(route + i, s_len, e_len);
	press_enter_to_continue();
}

void	search_by_start(t_routes *route, int route_count)
{
	char 	buff[BUFF_SIZE];
	int 	i, s_len, e_len, new_len;

	clear_screen();
	printf("Enter part of the start point: ");
	scanf("%s", buff);
	s_len = 0;
	e_len = 0;
	for(i = 0; i < route_count; i++)
		if (strstr(route[i].start_point, buff))
		{
			new_len = strlen(route[i].start_point);
			if (new_len > s_len)
				s_len = new_len;
			new_len = strlen(route[i].end_point);
			if (new_len > e_len)
				e_len = new_len;
		}
	clear_screen();
	if (s_len == 0)
		printf("No route found\n");
	else
		for(i = 0; i < route_count; i++)
			if (strstr(route[i].start_point, buff))
				print_route(route + i, s_len, e_len);
	press_enter_to_continue();
}

char	print_search_message(void)
{
	char c;

	clear_screen();
	printf(
	"Search by:\n"
	"1 - Transport\n"
	"2 - Route number\n"
	"3 - Start point\n"
	"4 - End point\n"
	"0 - Back\n"
	"Enter option: ");
	c = 0;
	while (c < '0' || c > '4')
		scanf(" %c", &c);
	return (c);
}

void	search_by_end(t_routes *route, int route_count)
{
	char 	buff[BUFF_SIZE];
	int 	i, s_len, e_len, new_len;

	clear_screen();
	printf("Enter part of the end point: ");
	scanf("%s", buff);
	s_len = 0;
	e_len = 0;
	for(i = 0; i < route_count; i++)
		if (strstr(route[i].end_point, buff))
		{
			new_len = strlen(route[i].start_point);
			if (new_len > s_len)
				s_len = new_len;
			new_len = strlen(route[i].end_point);
			if (new_len > e_len)
				e_len = new_len;
		}
	clear_screen();
	if (s_len == 0)
		printf("No route found\n");
	else
		for(i = 0; i < route_count; i++)
			if (strstr(route[i].end_point, buff))
				print_route(route + i, s_len, e_len);
	press_enter_to_continue();
}

void	search_options(char c, t_routes *route, int route_count)
{
	while (c != '0')
	{
		if (c == '1')
			transport_options(route, route_count);
		else if (c == '2')
			search_by_number(route, route_count);
		else if (c == '3')
			search_by_start(route, route_count);
		else if (c == '4')
			search_by_end(route, route_count);
		c = print_search_message();
	}
}

void	search(t_routes *route, int route_count)
{
	char	c;

	c = print_search_message();	
	search_options(c, route, route_count);
}