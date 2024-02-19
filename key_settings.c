#include "fdf.h"


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
