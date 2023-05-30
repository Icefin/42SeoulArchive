#include <mlx.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

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
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	for (int x = 400; x < 1000; x++) {
		for (int y = 300; y < 600; y++) {
			my_mlx_pixel_put(&img, x, y, 0x00ff0000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
