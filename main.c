#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 300

typedef struct s_data{
	void	*mlx;
	void	*win;
}				t_mlx_data;

int	handle_board(int keysym, t_mlx_data *data)
{
	if (keysym == 65307)
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


int	main(void)
{
	t_mlx_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	mlx_key_hook(data.win, handle_board, &data);
	mlx_loop(data.mlx);
	return (0);
}
