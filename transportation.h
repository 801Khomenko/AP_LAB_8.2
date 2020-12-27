#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_ELEMENTS 20
#define	BUFF_SIZE 200

enum	vehicle
{
	BUS,
	MARSHRUTKA,
	TRAM,
	TROLLEY,
};

typedef struct		s_routes
{
	enum vehicle	type;
	int				number;
	char			*start_point;
	char			*end_point;
	int				n_stops;
	int				time;
}					t_routes;

// typedef union		e_var
// {
// 	char			option;
// 	enum vehicle	type;
// 	int				number;
// 	char			*start_point;
// 	char			*end_point;
// 	int				n_stops;
// 	int				time;
// }					t_var;

void	error(char *str);
void	clear_screen(void);
void	press_enter_to_continue(void);

int		read_file(const char *fname, t_routes *route);
void	search(t_routes *route, int route_count);
void	show_data(t_routes *route, int route_count);
void	print_route(t_routes *route, int s_len, int e_len);
void	show_one_by_one(t_routes *route, int route_count);
void	sort(t_routes *route, int route_count);

void 	jaba(int n);