
#include "cublib/cublib.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>

#define SCALE 16
#define PI 3.1415926535

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
}				t_window;

typedef struct	s_player
{
	int			x;
	int			y;
	double		px;
	double		py;
	double		ex;
	double		ey;
	double		pov;
}				t_player;

typedef struct s_all
{
	t_window	*win;
	t_player	*plr;
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
	end.x = (all->plr->x + 1) * SCALE;
	end.y = (all->plr->y + 1) * SCALE;
	while (start.y < end.y)
	{
		while (start.x < end.x)
			my_mlx_pixel_put(all->win, start.x++, start.y, color_pink);
		start.x -= SCALE;
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

// void	ft_ray(t_all *all)
// {
// 	double	angle;
// 	double	dist;

// 	angle = ((double))all->ray.i - (all->win.x / 2)	* 33 / (all->win.x / 2);
// 	angle = angle * M_PI / 180;
// 	all->ray.x = all->dir.x * cos(angle) - all->dir.y * sin(angle);
// 	all->ray.y = all->dir.y * cos(angle) + all->dir.x * sin(angle);
// 	dist = hypot(all->ray.x, all->ray.y);
// 	all->ray.x /= dist;
// 	all->ray.y /= dist;
// }

void dda_line (t_all *all, double x1, double y1, double x2, double y2)
{
	int		i;
	double	x = all->plr->x;
	double	y = all->plr->y;

	i = 0;
	while (i++ < 100)
	{
		x = x + i * cos(all->plr->pov);
		if (all->map[(int)y][(int)x] == '1')
      	    break ;
        y = y + i * sin(all->plr->pov);
		if (all->map[(int)y][(int)x] == '1')
    	    break ;
	}

	int i, L, xstart, ystart, xend, yend;
	double dX, dY, x[1000], y[1000];    
	xstart = round(x1);
	ystart = round(y1);
	xend = round(x2);
	yend = round(y2);
	L = fmax(abs(xend-xstart), abs(yend-ystart));
	dX = (x2-x1) / L;
	dY = (y2-y1) / L;
	i = 0;
	x[i] = x1;
	y[i] = y1;
	i++;
	while (i < L)
	{
		x[i] = x[i-1] + dX;
		y[i] = y[i-1] + dY;
		i++;
	}
	x[i] = x2;
	y[i] = y2;

	i = 0;
	while (i <= L)
	{
		my_mlx_pixel_put(all->win, round(x[i]), round(y[i]), 0x0000FF00);
		i++;
	}
}

void	ft_raycasting(t_all *all)
{
	int 	i;
	double 	x = all->plr->x;
	double 	y = all->plr->y;
	
		i = 0;
		while (i++ < 100)
		{
			x = x + i * cos(all->plr->pov);
	//		if (all->map[(int)y][(int)x] == '1')
      //  	    break ;
        	y = y + i * sin(all->plr->pov);
		//	if (all->map[(int)y][(int)x] == '1')
        //	    break ;
		}
    	dda_line(all,  all->plr->x * SCALE, all->plr->y * SCALE, x * SCALE, y * SCALE);
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
		all->plr->y -= 1;
	}
	if (key == 125) //Down Arrow
	{
		all->plr->y += 1;
	}
	if (key == 123) //Left Arrow
	{
		all->plr->x -= 1;
	}
	if (key == 124) //Right Arrow
	{
		all->plr->x += 1;
	}
	if (key == 0)
		all->plr->pov += 0.1;
	if (key == 2)
		all->plr->pov -= 0.1;
	ft_draw_screen(all);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd = open(argv[1], O_RDONLY);
	t_list		*head = NULL;
	t_window	win;
	t_player	plr;
	t_all		all;

	ft_bzero(&all, sizeof(t_all));
	ft_bzero(&win, sizeof(t_window));
	ft_bzero(&plr, sizeof(t_player));

	all.win = &win;
	all.plr = &plr;
	win.win_width = 640;
	win.win_height = 480;
	plr.pov = 0;

	ft_parse_map(fd, &head);
	all.map = make_map(&head, ft_lstsize(head));
	ft_player_init(&all);

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.win_width, win.win_height, "cub3d");
	win.img = mlx_new_image(win.mlx, win.win_width, win.win_height);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);

	ft_draw_screen(&all);
	mlx_key_hook(win.win, ft_key_press, &all);
	mlx_loop(win.mlx);
	return (0);
}