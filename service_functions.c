#include "transportation.h"

void	clear_screen(void)
{
	system("cls");
}

void	error(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit(-1);
}

void	press_enter_to_continue(void)
{
	char 	enter;

	printf("Press Enter to continue\n");
	getchar();
	while (enter != '\r' && enter != '\n')
		enter = getchar();
}

void	print_route(t_routes *route, int s_len, int e_len)
{
	char	*vname[] = {"Bus", "Marshrutka", "Tram", "Trolley"};

	printf("%-10s | %-3d | %-*s | %-*s | %-5d | %-4d\n",
		vname[route->type], route->number, s_len, route->start_point, e_len, route->end_point, route->n_stops, route->time);
}

void 	jaba(int n)
{
	static int i;

	if (n)
		printf("jaba set %d\n", n);
	else
		printf("jaba unset %d\n", i++);
	press_enter_to_continue();
}