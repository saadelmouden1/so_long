/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:03:18 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 01:03:22 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_update(char *retholder, char *holder);
char	*get_line(char *holder);
char	*read_line(char **holder_ptr, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		found_newline(char *holder);
int		ft_strlen(char *str);
#endif