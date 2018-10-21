/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:58:15 by mfiguera          #+#    #+#             */
/*   Updated: 2018/04/11 17:49:36 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cleanit(t_data *data)
{
	int i;

	i = 0;
	while (i < data->mh)
		free(data->tb[i++]);
	free(data->tb);
	i = 0;
	while (i < data->ph)
		free(data->pc[i++]);
	free(data->pc);
	data->msc = 176176176;
}

int		getlower(t_data ma, int y, int x)
{
	int	i;
	int	j;
	int ret;

	y--;
	x--;
	i = -1;
	ret = 10000;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == 1 && j == 1)
				j++;
			if (i + y < ma.mh && i + y >= 0 && j + x < ma.mw && j + x >= 0 &&
				ma.tb[i + y][j + x] != '.' && ma.tb[i + y][j + x] != 'O' &&
				ma.tb[i + y][j + x] != 'X' && ma.tb[i + y][j + x] < ret)
				ret = ma.tb[i + y][j + x];
			else if (i + y < ma.mh && i + y >= 0 && j + x < ma.mw && j + x >= 0
					&& ma.tb[i + y][j + x] == (ma.pl == 'O' ? 'X' : 'O'))
				return (0);
		}
	}
	return (ret);
}

void	heatmap(t_data *s, int y, int x)
{
	int ret;

	if (x == s->mw)
	{
		x = 0;
		y++;
	}
	if (y >= s->mh)
		return ;
	if ((ret = getlower(*s, y, x)) != 10000)
	{
		if (s->tb[y][x] != 'O' && s->tb[y][x] != 'X')
			s->tb[y][x] = 1 + ret;
		heatmap(s, y, ++x);
	}
	else
	{
		heatmap(s, y, ++x);
		if (s->tb[y][x] != 'O' && s->tb[y][x] != 'X')
			s->tb[y][x] = 1 + getlower(*s, y, x);
	}
}
