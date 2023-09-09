/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:11:43 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/12 14:16:52 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char* s)
{
	int res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return res;
}

int	ft_ptrlen(char** p)
{
	int res;

	res = 0;
	while (p[res] != 0)
		res++;
	return res;
}