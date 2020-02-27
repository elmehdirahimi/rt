/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:42:54 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/08 11:42:55 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDHT 1000
# define HEIGHT 1000

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>



typedef struct s_vect
{
	double x;
	double y;
	double z;
}			t_vect;

typedef struct  s_ray
{
	t_vect o;
	t_vect d;
	t_vect translation;
} 				t_ray;

typedef struct  s_cam
{
	t_ray cam_ray;
	t_vect look_at;
	t_vect  u;
	t_vect  v;
	double w;
	double h;
	t_vect center_corner;
} 				t_cam;

typedef struct  s_light
{
	t_vect position;
	t_vect color;
	int enable;
	t_vect translation;
	struct  s_light *next;
} 				t_light;

typedef struct  s_object
{
	int 			type;
	t_vect color;
    t_vect 			position;
	t_vect     direction;
	t_vect     rotation;
	t_vect  translation;
	double r;
	struct  s_object *next;
} 				t_object;

typedef struct		s_texture
{
	void			*img;
	int				*buf;
	int				w;
	int				h;

}					t_texture;


typedef struct	s_cell
{
	float		mindisttocell;
	t_vect	base;
	t_vect	toclosest;
	t_vect	closest;
}				t_cell;
typedef struct	s_voronoi
{
	float		valuechange;
	float		isborder;
	t_vect	cellcolor;
	t_vect	value;
	t_vect	noise;
}				t_voronoi;


typedef struct	s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;
	t_object 	*object;
	t_cam		cam;
	t_light     *light;
	double     t;
	int x;
    int y;
	int fd;
	int nb_line_min;
	int nb_line;
	char **image;
	t_vect  temp_o;
	t_vect  temp_d;
	double t3;
	double max;
	t_vect up;
	t_vect to;
	t_texture      txt;
	double		Um;
	 double		Vm;
}				t_rt;
void	initialize(t_rt *rt, char *argv);
t_vect addition(t_vect vect1, t_vect vect2);
t_vect soustraction(t_vect vect1, t_vect vect2);
t_vect multiplication(t_vect vect1, double x);
double  dot(t_vect vect1, t_vect vect2);
double  module(t_vect vect);
t_vect normale(t_vect vect);
t_vect  constrector(double x, double y, double z);
t_vect		project(t_vect direction, t_vect rotation);
void	put_pixel(t_rt *rt, int x, int y,int color);
void  draw(t_rt *rt);
t_vect  cross(t_vect vect1, t_vect vect2);
t_vect division(t_vect vect1, t_vect vect2);
double clamp(double v, double max, double min);
int  plane_intersection(t_rt *rt, t_object *plane_temp, double *dist);
int  cylinder_intersection(t_rt *rt, t_object *plane_temp, double *dist);
int  cone_intersection(t_rt *rt, t_object *cone_temp, double *dist);
int  sphere_intersection(t_rt *rt, t_object *sphere_temp, double *dist);
int equal(t_vect vect1, t_vect vect2);
int   init_camera(t_rt *rt, int j);
int	  add_light(t_rt *rt, int *k, int j);
int			add_sphere(t_rt *rt, int *k, int i);
int			add_cylinder(t_rt *rt, int *k, int i);
int			add_plane(t_rt *rt, int *k, int i);
double		ft_atod(char *str, int *j);
char    *get_buffer(t_rt *rt);
int		ft_color_position(t_rt *rt, t_object *object, int *k);
int   initialiser(t_rt *rt, char *argv);
int   parser(t_rt *rt);
int		ft_new_atoi(char *str, int *j);
void light_inter(t_rt *rt, double dist);
void   corner(t_rt *rt);
void    param_init(t_rt * rt);
void check_light(t_rt *rt);
t_vect     get_normal(t_vect vect, t_object *object,t_rt *rt);
t_vect    get_reflected(t_vect vect, t_vect v, t_object *object,t_rt *rt);
int     inter(t_rt *rt, t_object *object_temp, double *dist);
t_object   *intersection(t_rt *rt, double max);
int  Shading(t_rt *rt, t_object* sphere);
t_vect   extraConsterctor(char *image, int *j);
int check_light_format(t_rt *rt, int *k);
int check_camera_format(t_rt *rt);
int check_sphere_format(t_rt *rt, int *k);
int check_cylinder_format(t_rt *rt, int *k);
int check_plan_format(t_rt *rt, int *k);
void swap_object(t_rt *rt, t_object *object);
int cylinder_suit(t_rt *rt, t_object *object, int j, int *k);
int		rt_close(t_rt **rt);
int		rt_close1(t_rt **rt);
int		rt_close2(t_rt **rt);
int			load_texture(t_rt *rt);
int		getColorFromTexture(t_rt *rt, t_object *obj,  double t);
void 		GetAngleSphere(t_rt *rt, t_object *sphere_temp , t_vect inter);
void 		GetAngleCylinder(t_rt *rt, t_object *sphere_temp , t_vect inter);
void 	GetAngleCone(t_rt *rt, t_object *sphere_temp , t_vect inter);
void 		GetAnglePlan(t_rt *rt, t_object *plane_temp , t_vect inter);
void			ft_voronoi_noise(t_object *obj, t_vect p);
void  print_vect(t_vect vect);

#endif
