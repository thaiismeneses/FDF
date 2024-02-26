#include "fdf.h"

int	arrow_control(int key, t_mlx *data)
{
	if (key == K_UP)
		data->shift_y -= 10;
	if (key == K_DOWN)
		data->shift_y += 10;
	if (key == K_LEFT)
		data->shift_x -= 10;
	if (key == K_RIGHT)
		data->shift_x += 10;
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

int	key_board(int keysym, t_mlx *data)
{
	if (keysym == K_ESC)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		sleep(1);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);	
}
