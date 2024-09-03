/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:40 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:44:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

size_t	ft_strlen(const char *s);
void	*ft_malloc(size_t s);
char	*ft_strdup(const char *s1);
char	*str_join(const char *s1, const char *s2);
void	ft_put_nbr(int fd, ssize_t n);
void	ft_put_str(int fd, const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_path_join(const char *s1, const char *s2);

#endif
