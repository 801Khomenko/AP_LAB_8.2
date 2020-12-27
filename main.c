#include "transportation.h"

/*
 *  парсимо файл, зберігаємо все в масив елементів
 *  робимо діалогове вікно з опціями
 *  опції:
 *    додавання елементу
 *    пошук елементу за якимись характеристиками(номер маршруту, зупинка, вид)
 *    послідовний перегляд елементів
 *    модифікація елементів
 *    видалення елементу
 *    сортування
 *    зберегти
*/

void  main_dialogue_options(char c, t_routes *route, int route_count)
{
	if (c == '1')
	{
		show_data(route, route_count);
		press_enter_to_continue();
	}
	else if (c == '2')
		search(route, route_count);
	else if (c == '3')
		show_one_by_one(route, route_count);
	else if (c == '4')
		sort(route, route_count);
}

/*
головне меню:
показати дані
пошук елементу
послідовний перегляд
сортування
збереження
*/
void  print_main_message(void)
{
	clear_screen();
	printf(
			"Routes information:\n"
			"1 - Show all routes\n"
			"2 - Search\n"
			"3 - See one by one\n"
			"4 - Sort\n"
			"0 - Exit\n"
			"1Enter option: ");
}

void  main_dialogue(t_routes *route, int  route_count)
{
	char c;

	while (1)
	{
		c = 0;
		print_main_message();
		while (c < '0' || c >'4')
			scanf(" %c", &c);
		main_dialogue_options(c, route, route_count);
		if (c == '0')
			return ;
	}
}

int    main(int argc, char **argv)
{
	t_routes  route[MAX_ELEMENTS];
	int      route_count;

	route_count = read_file(argv[1], route);
	main_dialogue(route, route_count);
	return (0);
}