/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:11:43 by singeonho         #+#    #+#             */
/*   Updated: 2023/06/11 19:37:47 by singeonho        ###   ########.fr       */
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