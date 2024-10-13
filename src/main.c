/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchissal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:05:37 by dchissal          #+#    #+#             */
/*   Updated: 2024/06/28 09:05:39 by dchissal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_est(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
		{
			j = 0;
			while (".fdf"[j] != '\0' && ".fdf"[j] == s[i])
			{
				i++;
				j++;
			}
		}
		i++;
	}
	if (j == 4)
		return (0);
	handle_error("error... Extensão inválida!\n");
	return (-1);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	handle_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	close_program(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 65307)
	{
		free_map(data->map, data->height);
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		handle_error("Usage: ./fdf <map_file>");
	if (ft_check_est(argv[1]) == -1)
		return (-1);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			LARGURA, ALTURA, "FdF by Optimus Prime");
	data.map = read_map(argv[1], &data, &data.limits.min_z, &data.limits.max_z);
	data.img = mlx_new_image(data.mlx_ptr,
			LARGURA - 180, ALTURA);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	fill_background(&data, 0x00336);
	draw_iso_map(&data);
	info(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 180, 0);
	mlx_hook(data.win_ptr, 17, 0, ft_os_tres_idiotas, &data);
	mlx_key_hook(data.win_ptr, close_program, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
