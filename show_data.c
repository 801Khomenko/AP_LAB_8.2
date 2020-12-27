#include "transportation.h"

void	show_data(t_routes *route, int route_count)
{
	int		i, new_len, s_len, e_len;

	clear_screen();
	s_len = 0;
	e_len = 0;
	for (i = 0; i < route_count; i++)
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
	printf("%-10s | %-5s | %-*s | %-*s | Stops | Time\n\n", "Type", "№", s_len, "Start", e_len, "End");
	for (i = 0; i < route_count; i++)
		print_route(route + i, s_len, e_len);
}