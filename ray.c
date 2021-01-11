/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/08 17:35:30 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point	calculate(t_ray r, float t)
{
	return (r.origin + scalprod(r.direction, t));
}

t_point	ft_position(t_intersect i)
{
	return (calculate(i.ray, i.t);
}

int	intersect(t_intersect i)
{
	return (!i.shape);
}

int	intersect_plan(s_intersect i, s_shape *plan)
{
	float dn;
	float t;
	t_vect	n;

	init_vector(&n, 1, 1, 1);
	dn = dotprod(i.ray.direction, n);
	if (!dn)
		return (0);
	t = dotprod(plan->p0 - i.ray.origin, n) / dn;
	if (t <= RAY_MIN || t >= i.t)
		return (0);
	i.t = t;
	i.shape = plan;
	return (1);
}

int	intersect_sphere(s_intersect i, s_shape *sphere)
{
	t_ray	r;
	float	t;
	float	p;
	float	d;

	r = i.ray;
	r.origin.x = sphere.p0.x;
	r.origin.y = sphere.p0.y;
	p = r.direction;
	d = r.origin;
	t = resolve_eq(pow(len(d), 2), 2 * dotprod(d, p), pow(len(d), 2) - pow(sphere.d / 2));
	if (t <= RAY_MIN || t >= i.t)
		return (false);
	i.t = t;
	i.shape = sphere;
}

float	resolve_eq(float a, float b, float c)
{
	float delta;
	float x1;
	float x2;

	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (-1);
	x1 = (-b - sqrt(delta)) / (2 * a);	
	x2 = (-b + sqrt(delta)) / (2 * a);
	return (min(t1, t2));
}
