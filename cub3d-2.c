
#include "cublib/cublib.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>

#include <stdio.h> // FIX ME!!!

#define SCALE 64
#define TURN 0.1
#define SPEED 1
#define GRID 64

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_window;

typedef struct	s_player
{
	int			x;
	int			y;
	double		px;
	double		py;
	double		ex;
	double		ey;
    double      a;
	double		pov;
}				t_player;

typedef struct s_ray
{
    double      ay;
    double      ax;
    double      by;
    double      bx;
    double         hit_x;
	double			hit_y;
	int			i;
	int			len;
}               t_ray;

typedef struct s_all
{
	t_window	*win;
	t_player	*plr;
    t_ray       *ray;
	char		**map;
}				t_all;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_scale_img(t_window *win, int x, int y, int color)
{
	t_point	end;

	end.x = (x + 1) * SCALE;
	end.y = (y + 1) * SCALE;
	x *= SCALE;
	y *= SCALE;
	while (y < end.y)
	{
		while (x < end.x)
			my_mlx_pixel_put(win, x++, y, color);
		x -= SCALE;
		y++;
	}
}

void	ft_print_player(t_all *all)
{
	t_point start;
	t_point	end;
	int		color_pink;

	color_pink = 0xFF00FF;
	start.x = all->plr->x * SCALE;
	start.y = all->plr->y * SCALE;
	end.x = (all->plr->x * SCALE) + 8;
	end.y = (all->plr->y * SCALE) + 8;
	while (start.y < end.y)
	{
		while (start.x < end.x)
		{
		my_mlx_pixel_put(all->win, start.x, start.y, color_pink);
		start.x++;
		}
		start.x -= 8;
		start.y++;
	}
}

void	ft_player_init(t_all *all)
{
	t_point		point;

	point.y = 0;
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == 'N')
			{
				all->plr->x = point.x;
				all->plr->y = point.y;
				all->map[point.y][point.x] = '0';
			}
			point.x++;
		}
		point.y++;
	}
}

void	print_map(t_all *all, t_window *win)
{
	t_point		point;
	int			color_white;
	int			color_black;

	color_white = 0xFFFFFF;
	color_black = 0x000000;
	point.y = 0;
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '0')
				ft_scale_img(win, point.x, point.y, color_black);
			if (all->map[point.y][point.x] == '1')
				ft_scale_img(win, point.x, point.y, color_white);
		point.x++;
		}
		point.y++;
	}
}

char	**make_map(t_list **head, int size)
{
	char 	**map = ft_calloc(size + 1, sizeof(char *));
	int 	i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

void	ft_parse_map(int fd, t_list **head)
{
	char	*line = NULL;

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(head, ft_lstnew(line));
	}
	ft_lstadd_back(head, ft_lstnew(line));
}


void    ft_raycasting(t_all *all)
{
	while(all->ray->len < 100)
	{
		all->ray->hit_x = all->plr->x + all->ray->len * cos(all->plr->a);
		all->ray->hit_y = all->plr->y + all->ray->len * sin(all->plr->a);
		if (all->map[(int)all->ray->hit_y][(int)all->ray->hit_x] == '1')
			break;
		all->ray->len++;
	}
	ft_scale_img(all->win, (int)all->ray->hit_x, (int)all->ray->hit_y, 0xFF00FF);
}

void	ft_draw_screen(t_all *all)
{
	print_map(all, all->win);
	ft_print_player(all);
	ft_raycasting(all);

	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}

int	ft_key_press(int key, t_all *all)
{
	if (key == 126) //Up Arrow
	{
		all->plr->y -= SPEED;
	}
	if (key == 125) //Down Arrow
	{
		all->plr->y += SPEED;
	}
	if (key == 123) //Left Arrow
	{
		all->plr->x -= SPEED;
	}
	if (key == 124) //Right Arrow
	{
		all->plr->x += SPEED;
	}
	if (key == 0)
    {
		all->plr->a += TURN;
		if (all->plr->a > 2 * M_PI)
			all->plr->a -= (2 * M_PI);
    }
    if (key == 2)
	{
		all->plr->a -= TURN;
    	if (all->plr->a < 0)
            all->plr->a += (2 * M_PI);
    }
	ft_draw_screen(all);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd = open(argv[1], O_RDONLY);
	t_list		*head = NULL;
	t_window	win;
	t_player	plr;
    t_ray       ray;
	t_all		all;

	ft_bzero(&all, sizeof(t_all));
	ft_bzero(&win, sizeof(t_window));
    ft_bzero(&ray, sizeof(t_ray));
	ft_bzero(&plr, sizeof(t_player));

	all.win = &win;
	all.plr = &plr;
    all.ray = &ray;
	win.x = 640;
	win.y = 480;
	plr.a = M_PI / 2;

	ft_parse_map(fd, &head);
	all.map = make_map(&head, ft_lstsize(head));
	ft_player_init(&all);

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.x, win.y, "cub3d");
	win.img = mlx_new_image(win.mlx, win.x, win.y);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);

	ft_draw_screen(&all);
	mlx_key_hook(win.win, ft_key_press, &all);
	mlx_loop(win.mlx);
	return (0);
}