/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:27 by mtian             #+#    #+#             */
/*   Updated: 2025/07/29 18:10:28 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <math.h>
# include "libft.h"

/* mlx */
# include "mlx.h"

/* window */
# define WIDTH 1920
# define HEIGHT 1024
# define MENU_WIDTH 376

# define ESC 65307
# define QUIT 17

/* color initialise*/
# define COLOR_Z_ZERO 0x5ac9ed
# define COLOR_Z_POSITIVE 0xf0c91d
# define COLOR_Z_NEGATIVE 0xff4900

/* bresenham */
# define LINE_DIRECTION_RIGHT 0
# define LINE_DIRECTION_DOWN 1

# define STEP_HORIZENTAL 0
# define STEP_VERTICAL 1

# define SMALL_MAP 0
# define BIG_MAP 1

/* key event & mouse event */
# define LEFT 65363
# define RIGHT 65361

# define UP 65362
# define DOWN 65364

# define SMALLER 49
# define BIGGER 50

# define ROTATION_X 51
# define ROTATION_Y 52
# define ROTATION_Z 53

# define ROTATION_X_REVERSE 54
# define ROTATION_Y_REVERSE 55
# define ROTATION_Z_REVERSE 56

# define VIEW_2D_TOP 113
# define VIEW_2D_FRONT 119
# define VIEW_2D_RIGHT 101

# define VIEW_DEFAUT 114

# define COLOR_DEFAUT 105
# define COLOR_CHANGE 111
# define COLOR_VARIER 112

# define Z_PLUS 106
# define Z_MOINS 107
# define Z_DEFAUT 108

# define MOUSE_ACTIVE 100
# define MOUSE_DESACTIVE 102

//# define FT_MAX(a, b) ((a) > (b) ? (a) : (b)) //supprimer supprimer

/* structure for point */
typedef struct s_data
{
	float		x;
	float		y;
	float		z;
	int			color;
}	t_data;

/* structure for color */
typedef struct s_color_gradient
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;
}	t_color_gradient;

/* structure for map */
typedef struct s_map
{
	t_data	*point;
	t_data	*point_right;
	t_data	*point_down;
	t_data	iso_point;
	t_data	iso_point_right;
	t_data	iso_point_down;
}	t_map;

/* structure for bresenham */
typedef struct s_bresenham
{
	int		dy;
	int		dx;
	int		p;
	int		a;
	int		b;
	int		x;
	int		y;
	int		x_step;
	int		y_step;
	int		scaled_x0;
	int		scaled_y0;
	int		scaled_x1;
	int		scaled_y1;
	int		color_start;
	int		color_end;
	float	fraction;
	int		color;
	char	*pixel;
}	t_bresenham;

/* structure for projection */
typedef struct s_projection
{
	int		tmp_x;
	int		tmp_y;
	int		scale;
	int		x_offset;
	int		y_offset;
	float	angle;
	float	alpha;
	float	beta;
	float	gamma;
}	t_projection;

/* structure for controls */
typedef struct s_controls
{
	int	move_left;
	int	move_right;
	int	move_up;
	int	move_down;
	int	smaller;
	int	bigger;
	int	rotation_x;
	int	rotation_y;
	int	rotation_z;
	int	rotation_x_reverse;
	int	rotation_y_reverse;
	int	rotation_z_reverse;
	int	z_plus;
	int	z_moins;
	int	z_defaut;
	int	view_2d_top;
	int	view_2d_front;
	int	view_2d_right;
	int	view_defaut;
	int	color_change;
	int	color_varier_active;
	int	mouse_active;
}	t_controls;

/* structure for all */
typedef struct s_all
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*menu_img;

	t_list			*l;
	t_data			**tab;

	int				rows;
	int				cols;

	t_projection	p;
	t_controls		control;
	int				color_random;
	float			new_var_z;
	float			plat;
}	t_all;

/* ft_atoi_base.c */
int		ft_in_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);

/* clear_list_tab.c */
void	clear_list(t_list **lst);
void	free_tab_data(t_data **tab, int row_index);
void	free_tab(char **tab);
void	print_error_exit(t_list **l);

