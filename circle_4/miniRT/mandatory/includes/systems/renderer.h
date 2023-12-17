/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:53:29 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 18:48:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "commontype.h"
# include "camera.h"
# include "image.h"
# include "scene.h"
# include "window.h"
# include "ray.h"

# define TRACE_DEPTH 2

typedef struct s_renderer
{
	t_scene		*m_scene;
	t_camera	*m_camera;
}	t_renderer;

void		initialize_renderer(t_renderer *renderer, const t_scene *scene, const t_camera *camera);
void		destroy_renderer(t_renderer *renderer);
/*
render every pixel
*/
void		render_screen(t_renderer * renderer, t_window *window);

t_uint32	per_pixel(t_ray ray);
t_rayinfo	trace_ray(t_ray	ray);
t_rayinfo	closest_hit(t_ray ray, float ray_time, t_int32 object_id);
t_rayinfo	miss(t_ray ray);
/*
resize image
*/
void		renderer_on_resize();
#endif