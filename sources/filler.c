/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:58:58 by mfiguera          #+#    #+#             */
/*   Updated: 2018/04/14 18:00:50 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**getboard(int w, int h)
{
	char	**board;
	int		start;
	char	*line;
	int		i;

	i = 0;
	start = 0;
	board = (char**)malloc(sizeof(*board) * h);
	while (i < h)
	{
		get_next_line(0, &line);
		ft_toupperstr(&line);
		if (line[0] == ' ')
			start = ft_strlen(line) - w;
		else
			board[i++] = ft_strsub(line, start, w);
		free(line);
	}
	return (board);
}

void	getallinfo(t_data *info)
{
	char	*line;
	int		i;

	i = 8;
	while (get_next_line(0, &line) == 1 && !ft_strstr(line, "Plateau"))
		free(line);
	info->mh = ft_atoi(&line[i]);
	while (line && ft_isdigit(line[i]))
		i++;
	i++;
	info->mw = ft_atoi(&line[i]);
	i = 6;
	free(line);
	info->tb = getboard(info->mw, info->mh);
	get_next_line(0, &line);
	info->ph = ft_atoi(&line[i]);
	while (line && ft_isdigit(line[i]))
		i++;
	i++;
	info->pw = ft_atoi(&line[i]);
	free(line);
	info->pc = getboard(info->pw, info->ph);
}

int		getplayerno(void)
{
	char	*line;
	char	*swa;
	char	ret;

	while (get_next_line(0, &line) == 1 && !ft_strstr(line, "mfiguera.filler"))
	{
		ft_putendl(line);
		free(line);
	}
	swa = ft_strstr(line, "exec");
	if (swa && swa[6] == '1')
		ret = 'O';
	else if (swa && swa[6] == '2')
		ret = 'X';
	else
		ret = -1;
	if (ft_strstr(line, "mfiguera.filler"))
		free(line);
	return (ret);
}

int		main(void)
{
	static t_data	game;
	int				ret;

	game.msc = 176176176;
	ret = 1;
	game.pl = getplayerno();
	while (ret)
	{
		getallinfo(&game);
		heatmap(&game, 0, 0);
		ret = solveit(game);
		cleanit(&game);
	}
	return (0);
}