/* find_point.c */
t_data	*find_point_right(t_data **tableau, int row, int col, int max_cols);
t_data	*find_point_down(t_data **tableau, int row, int col, int row_index);

/* color_gradient.c */
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		interpolate_color(int color1, int color2, float fraction);
float	calculate_fraction(float x1, float x2, float x);

/* process_data.c */
void	process_element(char *element, t_data *data);
void	process_row(t_list *current, t_data *array_row, int max_cols);
void	convert_data_to_tableau(t_list *l, t_data **array,
			int row_index, int max_cols);
void	process_tableau_data(int *col, int *row, int max_cols, t_data **array);
int		procces_tableau_row(int row_index, int max_cols, t_data **array);

/* parsing.c */
t_data	**malloc_tableau_2_dimension(int row_index, int max_cols);
t_data	**list_to_2d_array(t_list *l, int row_index, int max_cols);
void	process_spaced_line(char *line, t_list **l, int *max_cols);
void	parse_file_to_list(char *file_name, t_list **l,
			int *row_index, int *max_cols);

/* bresenham.c */
void	bresenham_step(t_bresenham *b, int flag);
void	bresenham_horizontal(t_bresenham *b, t_all *all);
void	bresenham_vertical(t_bresenham *b, t_all *all);
void	bresenham_draw_line(t_bresenham *b, t_all *all,
			t_data *point_0, t_data *point_1);
void	bresenham(t_data *point_0, t_data *point_1, t_all *all);

/* projection.c */
void	initialiser_projection(t_projection *p);
void	rotate_z(t_data *point, float gamma);
void	rotate_y(t_data *point, float beta);
void	rotate_x(t_data *point, float alpha);
t_data	calculate_center(t_data **tab, int rows, int cols);

/* rotate_around_center.c */
void	initialiser_point(t_data *center);
void	rotate_around_center(t_data *point, t_data center, t_projection *p);

/* isometric_small_map.c */
void	process_isometric(t_data *adjusted_point, t_data *projected_point,
			t_all *all);
t_data	isometric(t_data point, t_projection *p, t_all all);

/* isometric_big_map.c */
void	process_isometric_v2(t_data *iso_point, t_data *adjusted_point,
			t_all *all);
t_data	isometric_v2(t_data point, t_projection *p, t_all all);

/* draw.c */
void	draw_true_line(t_map *map, int line_direction, int map_size,
			t_all *all);
void	draw_view_3d(t_all *all);
void	draw_view_3d_v2(t_all *all);
int		redraw(void *params);
int		redraw_v2(void *params);

/* apply_controls_operations.c */
void	apply_controls_move(t_all *all);
void	apply_controls_scale(t_all *all);
void	apply_controls_rotation(t_all *all);
void	apply_controls_height(t_all *all);
void	apply_controls_color(t_all *all);

/* apply_controls.c */
void	apply_controls(t_all *all);

/* key_press_1.c */
void	key_press_move(int key, t_all *all);
void	key_press_scale(int key, t_all *all);
void	key_press_rotation(int key, t_all *all);
void	key_press_height(int key, t_all *all);

/* key_press_2.c */
void	key_press_view_part1(int key, t_all *all);
void	key_press_view_part2(int key, t_all *all);
void	key_press_color(int key, t_all *all);
void	key_press_mouse(int key, t_all *all);
int		key_press(int key, t_all *all);

/* key_release.c */
void	key_release_rotation_height_color(int key, t_all *all);
int		key_release(int key, t_all *all);

/* mouse_event.c */
int		mouse_move(int x, int y, t_all *all);
int		mouse_scroll(int button, int x, int y, t_all *all);

/* utils.c */
int		ft_max(int a, int b);
float	set_plat(int rows);
void	load_menu_image(t_all *all);

/* fdf.c */
int		ft_close(t_all *all);
void	manage_close(t_all *all);
void	initialiser_control(t_controls *control);
void	initialiser_all(t_all *all);
void	fdf(t_all *all);

#endif
