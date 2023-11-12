/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:46:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/12 16:34:41 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype_bonus.h"
#include "philo_bonus.h"

t_state	philo_get_state(t_philo *philo)
{
	t_state	state;

	sem_wait(philo->smp);
	state = philo->state;
	sem_post(philo->smp);
	return (state);
}

void	philo_set_state(t_philo *philo, t_state state)
{
	sem_wait(philo->smp);
	if (philo->state == DEAD)
	{
		sem_post(philo->smp);
		return ;
	}
	philo->state = state;
	sem_post(philo->smp);
}

int	philo_get_eat_cnt(t_philo *philo)
{
	int	eat_cnt;

	sem_wait(philo->smp);
	eat_cnt = philo->eat_cnt;
	sem_post(philo->smp);
	return (eat_cnt);
}

void	philo_increase_eat_cnt(t_philo *philo)
{
	sem_wait(philo->smp);
	philo->eat_cnt++;
	sem_post(philo->smp);
}

t_int64	philo_get_eat_stamp(t_philo *philo)
{
	t_int64	eat_stamp;

	sem_wait(philo->smp);
	eat_stamp = philo->eat_stamp;
	sem_post(philo->smp);
	return (eat_stamp);
}

void	philo_set_eat_stamp(t_philo *philo, t_int64 stamp)
{
	sem_wait(philo->smp);
	philo->eat_stamp = stamp;
	sem_post(philo->smp);
}
