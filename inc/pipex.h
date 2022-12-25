/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:40:08 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/25 04:25:12 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include"../libtool/libft.h"
# include"get_next_line.h"

char	*get_path(char **en, char *cmd);
int		error(void);
void	do_cmd(char **cmd, char **en);

#endif
