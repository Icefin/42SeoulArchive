#include <mlx.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

enum EVENT {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum KEYCODE {
	KEY_ESCAPE = 53,

	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

typedef struct s_vars {
	void *mlx;
	void *window;
}	t_vars;

int close(int keycode, t_vars *vars) {
	if (keycode == KEY_ESCAPE) {
		mlx_destroy_window(vars->mlx, vars->window);
	}
	return 0;
}

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) {
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void) {
	t_vars vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	mlx_hook(vars.window, ON_KEYDOWN, 1L<<0, close, &vars);
	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	for (int x = 400; x < 1000; x++) {
		for (int y = 300; y < 600; y++) {
			my_mlx_pixel_put(&img, x, y, 0x00ff0000);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
