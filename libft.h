/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:01:32 by rbenjami          #+#    #+#             */
/*   Updated: 2013/11/20 11:31:33 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE
 #define INCLUDE
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>

/**
 *	Writes a character to the standard output (stdout).
 *	On success, the character written is returned.
 *	If a writing error occurs, EOF is returned and the error indicator (ferror) is set.
 */
int		ft_putchar(int);
void	ft_putstr(char*);
int		ft_isupper(int);
int		ft_islower(int);

size_t	ft_strlen(const char*);
void	*ft_memset(void*, int, size_t);

/**
 *	The bzero() function writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.
 */

void	ft_bzero (void*, size_t);
void	*ft_memcpy(void*, const void*, size_t);
void	*ft_memccpy(void*, const void*, int, size_t);
void	*ft_memmove(void*, const void*, size_t);
void	*ft_memmove(void*, const void*, size_t);
void	*ft_memchr(const void*, int, size_t);
char	*ft_strdup(const char*);
int		ft_strcmp(const char*, const char*);
int		ft_strncmp (const char*, const char*, size_t);
char	*ft_strcat(char*, const char*);
char	*ft_strncat(char*, const char*, size_t);
char	*ft_strchr(const char*, int);
char	*ft_strstr(const char*, const char*);
char	*ft_strnstr(const char*, const char*, size_t);
char	*ft_strrchr(const char*, int);
char	*ft_strcpy(char*, const char*);
char	*ft_strncpy(char*, char*, size_t);
size_t	ft_strlcpy(char*, const char*, size_t);
int		ft_atoi(const char*);
int		ft_isdigit(int);
int		ft_isalpha(int);
int		ft_isascii(int);
int		ft_isalnum(int);
int		ft_tolower(int);
int		ft_toupper(int);
int		ft_isprint(int);
#endif