#include "cub3d.h"

void my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int my_get_pixel_color(t_img_data *img, int x, int y)
{
    // Calculate the address of the pixel in memory
    char *pixel_addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

    // Get the pixel color based on the image format
    if (img->bits_per_pixel == 32) {
        // If the image is in 32-bit RGBA format
        unsigned int *pixel = (unsigned int *)pixel_addr;
        return *pixel;
    } else if (img->bits_per_pixel == 24) {
        // If the image is in 24-bit RGB format
        unsigned char *pixel = (unsigned char *)pixel_addr;
        // Construct the color from RGB components
        unsigned int color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
        return color;
    } else {
        // Unsupported image format
        return -1;
    }
}

void draw_circle(t_img_data *data, int center_x, int center_y, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        my_mlx_pixel_put(data, center_x + x, center_y + y, color);
        my_mlx_pixel_put(data, center_x + y, center_y + x, color);
        my_mlx_pixel_put(data, center_x - y, center_y + x, color);
        my_mlx_pixel_put(data, center_x - x, center_y + y, color);
        my_mlx_pixel_put(data, center_x - x, center_y - y, color);
        my_mlx_pixel_put(data, center_x - y, center_y - x, color);
        my_mlx_pixel_put(data, center_x + y, center_y - x, color);
        my_mlx_pixel_put(data, center_x + x, center_y - y, color);

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}
void draw_empty_block(t_game *game, int x, int y)
{
    int dx = 0;
    int dy = 0;
    int block_size = BLOCK_SIZE;

    while (dy < block_size)
    {
        dx = 0;
        while (dx < block_size)
        {
            int px = x + dx;
            int py = y + dy;
            my_mlx_pixel_put(game->img, px, py, 0xFFFFFFFF);
            dx++;
        }
        dy++;
    }
}

void draw_wall_block(t_game *game, int x, int y, t_img_data *img)
{
    int dx = 0;
    int dy = 0;
    int block_size = BLOCK_SIZE;

    while (dy < block_size)
    {
        dx = 0;
        while (dx < block_size)
        {
            int px = x + dx;
            int py = y + dy;
            int color = my_get_pixel_color(img, px % BLOCK_SIZE, py % BLOCK_SIZE);
            my_mlx_pixel_put(game->img, px, py, color);
            dx++;
        }
        dy++;
    }
}

void draw_minimap(t_game *game, void *mlx, void *window)
{
    int i = 0;
    int j, x, y;
    int block_size = BLOCK_SIZE;

    while (i < game->map->map_height)
    {
        j = 0;
        while (j < game->map->map_width)
        {
            x = j * block_size;
            y = i * block_size;
            if (game->map->map[i][j] == '1') 
            {
                draw_wall_block(game, x, y, game->assets->n);
            } else 
            {
                draw_empty_block(game, x, y);
            }
            j++;
        }
        i++;
    }
    
    draw_circle(game->img, game->map->player->posX, game->map->player->posY, 5, 0x00FF00);
    mlx_put_image_to_window(mlx, window, game->img->img, 0, 0);
}
