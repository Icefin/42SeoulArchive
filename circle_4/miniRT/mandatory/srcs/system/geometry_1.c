/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:50:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/24 22:24:13 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "rtmath.h"
#include <math.h>

//ray-sphere relation
// void	raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out)
// {
// 	t_vec3	oc = vec3_minus_vec3(ray.origin, sphere.position);
// 	double a = dot_vec3(ray.direction, ray.direction);
// 	double b = 2.0 * dot_vec3(oc, ray.direction);
// 	double c = dot_vec3(oc, oc) - sphere.radius * sphere.radius;
// 	double discriminant = b * b - 4 * a * c;

// 	if (discriminant >= 0) {
// 		out->hitid = sphere.id;
// 		out->raytime = -b - sqrt(discriminant) / (2.0 * a);
// 		out->hitpos = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, out->raytime));
// 		out->hitnorm = vec3_minus_vec3(out->hitpos, sphere.position);
// 	}
// }

void	raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out)
{
    t_vec3      oc; //방향벡터로 나타낸 구의 중심.
    //a, b, c는 각각 t에 관한 2차 방정식의 계수
    double      a;
    double      half_b;
    double      c;
    double      discriminant; //판별식
    double      sqrtd;
    double      t;

    oc = vec3_minus_vec3(ray.origin, sphere.position);
    a = dot_vec3(ray.direction, ray.direction);
    half_b = dot_vec3(oc, ray.direction);
    c = dot_vec3(oc, oc) - (sphere.radius * sphere.radius);
    discriminant = (half_b * half_b) - (a * c);

    if (discriminant < 0)
        return ;
    sqrtd = sqrt(discriminant);
    // 두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
    t = (-half_b - sqrtd) / a;
    if (t < 1e-6 || t > out->raytime)
    {
        t = (-half_b + sqrtd) / a;
        if (t < 1e-6 || t > out->raytime)
            return ;
    }
	out->hitid = sphere.id;
    out->raytime = t;
    out->hitpos = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, t));
    out->hitnorm = vec3_multiply_num(vec3_minus_vec3(out->hitpos, sphere.position), 1 / sphere.radius);  // 정규화된 법선 벡터
}