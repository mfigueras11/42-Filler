/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:16 by mfiguera          #+#    #+#             */
/*   Updated: 2018/04/11 17:56:32 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef	struct	s_data
{
	char	pl;
	int		mw;
	int		mh;
	int		pw;
	int		ph;
	char	**tb;
	char	**pc;
	int		msc;
	int		bx;
	int		by;
}				t_data;

int				solveit(t_data game);
void			cleanit(t_data *data);
void			heatmap(t_data *s, int y, int x);

#endif
