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
 #define LONG_MAX 0x7FFFFFFFL
 #define LONG_MIN ((long) 0x80000000L)

/**
 *	ft_putchar:
 *	Writes a character to the standard output (stdout).
 *	On success, the character written is returned.
 */
int		ft_putchar(int);

/**
 *	ft_putstr:
 *	Writes the string to the given output unit.
 */
void	ft_putstr(char*);

/**
 *	ft_isupper:
 *	Tests for any upper-case letter.
 */
int		ft_isupper(int);

/**
 *	ft_islower:
 *	Tests for any lower-case letter.
 */
int		ft_islower(int);

/**
 *	ft_isspace:
 *	Tests for the white-space characters.
 */
int		ft_isspace(char);

/**
 *	ft_strtol:
 *	Converts the string in str to a long value.
 */
long	ft_strtol(const char*, char**, int);

/**
 *	ft_strlen:
 *	Computes the length of the string s
 */
size_t	ft_strlen(const char*);

/**
 *	ft_strcmp:
 *	Lexicographically compare the null-terminated strings s1 and s2.
 */
int		ft_strcmp(const char*, const char*);

/**
 *	ft_strncmp:
 *	Compares not more than n characters
 */
int		ft_strncmp(const char*, const char*, size_t);

/**
 *	ft_strdup:
 *	Allocates sufficient memory for a copy of the string s1,
 *	does the copy, and returns a pointer to it.
 */
char	*ft_strdup(const char*);

/**
 *	ft_strcat:
 *	Append a copy of the null-terminated string s2 to the end of the
 *	null-terminated string s1, then add a terminating `\0'.
 */
char	*ft_strcat(char*, const char*);

/**
 *	ft_strncat:
 *	Appends not more than n characters from s2,
 *	and then adds a terminating `\0'.
 */
char	*ft_strncat(char*, const char*, size_t);

/**
 *	ft_strchr:
 *	Locates the first occurrence of c (converted to a char)
 *	in the string pointed to by s.
 */
char	*ft_strchr(const char*, int);

/**
 *	ft_strrchr:
 *	Is identical to strchr(), except it locates the last occurrence of c.
 */
char	*ft_strrchr(const char*, int);

/**
 *	ft_strstr:
 *	Locates the first occurrence of the null-terminated string s2
 *	in the null-terminated string s1.
 */
char	*ft_strstr(const char*, const char*);

/**
 *	ft_strnstr:
 *	Locates the first occurrence of the null-terminated string s2
 *	in the string s1, where not more than n characters are searched.
 */
char	*ft_strnstr(const char*, const char*, size_t);

/**
 *	ft_strcpy:
 *	Copy the string s2 to s1 (including the terminating `\0' character).
 */
char	*ft_strcpy(char*, const char*);

/**
 *	ft_strncpy:
 *	copy at most n characters from s2 into s1.  If s2 is less than n characters
 *	long, the remainder of s1 is filled with `\0' characters.
 *	Otherwise, s1 is not terminated.
 */
char	*ft_strncpy(char*, char*, size_t);

/**
 *	ft_strlcpy:
 *	Copies up to size - 1 characters from the NUL-terminated string src to dst,
 *	NUL-terminating the result.
 */
size_t	ft_strlcpy(char*, const char*, size_t);

/**
 *	ft_strlcat:
 *	ppends the NUL-terminated string src to the end of dst.
 *	It will append at most size - ft_strlen(dst) - 1 bytes,
 *	NUL-terminating the result.
 */
size_t	ft_strlcat(char*, const char*, size_t);

/**
 *	ft_memset:
 *	Sets the first num bytes of the block of memory pointed by ptr to
 *	the specified value (interpreted as an unsigned char).
 */
void	*ft_memset(void*, int, size_t);

/**
 *	ft_memcpy:
 *	Copies n bytes from memory area s2 to memory area s1.
 *	If s1 and s2 overlap, behavior is undefined.
 *	Applications in which s1 and s2 might overlap should
 *	use ft_memmove(3) instead
 */
void	*ft_memcpy(void*, const void*, size_t);

/**
 *	ft_memccpy:
 *	Copies bytes from string s2 to string s1.  If the character c
 *	(as converted to an unsigned char) occurs in the string s2,
 *	the copy stops and a pointer to the byte after the copy of c in the string
 *	s1 is returned Otherwise, n bytes are copied, and a NUL pointer is returned
 */
void	*ft_memccpy(void*, const void*, int, size_t);

/**
 *	ft_memmove:
 *	Copies n bytes from string s2 to string s1.  The two strings may overlap;
 *	the copy is always done in a non-destructive manner.
 */
void	*ft_memmove(void*, const void*, size_t);

/**
 *	ft_memchr:
 *	Locates the first occurrence of c (converted to an unsigned char)
 *	in string s.
 */
void	*ft_memchr(const void*, int, size_t);

/**
 *	ft_memcmp:
 *	Compares byte string s1 against byte string s2.
 *	Both strings are assumed to be n bytes long.
 */
int		ft_memcmp(const void*, const void*, size_t);

/**
 *	ft_bzero:
 *	The ft_bzero() function writes n zeroed bytes to the string s.
 *	If n is zero, ft_bzero() does nothing.
 */
void	ft_bzero(void*, size_t);

/**
 *	ft_atoi:
 *	Converts the initial portion of the string pointed
 *	to by str to int representation.
 */
int		ft_atoi(const char*);

/**
 *	ft_isdigit:
 *	Tests for a decimal digit character.
 */
int		ft_isdigit(int);

/**
 *	ft_isalpha:
 *	Tests for any character for which ft_isupper(3) or ft_islower(3) is true.
 */
int		ft_isalpha(int);

/**
 *	ft_isascii:
 *	Tests for an ASCII character, which is any character between
 *	0 and octal 0177 inclusive.
 */
int		ft_isascii(int);

/**
 *	ft_isalnum:
 *	Tests for any character for which ft_isalpha(3) or ft_isdigit(3) is true.
 */
int		ft_isalnum(int);

/**
 *	ft_tolower:
 *	Converts an upper-case letter to the corresponding lower-case letter.
 */
int		ft_tolower(int);

/**
 *	ft_toupper:
 *	Converts an lower-case letter to the corresponding upper-case letter.
 */
int		ft_toupper(int);

/**
 *	ft_isprint:
 *	Tests for any printing character, including space (` ').
 */
int		ft_isprint(int);
#endif
