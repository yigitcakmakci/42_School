/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:10:03 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/02 20:55:44 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>

char		*ft_strnstr(const char *big, const char *little, int len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		executes(char **argv, char **envp, int which_process);
char		*set_path(char **envp, char *cmd);
char		*try_path(char **envp, char *cmd);
void		free_list(char **trash);

#endif
