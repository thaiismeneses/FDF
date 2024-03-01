#include "fdf.h"

/*int	arrow_control(int keycode, t_mlx *data)
{
	if (keycode == XK_Up)
		data->shift_y -= 10;
	if (keycode == XK_Down)
		data->shift_y += 10;
	if (keycode == XK_Left)
		data->shift_x -= 10;
	if (keycode == XK_Right)
		data->shift_x += 10;
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}*/


int	key_board(int keycode, t_mlx *data)
{
/*	if (keycode == XK_Up || keycode  == XK_Down || 
			keycode == XK_Left || keycode == XK_Right)
		arrow_control(keycode, data);*/
	if (keycode == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keycode);
		sleep(1);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keycode);
	return (0);	
}
