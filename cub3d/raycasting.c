
#include "cublib/cublib.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>

#include <stdio.h> // FIX ME!!!

#define TURN    0.1
#define SPEED   5
#define GRID    64

#define WHITE   0x00FFFFFF
#define BLACK   0x00000000
#define RED     0x00FF0000

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
	double		px;
	double		py;
	double		dx;
	double		dy;
    double      a;
}				t_player;

typedef struct s_ray
{
    double      ay;
    double      ax;
    double      by;
    double      bx;
    double      hit_x;
	double  	hit_y;
	int			i;
	int			len;
}               t_ray;

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			s;
	int			rx;
	int			ry;
}				t_map;

typedef struct s_all
{
	t_window	*win;
	t_player	*plr;
    t_ray       *ray;
	t_map		*map;
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

void dda_line (t_all *all, double x1, double y1, double x2, double y2)
{
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
		my_mlx_pixel_put(all->win, round(x[i]), round(y[i]), RED);
		i++;
	}
}

void	ft_make_map(t_all *all)
{
	int		i;

	i = 0;
	all->map->x = 8;
	all->map->y = 8;
	all->map->s = 8;
	all->map->rx = all->win->x / all->map->s;
	all->map->ry = all->win->y / all->map->s;

	all->map->map = (char**)malloc(all->map->y * sizeof(char*));
	while (i < all->map->y)
	{
		all->map->map[i] = (char*)malloc((all->map->x + 1) * sizeof(char));
		i++;
	}

	ft_strcpy(all->map->map[0], "11111111");
	ft_strcpy(all->map->map[1], "10000001");
	ft_strcpy(all->map->map[2], "10000101");
	ft_strcpy(all->map->map[3], "10000001");
	ft_strcpy(all->map->map[4], "10000001");
	ft_strcpy(all->map->map[5], "11110001");
	ft_strcpy(all->map->map[6], "10000001");
	ft_strcpy(all->map->map[7], "11111111");

	i = 0;  
	while (i < all->map->y)
	{
		printf("%s\n", all->map->map[i]);  //FIX ME
		i++;
	}
}

void	ft_scale_map(t_all *all, double y, double x, int color)
{
	double		ys;
	double		xs;
    double		yo;
	double		xo;
    
	ys = y * all->map->ry;
	xs = x * all->map->rx;
	yo = (y + 1) * all->map->ry;
	xo = (x + 1) * all->map->rx;
    while (ys < yo)
    {
        while (xs < xo)
        {
            my_mlx_pixel_put(all->win, xs++, ys, color);
        }
		xs -= all->map->rx;
		ys++;
    }
}

