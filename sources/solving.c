/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:24:18 by mfiguera          #+#    #+#             */
/*   Updated: 2018/04/11 17:54:04 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		itfits2(t_data da, int h, int w, int match)
{
	int	i;
	int j;
	int	score;

	score = 0;
	i = -1;
	while (++i < da.ph)
	{
		j = -1;
		while (++j < da.pw)
		{
			if (da.pc[i][j] == '*' && (i + h) >= 0 && (i + h) < da.mh
						&& (j + w) >= 0 && (j + w) < da.mw &&
					(da.tb[i + h][j + w] == 'O' || da.tb[i + h][j + w] == 'X'))
				match++;
			if (da.pc[i][j] == '*' && ((i + h) < 0 || (i + h) >= da.mh
						|| (j + w) < 0 || (j + w) >= da.mw))
				return (0);
			if (da.pc[i][j] == '*')
				score += da.tb[i + h][j + w];
		}
	}
	if (match == 1)
		return (score);
	return (0);
}

int		itfits(t_data *data, int h, int w)
{
	int	ph;
	int	pw;
	int	scr;

	ph = 0;
	while (ph < data->ph)
	{
		pw = 0;
		while (pw < data->pw)
		{
			if (data->pc[ph][pw] == '*' &&
					(scr = itfits2(*data, h - ph, w - pw, 0))
					&& scr < data->msc)
			{
				data->by = h - ph;
				data->bx = w - pw;
				data->msc = scr;
			}
			pw++;
		}
		ph++;
	}
	return (0);
}

int		solveit(t_data game)
{
	int i;
	int j;

	i = 0;
	while (i < game.mh)
	{
		j = 0;
		while (j < game.mw)
		{
			if (game.tb[i][j] == game.pl)
				itfits(&game, i, j);
			j++;
		}
		i++;
	}
	if (game.msc != 176176176)
	{
		ft_printf("%d %d\n", game.by, game.bx);
		return (1);
	}
	return (0);
}