void	ft_draw_map(t_all *all)
{
	double		y;
	double		x;
	int		color;

	y = 0;
	x = 0;
	while (y < all->map->y)
	{
		while (x < all->map->x)
		{
			if (all->map->map[(int)y][(int)x] == '1')
			color = WHITE;
			else
			color = BLACK;
			ft_scale_map(all, y, x, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void    ft_draw_player(t_all *all)
{
    int     x;
    int     y;
    
    x = (int)all->plr->px + 8;
    y = (int)all->plr->py + 8;
    while (y >= all->plr->py)
    {
        while (x >= all->plr->px)
        {
            my_mlx_pixel_put(all->win, x--, y, RED);
        }
        x += 8;
        y--;
    }
}

void	ft_set_screen(t_all *all)
{
	all->win->img = mlx_new_image(all->win->mlx, all->win->x, all->win->y);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel, &all->win->line_length, &all->win->endian);
}

void	ft_draw_screen(t_all *all)
{
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	free(all->win->img);
	free(all->win->addr);
}


void	ft_draw_rays(t_all *all)
{
	double py, px;
	double ay, ax;
	double xo, yo;
	int mx, my, hit;


	hit = -100;
	py = all->plr->py;
	px = all->plr->px;

	// looking up
	if (all->plr->a > M_PI)
	{
		ay = (int)(py / 64) * 64 - 1;
		yo = -64;
		xo = yo / tan(all->plr->a);
	}
	// looking down
	if (all->plr->a < M_PI)
	{
		ay = (int)(py / 64) * 64 + 64;
		yo = 64;
		xo = yo / tan(all->plr->a);
	}
	ax = px + (py - ay) / tan(all->plr->a);
	while (hit != 1)
	{
		mx = (int)(ax) / 64;
		my = (int)(ay) / 64;
		if (all->map->map[my][mx] == '1')
		hit = 1;
		else
		{
			ax += xo;
			ay += yo;
			hit++;
		}
	}
	printf("horizontal:  ay - %f, ax - %f, py - %f, px - %f\n", ay, ax, py, px);
	dda_line(all, px, py, ax, ay);

	// looking right
	if (all->plr->a > 3 * M_PI / 2 || all->plr->a < M_PI / 2)
	{
		ax = (int)(px / 64) * 64 - 1;
		xo = 64;
		yo = -xo * tan(all->plr->a);
	}
	// looking left
	if (all->plr->a > M_PI / 2 && all->plr->a < 3 * M_PI / 2)
	{
		ax = (int)(px / 64) * 64 + 64;
		xo = -64;
		yo = xo * tan(all->plr->a);
	}
	ay = py + (px - ax) / tan(all->plr->a);
	hit = -100;
	while (hit != 1)
	{
		mx = (int)(ax) / 64;
		my = (int)(ay) / 64;
		if (all->map->map[my][mx] == '1')
		hit = 1;
		else
		{
			ax += xo;
			ay += yo;
			hit++;
		}
	}
	printf("vertical: ay - %f, ax - %f, py - %f, px - %f\n", ay, ax, py, px);
	dda_line(all, px, py, ax, ay);
}


// void	ft_draw_rays(t_all *all)
// {
// 	int		r, mx, my, mp, dof;
// 	double	rx, ry, ra, xo, yo;
// 	double	atan;

// 	ra = all->plr->a;
// 	r = 0;
// 	while (r < 1)
// 	{
// 		Check horizontal lines
// 		dof = 0;
// 		atan = -1 / tan(ra);
// 		if (ra > M_PI)
// 		{
// 			ry = (((int)all->plr->py >> 6) << 6) - 0.0001; // looking up
// 			rx = (all->plr->py - ry) * atan + all->plr->px;
// 			yo = 64 * -1;
// 			xo = -yo * atan;
// 		}
// 		if (ra < M_PI)
// 		{
// 			ry = (((int)all->plr->py >> 6) << 6) + 64; // looking down
// 			rx = (all->plr->py - ry) * atan + all->plr->px;
// 			yo = 64;
// 			xo = -yo * atan;
// 		}
// 		if (ra == 0 || ra == M_PI)
// 		{
// 			rx = all->plr->px;
// 			ry = all->plr->py;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			if (all->map->map[mx][my] == '1')
// 				dof = 8; // hit wall
// 			else
// 			{
// 				rx +=xo;
// 				ry +=yo;
// 				dof += 1;
// 			}
// 		}
// 		dda_line(all, all->plr->px, all->plr->py, rx, ry);
// 		r++;
// 	}
// }

int	ft_key_press(int key, t_all *all)
{
	if (key == 126) //Up Arrow
	{
		all->plr->py -= SPEED;
	}
	if (key == 125) //Down Arrow
	{
		all->plr->py += SPEED;
	}
	if (key == 123) //Left Arrow
	{
		all->plr->px -= SPEED;
	}
	if (key == 124) //Right Arrow
	{
		all->plr->px += SPEED;
	}
	if (key == 0) //key A
    {
		all->plr->a += TURN;
		if (all->plr->a > 2 * M_PI)
			all->plr->a -= (2 * M_PI);
		all->plr->dx = cos(all->plr->a) * 5;
		all->plr->dy = sin(all->plr->a) * 5;
    }
    if (key == 2) //key D
	{
		all->plr->a -= TURN;
    	if (all->plr->a < 0)
            all->plr->a += (2 * M_PI);
		all->plr->dx = cos(all->plr->a) * 5;
		all->plr->dy = sin(all->plr->a) * 5;
    }
	if (key == 13) // key W
	{
		all->plr->px += all->plr->dx;
		all->plr->py += all->plr->dy;
	}
	if (key == 1) // key S
	{
		all->plr->px -= all->plr->dx;
		all->plr->py -= all->plr->dy;
	}

	// esc key - 53

	ft_set_screen(all);
	ft_draw_map(all);
	ft_draw_player(all);
//	dda_line(all, all->plr->px, all->plr->py, all->plr->px + (all->plr->dx * 5), all->plr->py + (all->plr->dy * 5));
	ft_draw_rays(all);
	ft_draw_screen(all);
	
	return (0);
}

int		main()
{
	t_window	win;
	t_player	plr;
    t_ray       ray;
	t_map		map;
	t_all		all;

	ft_bzero(&all, sizeof(t_all));
	ft_bzero(&win, sizeof(t_window));
    ft_bzero(&ray, sizeof(t_ray));
	ft_bzero(&plr, sizeof(t_player));

	all.win = &win;
	all.plr = &plr;
    all.ray = &ray;
	all.map = &map;
	win.x = 640;
	win.y = 480;
	plr.a = M_PI / 2;
    plr.px = 200;
    plr.py = 200;
	plr.dx = cos(plr.a) * 5;
	plr.dy = sin(plr.a) * 5;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.x, win.y, "cub3d");
	
	ft_set_screen(&all);
	ft_make_map(&all);
	ft_draw_map(&all);
    ft_draw_player(&all);
//	dda_line(&all, plr.px, plr.py, plr.px + (plr.dx * 5), plr.py + (plr.dy * 5));
	ft_draw_rays(&all);

	mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
	mlx_key_hook(win.win, ft_key_press, &all);
	mlx_loop(win.mlx);
	return (0);
}