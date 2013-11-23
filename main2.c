/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student@42 <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:43:06 by student@42        #+#    #+#             */
/*   Updated: 2013/11/23 13:21:47 by mfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** author : qperez
** HardCore + strtrim + fixes strlcat : mfontain
** Fixes strsplit : gabtoubl
** Fixes strsplit, strjoin, strsub, strtrim, itoa, strequ, strnequ: stherman
**
** Any segfault ? Probably caused by a NULL test. ex : ft_memset(NULL, 0, 0);
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "libft.h" /* compile with -I./ */

#define D_ERROR { printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }
#define D_TEST  43
#define RANDT   512
#define LONG    10000
 
typedef struct  s_test
{
        const char *name;
        int                     (*funct)(void);
        bool            set;
}                               t_test;
/*
**      PART ONE
*/
#define ALL
#define QUIT
#define MEMSET
#define BZERO
#define MEMCPY
#define MEMCCPY
#define MEMMOVE
#define MEMCHR
#define MEMCMP
#define STRLEN
#define STRDUP
#define STRCPY
#define STRNCPY
#define STRCAT
#define STRNCAT
#define STRLCAT
#define STRCHR
#define STRRCHR
#define STRSTR
#define STRNSTR
#define STRCMP
#define STRNCMP
#define ATOI
#define ISALPHA
#define ISDIGIT
#define ISALNUM
#define ISASCII
#define ISPRINT
#define TOUPPER
#define TOLOWER
/*
**      PART TWO
*/
#define MEMALLOC
#define MEMDEL
#define STRNEW
#define STRDEL
#define PUTCHAR

/*
int                                     uf_free_tab(void **tab)
{
        unsigned int    i;

        if (tab == NULL)
                return (0);
        i = 0;
        while (tab[i] != NULL)
        {
                free(tab[i]);
                i = i + 1;
        }
        free(tab);
        return (1);
}

int                                     uf_test_strtrim(void)
{
        char                    str[] = "  \t    \t\nBon\t \njour\t\n  \n     ";
        char                    str2[] = "Bonjour";
        char                    *r;

        r = ft_strtrim(str);
        if (strcmp(r, "Bon\t \njour"))
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t    \t\nBon\t \njour\t\n  \n     \").\nExpected ret = \"Bon\t \njour\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, r);
                return (0);
        }
        free(r);
        r = ft_strtrim(str2);
    if (strcmp(r, "Bonjour") || (str2 == r))
    {
        printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"Bonjour\").\nExpected ret = \"Bonjour\" and differents pointers\
                           but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str2, r);
        return (0);
    }
    free(r);
        return (1);
}

int                                     uf_test_strsplit(void)
{
        char                    **ret;

        ret = ft_strsplit("", '*');
        if (ret == NULL || ret[0] != NULL)
        {
                printf("Error Line %d, Funct %s : \
                           \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \nUnable to free your tab in first test\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("hello", '*');
        if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
                           but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in second test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("*hello", '*');
        if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
                           but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("*hello*", '*');
        if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello*\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
                           but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("*hel*lo*", '*');
        if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
                           but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fourth test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("*hel*lo*f", '*');
        if (ret[3] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0 &&
                strcmp(ret[2], "f") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*f\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\", tab[2] = \"f\" and tab[3] = NULL \
                           but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\" and tab[3] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fifth test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("g*hel*lo*f", '*');
        if (ret[4] != NULL && strcmp(ret[0], "g") != 0 && strcmp(ret[1], "hel") != 0 &&
                strcmp(ret[2], "lo") != 0 && strcmp(ret[3], "f") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"g*hel*lo*f\", '*').\nExpected tab[0] = \"g\", tab[1] = \"hel\", tab[2] = \"lo\", tab[3] = \"f\" and tab[4] = NULL \
                           but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\", tab[3] = \"%s\" and tab[4] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3], ret[4]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in sixth test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        ret = ft_strsplit("***hel****lo**", '*');
        if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel****lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
                           but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
                uf_free_tab((void **)ret);
                return (0);
        }
        if (uf_free_tab((void **)ret) == 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in seventh test\033[0m\n", __LINE__ - 2, __func__);
                return (0);
        }
        return (1);
}

int                             uf_test_strjoin(void)
{
        char            *ret;

        ret = ft_strjoin("Hello ", "boys");
        if (strcmp(ret, "Hello boys") != 0)
        {
                D_ERROR
                free(ret);
                return (0);
        }
        free(ret);
        ret = ft_strjoin("", "boys");
    if (strcmp(ret, "boys") != 0)
    {
                D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
        ret = ft_strjoin("Hello ", "");
    if (strcmp(ret, "Hello ") != 0)
    {
                D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
        ret = ft_strjoin("", "");
    if (strcmp(ret, "") != 0)
    {
                D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
        return (1);
}

int                             uf_test_strsub(void)
{
        char            *ret;
        char            str[] = "*Hello*";

        ret = ft_strsub(str, 1, 5);
        if (strcmp(ret, "Hello") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strbub(\"*Hello*\", 1, 5).\nExpected ret = \"Hello\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        return (1);
}

void                    uf_striteri_callback(unsigned int i, char *s)
{
        *s = *s + i;
}

void                    uf_striter_callback(char *s)
{
        *s = *s + 1;
}

char                    uf_strmap_callback(char s)
{
        return (s + 1);
}

char                    uf_strmapi_callback(unsigned int i, char s)
{
        return (s + i);
}

int                             uf_test_itoa(void)
{
        char            *ret;
        if (strcmp(ret = ft_itoa(0), "0") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_itoa(0).\nExpected ret = \"0\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        if (strcmp(ret = ft_itoa(-123), "-123") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_itoa(-123).\nExpected ret = \"-123\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        if (strcmp(ret = ft_itoa(123), "123") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_itoa(123).\nExpected ret = \"123\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        if (strcmp(ret = ft_itoa(-2147483648), "-2147483648") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_itoa(-2147483648).\nExpected ret = \"-2147483648\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        if (strcmp(ret = ft_itoa(2147483647), "2147483647") != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_itoa(2147483647).\nExpected ret = \"2147483647\" \
                           but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
                free(ret);
                return (0);
        }
        free(ret);
        return (1);
}

int                             uf_test_strnequ(void)
{
        int                     ret;

        ret = 0;
        if ((ret = ft_strnequ("abc", "abc", 2)) != 1)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abc\", 2).\nExpected ret = \"1\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                return (0);
        }
        if ((ret = ft_strnequ("cba", "abc", 2)) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"cba\", \"abc\", 2).\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                return (0);
        }
        if ((ret = ft_strnequ("abc", "cba", 2)) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"cba\", 2).\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                return (0);
        }
        if ((ret = ft_strnequ("abc", "abd", 2)) != 1)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abd\", 2).\nExpected ret = \"1\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                return (0);
        }
        if ((ret = ft_strnequ("", "", 3)) != 1)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"\", \"\", 3).\nExpected ret = \"1\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                return (0);
        }
        return (1);
}

int                             uf_test_strequ(void)
{
        int                     ret;

        ret = 0;
        if ((ret = ft_strequ("abc", "abc")) != 1)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abc\").\nExpected ret = \"1\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        if ((ret = ft_strequ("cba", "abc")) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"cba\", \"abc\").\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        if ((ret = ft_strequ("abc", "cba")) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"cba\").\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        if ((ret = ft_strequ("", "")) != 1)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"\", \"\").\nExpected ret = \"1\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        if ((ret = ft_strequ("abc", "abcd")) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abcd\").\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        if ((ret = ft_strequ("abcd", "abc")) != 0)
        {
                printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abcd\", \"abc\").\nExpected ret = \"0\" \
                           but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
                        return (0);
        }
        return (1);
}

int                             uf_test_strmapi(void)
{
        char            str[] = "Hello";
        char            *ret;

        ret = ft_strmapi(str, uf_strmapi_callback);
        if (strcmp(ret, "Hfnos") != 0)
        {
                printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
                free(ret);
                return (0);
        }
        free(ret);
        return (1);
}

int                             uf_test_strmap(void)
{
        char            str[] = "Hello";
        char            *ret;

        ret = ft_strmap(str, uf_strmap_callback);
        if (strcmp(ret, "Ifmmp") != 0)
        {
                printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
                free(ret);
                return (0);
        }
        free(ret);
        return (1);
}


int                             uf_test_striteri(void)
{
        char            str[] = "Hello";

        ft_striteri(str, uf_striteri_callback);
        if (strcmp(str, "Hfnos") != 0)
                D_ERROR
        return (1);
}

int                             uf_test_striter(void)
{
        char            str[] = "Hello";

        ft_striter(str, uf_striter_callback);
        if (strcmp(str, "Ifmmp") != 0)
                D_ERROR
        return (1);
}

int                             uf_test_strclr(void)
{
        int                     i;
        char            str[] = "Hello";

        i = 0;
        ft_strclr(str);
        while (i < 6)
        {
                if (str[i] != '\0')
                        D_ERROR
        i = i + 1;
        }
        return (1);
}

int                             uf_test_strdel(void)
{
        char            *ret;

        ret = ft_strnew(4);
        ft_strdel(&ret);
        if (ret != NULL)
                D_ERROR
        ret = ft_strnew(0);
        ft_strdel(&ret);
        if (ret != NULL)
                D_ERROR
        return (1);
}

int                             uf_test_strnew(void)
{
        char            *ret;
        int                     i;

        i = 0;
        ret = ft_strnew(4);
        if (ret != NULL)
        {
                while (i < 5)
                {
                        if (ret[i] != '\0')
                                D_ERROR
                        i = i + 1;
                }
        }
        return (1);
}

int                             uf_test_memalloc_and_del(void)
{
        void            *ret;

        ret = ft_memalloc(4);
        ft_memdel(&ret);
        if (ret != NULL)
                D_ERROR
        return (1);
}
*/
/*
int                             uf_test_putchar(void)
{
        int                     i;

        i = -1024;
        while (i < 1024)
        {
                if (ft_putchar(i) != putchar(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
*/
int                             uf_test_tolower(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (tolower(i) != ft_tolower(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}


int                             uf_test_toupper(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (toupper(i) != ft_toupper(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_isprint(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (isprint(i) != ft_isprint(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_isascii(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (isascii(i) != ft_isascii(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_isalnum(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (isalnum(i) != ft_isalnum(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_isdigit(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (isdigit(i) != ft_isdigit(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_isalpha(void)
{
        int                     i;

        i = -300;
        while (i < 300)
        {
                if (isalpha(i) != ft_isalpha(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}

int                             uf_test_atoi(void)
{
        size_t          i, j;
        char            str[12] = {0};

        if (atoi("\n\v\t\r\f -123") != ft_atoi("\v\t\r\f-123"))
                D_ERROR
        if (atoi("12-3") != ft_atoi("12-3"))
                D_ERROR
        if (atoi("-+123") != ft_atoi("-+123"))
                D_ERROR
        if (atoi("a123") != ft_atoi("a123"))
                D_ERROR
        if (atoi("123a") != ft_atoi("123a"))
                D_ERROR
        if (atoi("123") != ft_atoi("123"))
                D_ERROR
        if (atoi("-123") != ft_atoi("-123"))
                D_ERROR
        if (atoi("+123") != ft_atoi("+123"))
                D_ERROR
        if (atoi(" - 123") != ft_atoi(" - 123"))
                D_ERROR
        if (atoi("\t -123") != ft_atoi("\t-123"))
                D_ERROR
        if (atoi("-2147483648") != ft_atoi("-2147483648"))
                D_ERROR
        if (atoi("2147483647") != ft_atoi("2147483647"))
                D_ERROR
        if (atoi("") != ft_atoi(""))
                D_ERROR
        i = 0;
        while (i < RANDT * LONG)
        {
                j = 0;
                while (j < 11)
                {
                        str[j] = (char)rand();
                        j++;
                }
                if (atoi(str) != ft_atoi(str))
                        D_ERROR
                i++;
        }
        return (1);
}

int                             uf_test_strncmp(void)
{
        if (ft_strncmp("abc", "abc", 2))
                D_ERROR
        if (!ft_strncmp("cba", "abc", 2))
                D_ERROR
        if (!ft_strncmp("abc", "cba", 2))
                D_ERROR
        if (strncmp("", "", 3) != ft_strncmp("", "", 3))
                D_ERROR
        return (1);
}

int                             uf_test_strcmp(void)
{
        if (ft_strcmp("abc", "abc"))
                D_ERROR
        if (!ft_strcmp("cba", "abc"))
                D_ERROR
        if (!ft_strcmp("abc", "cba"))
                D_ERROR
        if (strcmp("", "") != ft_strcmp("", ""))
                D_ERROR
        return (1);
}

int                             uf_test_strnstr(void)
{
        char            *str = "Hello les genw";

        if (strnstr(str, "Hello", 3) != ft_strnstr(str, "Hello", 3))
                D_ERROR
        if (strnstr(str, "les", 1) != ft_strnstr(str, "les", 1))
                D_ERROR
        if (strnstr(str, "gen", 2) != ft_strnstr(str, "gen", 2))
                D_ERROR
        if (strnstr(str, "w", 0) != ft_strnstr(str, "w", 0))
                D_ERROR
        if (strnstr(str, "", 3) != ft_strnstr(str, "", 3))
                D_ERROR
        return (1);
}

int                             uf_test_strstr(void)
{
        char            *str = "Hello les genw";

        if (strstr(str, "Hello") != ft_strstr(str, "Hello"))
                D_ERROR
        if (strstr(str, "les") != ft_strstr(str, "les"))
                D_ERROR
        if (strstr(str, "gen") != ft_strstr(str, "gen"))
                D_ERROR
        if (strstr(str, "w") != ft_strstr(str, "w"))
                D_ERROR
        if (strstr(str, "") != ft_strstr(str, ""))
                D_ERROR
        return (1);
}

int                             uf_test_strrchr(void)
{
        char            str[] = "Hello je tesx";

        if (strrchr(str, 'H') != ft_strrchr(str, 'H'))
                D_ERROR
        if (strrchr(str, 'j') != ft_strrchr(str, 'j'))
                D_ERROR
        if (strrchr(str, 'x') != ft_strrchr(str, 'x'))
                D_ERROR
        if (strrchr(str, 0) != ft_strrchr(str, 0))
                D_ERROR
        return (1);
}

int                             uf_test_strchr(void)
{
        char            str[] = "Hello je tesx";

        if (strchr(str, 'H') != ft_strchr(str, 'H'))
                D_ERROR
        if (strchr(str, 'j') != ft_strchr(str, 'j'))
                D_ERROR
        if (strchr(str, 'x') != ft_strchr(str, 'x'))
                D_ERROR
        if (strchr(str, 'y') != ft_strchr(str, 'y'))
                D_ERROR
        if (strchr(str, 0) != ft_strchr(str, 0))
                D_ERROR
        return (1);
}

/*
** Not HardCore but better than original
*/

int                             uf_test_strlcat(void)
{
        char            dest[50] = {0};
        char            dest2[50] = {0};
        size_t          i;

        if (strlcat(dest, "Hello ", 4) != ft_strlcat(dest2, "Hello ", 4))
                D_ERROR
        memset(dest, 0, sizeof(dest));
        memset(dest2, 0, sizeof(dest));
        strlcat(dest, "Hello ", 4);
        ft_strlcat(dest2, "Hello ", 4);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        strlcat(dest, "Hello ", 1);
        ft_strlcat(dest2, "Hello ", 1);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        i = 0;
        while (i < 6)
        {
                dest[4 + i] = 'z';
                dest2[4 + i] = 'z';
                ++i;
        }
        strlcat(dest, "abc", 6);
        ft_strlcat(dest2, "abc", 6);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        return (1);
}

int                             uf_test_strncat(void)
{
        char            dest[50] = {0};
        char            dest2[50] = {0};

        if (strncat(dest, "hello ", 2) != ft_strncat(dest, "hello ", 2))
                D_ERROR
        memset(dest, 0, sizeof(dest));
        strncat(dest, "Hello ", 4);
        ft_strncat(dest2, "Hello ", 4);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        strncat(dest, "Hello ", 2);
        ft_strncat(dest2, "Hello ", 2);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        return (1);
}

int                             uf_test_strcat(void)
{
        char            dest[50] = {0};
        char            dest2[50] = {0};

        if (strcat(dest, "hello ") != ft_strcat(dest, "hello "))
                D_ERROR
        memset(dest, 0, sizeof(dest));
        strcat(dest, "Hello ");
        ft_strcat(dest2, "Hello ");
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        strcat(dest, "Hello ");
        ft_strcat(dest2, "Hello ");
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        return (1);
}

int                             uf_test_strncpy(void)
{
        int                     i;
        char            dest[50] = {0};
        char            dest2[50] = {0};

        i = 0;
        if (strncpy(dest, "Hello foo", 6) != ft_strncpy(dest, "Hello foo", 6))
                D_ERROR
        strncpy(dest, "Hello foo", 6);
        ft_strncpy(dest2, "Hello foo", 6);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        strncpy(dest, "Hello", 2);
        ft_strncpy(dest2, "Hello", 2);
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        dest[19] = 'a';
        ft_strncpy(dest, "", 40);
        if (dest[19] != '\0')
                D_ERROR
        dest2[19] = 'a';
        strncpy(dest2, "", 40);
        if (dest2[19] != '\0')
                D_ERROR
        memset(dest, '\0', sizeof(dest));
        memset(dest2, '\0', sizeof(dest));
        strncpy(dest, "abc", 3);
        strncpy(dest, "123", 1);
        if (dest[1] != 'b' && dest[2] != 'c')
                D_ERROR
        ft_strncpy(dest2, "abc", 3);
        ft_strncpy(dest2, "123", 1);
        if (dest[1] != 'b' && dest[2] != 'c')
                D_ERROR
        return (1);
}

int                             uf_test_strcpy(void)
{
        char            dest[50] = {0};
        char            dest2[50] = {0};

        if (strcpy(dest, "Hello foo") != ft_strcpy(dest, "Hello foo"))
                D_ERROR
        strcpy(dest, "Hello foo");
        ft_strcpy(dest2, "Hello foo");
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        strcpy(dest, "Hello");
        ft_strcpy(dest2, "Hello");
        if (strcmp(dest, dest2) != 0)
                D_ERROR
        return (1);
}

int                             uf_test_strdup(void)
{
        char            *ret1;
        char            *ret2;

        ret1 = strdup("");
        ret2 = ft_strdup("");
        if (strcmp(ret1, ret2) != 0)
                D_ERROR
        free(ret1);
        free(ret2);
        ret1 = strdup("hello");
        ret2 = ft_strdup("hello");
        if (strcmp(ret1, ret2) != 0)
                D_ERROR
        free(ret1);
        free(ret2);
        return (1);
}

int                             uf_test_strlen(void)
{
        if (strlen("") != ft_strlen(""))
                D_ERROR
        if (strlen("abc") != ft_strlen("abc"))
                D_ERROR
        if (strlen("a") != ft_strlen("a"))
                D_ERROR
        return (1);
}

int                             uf_test_memmove(void)
{
        char            str[] = "memmove can be very useful......";
        char            str2[] = "memmove can be very useful......";
        char            str3[] = "memmove can be very useful......";
        char            str4[] = "memmove can be very useful......";

        char    *s1, *s2;

        if (strcmp((const char *)memmove(str + 10, str + 5, 10), (const char *)ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
                D_ERROR
        if (strcmp((s1 = (char *)memmove(str3 + 5, str3 + 10, 10)), (s2 = (char *)ft_memmove(str4 + 5, str4 + 10, 10))) != 0)
                D_ERROR
        return (1);
}

int                             uf_test_memchr(void)
{
        char            tab[12] = "Hello boys\0";
        char            tab2[12] = "Hello boys\0";
        char            cpy[7] = "olleh\0";

        if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
                D_ERROR
        memcpy(tab, "Hello", 5);
        ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
        memccpy(tab, cpy, 'o', sizeof(cpy));
        if (memchr(tab, 'y', sizeof(tab)) != ft_memchr(tab, 'y', sizeof(tab)))
                D_ERROR
        ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
        memccpy(tab + 1, cpy, 7, sizeof(cpy));
        if (memchr(tab, 'h', sizeof(tab)) != ft_memchr(tab, 'h', sizeof(tab)))
                D_ERROR
        return (1);
}

int                             uf_test_memcmp(void)
{
    char            ctab[11], ctab2[11];
    int             itab[11], itab2[11];
    unsigned long   ltab[11], ltab2[11];
    size_t          i, j;

        if (memcmp(NULL, NULL, 0) != ft_memcmp(NULL, NULL, 0))
                D_ERROR
    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 11)
        {
            ctab[j] = (char)rand();
            ctab2[j] = (char)rand();
                        itab[j] = rand();
                        itab2[j] = rand();
            ltab[j] = (unsigned long)rand() * LONG;
                        ltab2[j] = (unsigned long)rand() * LONG;
            j++;
        }
                if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
            D_ERROR
        memcpy(ctab2, ctab, sizeof(ctab));
                if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
            D_ERROR
                if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
            D_ERROR
                memcpy(itab2, itab, sizeof(itab));
        if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
            D_ERROR
                if (memcmp(ltab, ltab2, sizeof(ltab)) != ft_memcmp(ltab, ltab2, sizeof(ltab)))
            D_ERROR
                memcpy(ltab2, ltab, sizeof(ltab));
        if (memcmp(ltab, ltab2, sizeof(ltab)) != ft_memcmp(ltab, ltab2, sizeof(ltab)))
            D_ERROR
                                ++i;
    }
        return (1);
}

int                             uf_test_memccpy(void)
{
        char                    ctab[11], ctab2[11], ctab3[11];
        int                             itab[11], itab2[11], itab3[11];
        unsigned long   ltab[11], ltab2[11], ltab3[11];
        int                             i, j;
        size_t                  k;
        void                    *temp, *temp2;

        memccpy(NULL, NULL, 0, 0);
        ft_memccpy(NULL, NULL, 0, 0);
        k = 0;
        while (k <= sizeof(ltab))
        {
                i = 0;
                while (i < RANDT)
                {
                        j = 0;
                        while (j < 11)
                        {
                                ctab[j] = (char)rand();
                                ctab2[j] = 0; ctab3[j] = 0;
                                itab[j] = rand();
                                itab2[j] = 0; itab3[j] = 0;
                                ltab[j] = (unsigned long)rand() * LONG;
                                ltab2[j] = 0; ltab3[j] = 0;
                                j++;
                        }
                        temp = memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
                        memcpy(ctab3, ctab2, sizeof(ctab));
                        temp2 = ft_memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
                        if ((memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || (temp != temp2)))
                                D_ERROR
                        temp = memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
                        memcpy(itab3, itab2, sizeof(itab));
                        temp2 = ft_memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
                        if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp != temp2)))
                                D_ERROR
                        temp = memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
                        memcpy(ltab3, ltab2, sizeof(ltab));
                        temp2 = ft_memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
                        if ((memcmp(ltab2, ltab3, sizeof(ltab)) != 0 || (temp != temp2)))
                                D_ERROR
                        ++i;
                }
                ++k;
        }
        return (1);
}

int                                     uf_test_memcpy(void)
{
        char                    ctab[11], ctab2[11], ctab3[11];
        int                             itab[11], itab2[11], itab3[11];
        unsigned long   ltab[11], ltab2[11], ltab3[11];
        int                             i, j;
        size_t                  k;
        void                    *temp, *temp2, *temp3;

        memcpy(NULL, NULL, 0);
        ft_memcpy(NULL, NULL, 0);
        k = 0;
        while (k <= sizeof(ltab))
        {
                i = 0;
                while (i < RANDT)
                {
                        j = 0;
                        while (j < 11)
                        {
                                ctab[j] = (char)rand();
                                ctab2[j] = 0; ctab3[j] = 0;
                                itab[j] = rand();
                                itab2[j] = 0; itab3[j] = 0;
                                ltab[j] = (unsigned long)rand() * LONG;
                                ltab2[j] = 0; ltab3[j] = 0;
                                j++;
                        }
                        memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
                        temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
                        memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
                        temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
                        memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
                        temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
                        if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp2 != itab3)))
                                D_ERROR
                        if (memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3)
                                D_ERROR
                        if (memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3))
                                D_ERROR
                        ++i;
                }
                ++k;
        }
        return (1);
}

int                                     uf_test_memset(void)
{
        char                    ctab[11], ctab2[11];
        int                             itab[11], itab2[11];
        unsigned long   ltab[11], ltab2[11];
        size_t                  i, j, k;
        void                    *temp, *temp2;

        memset(NULL, 0, 0);
        ft_memset(NULL, 0, 0);
        k = 0;
        while (k <= sizeof(ltab))
        {
                i = 0;
                while (i < RANDT)
                {
                        j = 0;
                        while (j < 11)
                        {
                                ctab[j] = (char)rand();
                                itab[j] = rand();
                                ltab[j] = (unsigned long)rand() * LONG;
                                j++;
                        }
                        memcpy(ctab2, ctab, sizeof(ctab));
                        memcpy(itab2, itab, sizeof(itab));
                        memcpy(ltab2, ltab, sizeof(ltab));
                        temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
                        temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
                        if (memcmp(itab, itab2, sizeof(itab)) != 0 || temp != itab || temp2 != itab2)
                                D_ERROR
                        temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
                        temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
                        if (memcmp(ctab, ctab2, sizeof(ctab)) != 0 || temp != ctab || temp2 != ctab2)
                                D_ERROR
                        temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
                        temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
                        if (memcmp(ltab, ltab2, sizeof(ltab)) != 0 || temp != ltab || temp2 != ltab2)
                                D_ERROR
                        ++i;
                }
                ++k;
        }
        return (1);
}

int                                     uf_test_bzero(void)
{
        char                    ctab[11], ctab2[11];
        int                             itab[11], itab2[11];
        unsigned long   ltab[11], ltab2[11];
        size_t                  i, j;

        i = 0;
        bzero(NULL, 0);
        ft_bzero(NULL, 0);
        while (i < 11)
        {
                j = 0;
                while (j < 11)
                {
                        ctab[j] = (char)rand();
                        itab[j] = rand();
                        ltab[j] = (unsigned long)rand() * LONG;
                        j++;
                }
                memcpy(ctab2, ctab, sizeof(ctab));
                memcpy(itab2, itab, sizeof(itab));
                memcpy(ltab2, ltab, sizeof(ltab));
                bzero(ctab2, i);
                ft_bzero(ctab, i);
                if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
                        D_ERROR
                bzero(itab2, i);
                ft_bzero(itab, i);
                if (memcmp(itab, itab2, sizeof(itab)) != 0)
                        D_ERROR
                bzero(ltab2, i);
                ft_bzero(ltab, i);
                if (memcmp(ltab, ltab2, sizeof(ltab)) != 0)
                        D_ERROR
                ++i;
        }
        return (1);
}

void                            uf_add_test(t_test *test, const char *name, int (*funct)(void))
{
        static int              i = 0;

        test[i].name = name;
        test[i].funct = funct;
        test[i].set = true;
        i = i + 1;
}
 
int             main(void)
{
        int             i;
        t_test  test[D_TEST];
 
        i = 0;

        char    str[256];
 
        /*printf("\n>--------------------------------------------------------------------<\n\n");*/
        printf("function: ");
        scanf("%s", str);
        ft_putchar('\n');

#ifdef  QUIT
        if (strcmp(str, "quit") == 0)
        {
                printf(">-----------------------------\033[31mGOOD LUCK\033[0m------------------------------<\n");
                return (0);
        }
#endif

#ifdef  ALL
        if (strcmp(str, "all") == 0)
        {
                srand(time(NULL));
                /*printf("[\033[33mYellow Tests\033[0m] are Hardcore\n");*/
                i = 0;
                memset(test, 0, D_TEST);
                uf_add_test(test, "\033[33mmemset\033[0m", uf_test_memset);
                uf_add_test(test, "\033[33mbzero\033[0m", uf_test_bzero);
                uf_add_test(test, "\033[33mmemcpy\033[0m", uf_test_memcpy);
                uf_add_test(test, "\033[33mmemccpy\033[0m", uf_test_memccpy);
                uf_add_test(test, "memmove", uf_test_memmove);
                uf_add_test(test, "memchr", uf_test_memchr);
                uf_add_test(test, "\033[33mmemcmp\033[0m", uf_test_memcmp);
                uf_add_test(test, "strlen", uf_test_strlen);
                uf_add_test(test, "strdup", uf_test_strdup);
                uf_add_test(test, "strcpy", uf_test_strcpy);
                uf_add_test(test, "strncpy", uf_test_strncpy);
                uf_add_test(test, "strcat", uf_test_strcat);
                uf_add_test(test, "strncat", uf_test_strncat);
                uf_add_test(test, "strlcat", uf_test_strlcat);
                uf_add_test(test, "strchr", uf_test_strchr);
                uf_add_test(test, "strrchr", uf_test_strrchr);
                uf_add_test(test, "strstr", uf_test_strstr);
                uf_add_test(test, "strnstr", uf_test_strnstr);
                uf_add_test(test, "strcmp", uf_test_strcmp);
                uf_add_test(test, "strncmp", uf_test_strncmp);
                uf_add_test(test, "\033[33matoi\033[0m", uf_test_atoi);
                uf_add_test(test, "\033[33malpha\033[0m", uf_test_isalpha);
                uf_add_test(test, "\033[33mdigit\033[0m", uf_test_isdigit);
                uf_add_test(test, "\033[33malnum\033[0m", uf_test_isalnum);
                uf_add_test(test, "\033[33misascii\033[0m", uf_test_isascii);
                uf_add_test(test, "\033[33misprint\033[0m", uf_test_isprint);
                uf_add_test(test, "\033[33mtoupper\033[0m", uf_test_toupper);
                uf_add_test(test, "\033[33mtolower\033[0m", uf_test_tolower);
                //uf_add_test(test, "putchar", uf_test_putchar);
                /*uf_add_test(test, "memalloc_del", uf_test_memalloc_and_del);
                uf_add_test(test, "strnew", uf_test_strnew);
                uf_add_test(test, "strdel", uf_test_strdel);
                uf_add_test(test, "strclr", uf_test_strclr);
                uf_add_test(test, "striter", uf_test_striter);
                uf_add_test(test, "striteri", uf_test_striteri);
                uf_add_test(test, "strmap", uf_test_strmap);
                uf_add_test(test, "strmapi", uf_test_strmapi);
                uf_add_test(test, "strequ", uf_test_strequ);
                uf_add_test(test, "strnequ", uf_test_strnequ);
                uf_add_test(test, "strsub", uf_test_strsub);
                uf_add_test(test, "strjoin", uf_test_strjoin);
                uf_add_test(test, "strsplit", uf_test_strsplit);
                uf_add_test(test, "itoa", uf_test_itoa);
                uf_add_test(test, "strtrim", uf_test_strtrim);*/
                while (i < D_TEST && test[i].set == true)
                {
                        printf("Test [%s] : ", test[i].name);
                        if (test[i].funct() == 0)
                                printf("\033[31mFAIL\033[0m\n");
                        else
                                printf("\033[32mOK\033[0m\n");
                        i = i + 1;
                }
                return (0);
        }
        else
#endif
 
#ifdef  MEMSET
        if (strcmp(str, "memset") == 0)
        {
                char                    b[256];
                char                    *b2;
                char                    c;
                char                    c2;
                int                             len;
                int                             len2;
 
                printf("void    *memset(void *b, int c, size_t len);\n");
                printf("b = ");
                scanf("%s", b);
                printf("c = ");
                scanf("%s", &c);
                printf("len = ");
                scanf("%d", &len);
                b2 = strdup(b);
                c2 = c;
                len2 = len;
                printf("\nmemset(\"%s\", '%c', %d) :\n", b, c, len);
                printf("%s\n", (char *)memset(b, c, len));
                printf("b = %s\n", b);
                printf("\nft_memset(\"%s\", '%c', %d) :\n", b2, c2, len2);
                printf("%s\n", (char *)ft_memset(b2, c2, len2));
                printf("b = %s\n", b2);
                free(b2);
        }
        else
#endif
#ifdef  BZERO
        if (strcmp(str, "bzero") == 0)
        {
                char                    s[256];
                char                    *s2;
                int                             n;
                int                             n2;
                int                             len;
                int                             i;
 
                printf("void    bzero(void *s, size_t n);\n");
                printf("s = ");
                scanf("%s", s);
                printf("n = ");
                scanf("%d", &n);
                len = ((int)ft_strlen(s) + 1 > n) ? (int)ft_strlen(s) + 1 : n;
                s2 = strdup(s);
                n2 = n;
                printf("\nbzero(\"%s\", %d) :\n", s, n);
                bzero(s, n);
                i = 0;
                while (i < len)
                {
                        printf("s[%d] = '%c'\n", i, s[i]);
                        i++;
                }
                printf("\nft_bzero(\"%s\", %d) :\n", s2, n2);
                ft_bzero(s2, n2);
                i = 0;
                while (i < len)
                {
                        printf("s[%d] = '%c'\n", i, s2[i]);
                        i++;
                }
                free(s2);
        }
        else
#endif
#ifdef  MEMCPY
        if (strcmp(str, "memcpy") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                int             n;
                int             n2;
 
                printf("void    *memcpy(void *s1, const void *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nmemcpy(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%s\n", (char *)memcpy(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_memcpy(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
                printf("%s\n", (char *)ft_memcpy(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  MEMCCPY
        if (strcmp(str, "memccpy") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                char    c;
                char    c2;
                int             n;
                int             n2;
 
                printf("void    *memccpy(void *s1, const void *s2, int c, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("c = ");
                scanf("%s", &c);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                c2 = c;
                n2 = n;
                printf("\nmemccpy(\"%s\", \"%s\", %d, %d) :\n", s1, s2, c, n);
                printf("%s\n", (char *)memccpy(s1, s2, c, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_memccpy(\"%s\", \"%s\", %d, %d) :\n", s12, s22, c2, n2);
                printf("%s\n", (char *)ft_memccpy(s12, s22, c2, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  MEMMOVE
        if (strcmp(str, "memmove") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                int             n;
                int             n2;
 
                printf("void    *memmove*(void *s1, const *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s",s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nmemmove(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%s\n", (char *)memmove(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_memmove(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
                printf("%s\n", (char *)ft_memmove(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  MEMCHR
        if (strcmp(str, "memchr") == 0)
        {
                char                    s[256];
                char                    *s2;
                char                    c;
                char                    c2;
                int                             n;
                int                             n2;
 
                printf("void    *memchr(void *s, int c, size_t n);\n");
                printf("s = ");
                scanf("%s", s);
                printf("c = ");
                scanf("%s", &c);
                printf("n = ");
                scanf("%d", &n);
                s2 = strdup(s);
                c2 = c;
                n2 = n;
                printf("\nmemchr(\"%s\", '%c', %d) :\n", s, c, n);
                printf("%s\n", (char *)memchr(s, c, n));
                printf("s = %s\n", s);
                printf("\nft_memchr(\"%s\", '%c', %d) :\n", s2, c2, n2);
                printf("%s\n", (char *)ft_memchr(s2, c2, n2));
                printf("s = %s\n", s2);
                free(s2);
        }
        else
#endif
#ifdef  MEMCMP
        if (strcmp(str, "memcmp") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                int             n;
                int             n2;
 
                printf("int     memcmp(const void *s1, const void *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nmemcmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%d\n", memcmp(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_memcmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
                printf("%d\n", ft_memcmp(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  STRLEN
        if (strcmp(str, "strlen") == 0)
        {
                char    s[256];
                char    *s2;
 
                printf("size_t  strlen(const char *s);\n");
                printf("s = ");
                scanf("%s", s);
                s2 = strdup(s);
                printf("\nstrlen(\"%s\") :\n", s);
                printf("%d\n", (int)strlen(s));
                printf("s = %s\n", s);
                printf("\nft_strlen(\"%s\") :\n", s2);
                printf("%d\n", (int)ft_strlen(s2));
                printf("s = %s\n", s2);
                free(s2);
        }
        else
#endif
#ifdef  STRDUP
        if (strcmp(str, "strdup") == 0)
        {
                char    s1[256];
                char    *s12;
                char    *sdup;
 
                printf("char    *strdup(const char *s1);\n");
                printf("s1 = ");
                scanf("%s", s1);
                s12 = strdup(s1);
                printf("\nstrdup(\"%s\") :\n", s1);
                printf("%s\n", sdup = strdup(s1));
                free(sdup);
                printf("\nft_strdup(\"%s\") :\n", s12);
                printf("%s\n", sdup = strdup(s12));
                free(sdup);
        }
        else
#endif
#ifdef  STRCPY
        if (strcmp(str, "strcpy") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
 
                printf("char    *strcpy(char *s1, const char *s2);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                s12 = strdup(s1);
                s22 = strdup(s2);
                printf("\nstrcpy(\"%s\", \"%s\") :\n", s1, s2);
                printf("%s\n", strcpy(s1, s2));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strcpy(\"%s\", \"%s\") :\n", s12, s22);
                printf("%s\n", ft_strcpy(s12, s22));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  STRNCPY
        if (strcmp(str, "strncpy") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                int             n;
                int             n2;
 
                printf("char    *strncpy(char *s1, const char *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nstrncpy(\"%s\", \"%s\") :\n", s1, s2);
                printf("%s\n", strncpy(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strncpy(\"%s\", \"%s\") :\n", s12, s22);
                printf("%s\n", ft_strncpy(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  STRCAT
        if (strcmp(str, "strcat") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
 
                printf("char    *strcat(char *s1, const char *s2);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                s12 = strdup(s1);
                s22 = strdup(s2);
                printf("\nstrcat(\"%s\", \"%s\") :\n", s1, s2);
                printf("%s\n", strcat(s1, s2));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strcat(\"%s\", \"%s\") :\n", s12, s22);
                printf("%s\n", ft_strcat(s12, s22));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  STRNCAT
        if (strcmp(str, "strncat") == 0)
        {
                char    s1[256];
                char    *s12;
                char    s2[256];
                char    *s22;
                int             n;
                int             n2;
 
                printf("char    *strncat(char *s1, const char *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nstrncat(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%s\n", strncat(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strncat(\"%s\", \"%s\", %d) :\n", s12, s22, n);
                printf("%s\n", ft_strncat(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s12);
                free(s22);
        }
        else
#endif
#ifdef  STRLCAT
        if (strcmp(str, "strlcat") == 0)
        {
                char    dst[256];
                char    *dst2;
                char    src[256];
                char    *src2;
                int             size;
                int             size2;
 
                printf("char    *strlcat(char *dst, const char *src, size_t size);\n");
                printf("dst = ");
                scanf("%s", dst);
                printf("src = ");
                scanf("%s", src);
                printf("size = ");
                scanf("%d", &size);
                dst2 = strdup(dst);
                src2 = strdup(src);
                size2 = size;
                printf("\nstrlcat(\"%s\", \"%s\", %d) :\n", dst, src, size);
                printf("%d\n", (int)strlcat(dst, src, size));
                printf("dst = %s\n", dst);
                printf("src = %s\n", src);
                printf("\nft_strlcat(\"%s\", \"%s\", %d) :\n", dst2, src2, size2);
                printf("%d\n", (int)ft_strlcat(dst2, src2, size));
                printf("dst = %s\n", dst2);
                printf("src = %s\n", src2);
                free(dst2);
                free(src2);
        }
        else
#endif
#ifdef  STRCHR
        if (strcmp(str, "strchr") == 0)
        {
                char                    s[256];
                char                    *s2;
                char                    c;
                char                    c2;
 
                printf("char    *strchr(const char *s, int c);\n");
                printf("s = ");
                scanf("%s", s);
                printf("c = ");
                scanf("%s", &c);
                s2 = strdup(s);
                c2 = c;
                printf("\nstrchr(\"%s\", '%c') :\n", s, c);
                printf("%s\n", strchr(s, c));
                printf("s = %s\n", s);
                printf("\nft_strchr(\"%s\", '%c') :\n", s2, c2);
                printf("%s\n", ft_strchr(s2, c2));
                printf("s = %s\n", s2);
                free(s2);
        }
        else
#endif
#ifdef  STRRCHR
        if (strcmp(str, "strrchr") == 0)
        {
                char                    s[256];
                char                    *s2;
                char                    c;
                char                    c2;
 
                printf("char    *strrchr(const char *s, int c);\n");
                printf("s = ");
                scanf("%s", s);
                printf("c = ");
                scanf("%s", &c);
                s2 = strdup(s);
                c2 = c;
                printf("\nstrrchr(\"%s\", '%c') :\n", s, c);
                printf("%s\n", strrchr(s, c));
                printf("s = %s\n", s);
                printf("\nft_strrchr(\"%s\", '%c') :\n", s2, c2);
                printf("%s\n", ft_strrchr(s2, c2));
                printf("s = %s\n", s2);
                free(s2);
        }
        else
#endif
#ifdef  STRSTR
        if (strcmp(str, "strstr") == 0)
        {
                char                    s1[256];
                char                    *s12;
                char                    s2[256];
                char                    *s22;
 
                printf("char    *strstr(const char *s1, const char *s2);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                s12 = strdup(s1);
                s22 = strdup(s2);
                printf("\nstrstr(\"%s\", \"%s\") :\n", s1, s2);
                printf("%s\n", strstr(s1, s2));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strstr(\"%s\", \"%s\") :\n", s12, s22);
                printf("%s\n", ft_strstr(s12, s22));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s22);
        }
        else
#endif
#ifdef  STRNSTR
        if (strcmp(str, "strnstr") == 0)
        {
                char                    s1[256];
                char                    *s12;
                char                    s2[256];
                char                    *s22;
                int                             n;
                int                             n2;
 
                printf("char    *strnstr(const char *s1, const char *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nstrnstr(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%s\n", strnstr(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strnstr(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
                printf("%s\n", ft_strnstr(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s22);
        }
        else
#endif
#ifdef  STRCMP
        if (strcmp(str, "strcmp") == 0)
        {
                char                    s1[256];
                char                    *s12;
                char                    s2[256];
                char                    *s22;
 
                printf("int     strcmp(const char *s1, const char *s2);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s", s2);
                s12 = strdup(s1);
                s22 = strdup(s2);
                printf("\nstrcmp(\"%s\", \"%s\") :\n", s1, s2);
                printf("%d\n", strcmp(s1, s2));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strcmp(\"%s\", \"%s\") :\n", s12, s22);
                printf("%d\n", ft_strcmp(s12, s22));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s22);
        }
        else
#endif
#ifdef  STRNCMP
        if (strcmp(str, "strncmp") == 0)
        {
                char                    s1[256];
                char                    *s12;
                char                    s2[256];
                char                    *s22;
                int                             n;
                int                             n2;
 
                printf("int     strncmp(const char *s1, const char *s2, size_t n);\n");
                printf("s1 = ");
                scanf("%s", s1);
                printf("s2 = ");
                scanf("%s2", s2);
                printf("n = ");
                scanf("%d", &n);
                s12 = strdup(s1);
                s22 = strdup(s2);
                n2 = n;
                printf("\nstrncmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
                printf("%d\n", strncmp(s1, s2, n));
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                printf("\nft_strncmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
                printf("%d\n", ft_strncmp(s12, s22, n2));
                printf("s1 = %s\n", s12);
                printf("s2 = %s\n", s22);
                free(s22);
        }
        else
#endif
#ifdef  ATOI
        if (strcmp(str, "atoi") == 0)
        {
                char                    s[256];
                char                    *s2;
 
                printf("int     atoi(const char *str);\n");
                printf("s = ");
                scanf("%s", s);
                s2 = strdup(s);
                printf("\natoi(\"%s\") :\n", s);
                printf("%d\n", atoi(s));
                printf("\nft_atoi(\"%s\") :\n", s2);
                printf("%d\n", ft_atoi(s2));
        }
        else
#endif
#ifdef  ISALPHA
        if (strcmp(str, "isalpha") == 0)
        {
                char                    c;
                char                    c2;
 
                printf("int     isalpha(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\nisalpha('%c') :\n", c);
                printf("%d\n", isalpha(c));
                printf("\nft_isalpha('%c') :\n", c2);
                printf("%d\n", ft_isalpha(c2));
        }
        else
#endif
#ifdef  ISDIGIT
        if (strcmp(str, "isdigit") == 0)
        {
                char            c;
                char            c2;
 
                printf("int     isdigit(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\nisdigit('%c') :\n", c);
                printf("%d\n", isdigit(c));
                printf("\nft_isdigit('%c') :\n", c2);
                printf("%d\n", ft_isdigit(c2));
        }
        else
#endif
#ifdef  ISALNUM
        if (strcmp(str, "isalnum") == 0)
        {
                char            c;
                char            c2;
 
                printf("int     isalnum(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\nisalnum('%c') :\n", c);
                printf("%d\n", isalnum(c));
                printf("\nft_isalnum('%c') :\n", c2);
                printf("%d\n", ft_isalnum(c2));
        }
        else
#endif
#ifdef  ISASCII
        if (strcmp(str, "isascii") == 0)
        {
                char            c;
                char            c2;
 
                printf("int     isascii(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\nisascii('%c') :\n", c);
                printf("%d\n", isascii(c));
                printf("\nft_isascii('%c') :\n", c2);
                printf("%d\n", ft_isascii(c2));
        }
        else
#endif
#ifdef  ISPRINT
        if (strcmp(str, "isprint") == 0)
        {
                char            c;
                char            c2;
 
                printf("int     isprint(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\nisprint('%c') :\n", c);
                printf("%d\n", isprint(c));
                printf("\nft_isprint('%c') :\n", c2);
                printf("%d\n", ft_isprint(c2));
        }
        else
#endif
#ifdef  TOUPPER
        if (strcmp(str, "toupper") == 0)
        {
                char            c;
                char            c2;
 
                printf("int toupper(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\ntoupper('%c') :\n", c);
                printf("%c\n", (char)toupper(c));
                printf("c = %c\n", c);
                printf("\nft_toupper('%c') :\n", c2);
                printf("%c\n", (char)ft_toupper(c2));
                printf("c = %c\n", c2);
        }
        else
#endif
#ifdef  TOLOWER
        if (strcmp(str, "tolower") == 0)
        {
                char            c;
                char            c2;
 
                printf("int tolower(int c);\n");
                printf("c = ");
                scanf("%s", &c);
                c2 = c;
                printf("\ntolower('%c') :\n", c);
                printf("%c\n", (char)tolower(c));
                printf("c = %c\n", c);
                printf("\nft_tolower('%c') :\n", c2);
                printf("%c\n", (char)ft_tolower(c2));
                printf("c = %c\n", c2);
        }
        else
#endif

#ifdef  PUTCHAR
        if (strcmp(str, "putchar") == 0)
        {
                char            c;
 
                printf("int ft_putchar(int c):\n");
                printf("c = ");
                scanf("%s", &c);
                printf("\nputchar('%c') :\n", c);
                printf("%c\n", (char)putchar(c));
                printf("c = %c\n", c);
                printf("\nft_putchar('%c') :\n", c);
                printf("%c\n", (char)ft_putchar(c));
                printf("c = %c\n", c);
        }
        else
#endif
                /*
#ifdef  MEMALLOC
        if (strcmp(str, "memalloc") == 0)
        {
                char    *ptr;
                int             size;
                int             i;
 
                printf("void    *ft_memalloc(size_t size);\n");
                printf("size = ");
                scanf("%d", &size);
                printf("\nft_memalloc(%d) :\n", size);
                ptr = (char *)ft_memalloc(size);
                i = 0;
                if (ptr)
                        while (i < size)
                        {
                                printf("ptr[%d] = '%c'\n", i, ptr[i]);
                                i++;
                        }
                else
                        printf("%s\n", ptr);
                free(ptr);
        }
        else
#endif
#ifdef  MEMDEL
        if (strcmp(str, "memdel") == 0)
        {
                char    *ptr;
 
                ptr = malloc(sizeof(char) * 256);
                printf("void    ft_memdel(void  **ap);\n");
                printf("*ap = ");
                scanf("%s", ptr);
                printf("\nft_memdel(&ptr) :\n");
                ft_memdel((void **)&ptr);
                printf("*ap = %s\n", ptr);
        }
        else
#endif
#ifdef  STRNEW
        if (strcmp(str, "strnew") == 0)
        {
                char    *str;
                int             size;
                int             i;
 
                printf("char    *ft_strnew(size_t size);\n");
                printf("size = ");
                scanf("%d", &size);
                printf("\nft_strnew(%d) :\n", size);
                str = ft_strnew(size);
                i = 0;
                if (str)
                        while (i < size + 1)
                        {
                                printf("str[%d] = '%c'\n", i, str[i]);
                                i++;
                        }
                else
                        printf("%s\n", str);
                free(str);
        }
        else
#endif
#ifdef  STRDEL
        if (strcmp(str, "strdel") == 0)
        {
                char    *str;
 
                str = malloc(sizeof(char) * 256);
                printf("void    ft_strdel(void  **as);\n");
                printf("str = ");
                scanf("%s", str);
                printf("\nft_strdel(&str) :\n");
                ft_memdel((void **)&str);
                printf("str = %s\n", str);
        }
        else
#endif*/
        printf("This function does not exist.\n");

        if (!strcmp(str, "all") == 0)
        {                
                srand(time(NULL));
                /*printf("[\033[33mYellow Tests\033[0m] are Hardcore\n");*/
 
                memset(test, 0, D_TEST);
                uf_add_test(test, "\033[33mmemset\033[0m", uf_test_memset);
                uf_add_test(test, "\033[33mbzero\033[0m", uf_test_bzero);
                uf_add_test(test, "\033[33mmemcpy\033[0m", uf_test_memcpy);
                uf_add_test(test, "\033[33mmemccpy\033[0m", uf_test_memccpy);
                uf_add_test(test, "memmove", uf_test_memmove);
                uf_add_test(test, "memchr", uf_test_memchr);
                uf_add_test(test, "\033[33mmemcmp\033[0m", uf_test_memcmp);
                uf_add_test(test, "strlen", uf_test_strlen);
                uf_add_test(test, "strdup", uf_test_strdup);
                uf_add_test(test, "strcpy", uf_test_strcpy);
                uf_add_test(test, "strncpy", uf_test_strncpy);
                uf_add_test(test, "strcat", uf_test_strcat);
                uf_add_test(test, "strncat", uf_test_strncat);
                uf_add_test(test, "strlcat", uf_test_strlcat);
                uf_add_test(test, "strchr", uf_test_strchr);
                uf_add_test(test, "strrchr", uf_test_strrchr);
                uf_add_test(test, "strstr", uf_test_strstr);
                uf_add_test(test, "strnstr", uf_test_strnstr);
                uf_add_test(test, "strcmp", uf_test_strcmp);
                uf_add_test(test, "strncmp", uf_test_strncmp);
                uf_add_test(test, "\033[33matoi\033[0m", uf_test_atoi);
                uf_add_test(test, "\033[33malpha\033[0m", uf_test_isalpha);
                uf_add_test(test, "\033[33mdigit\033[0m", uf_test_isdigit);
                uf_add_test(test, "\033[33malnum\033[0m", uf_test_isalnum);
                uf_add_test(test, "\033[33misascii\033[0m", uf_test_isascii);
                uf_add_test(test, "\033[33misprint\033[0m", uf_test_isprint);
                uf_add_test(test, "\033[33mtoupper\033[0m", uf_test_toupper);
                uf_add_test(test, "\033[33mtolower\033[0m", uf_test_tolower);
                //uf_add_test(test, "putchar", uf_test_putchar);
                /*uf_add_test(test, "memalloc_del", uf_test_memalloc_and_del);
                uf_add_test(test, "strnew", uf_test_strnew);
                uf_add_test(test, "strdel", uf_test_strdel);
                uf_add_test(test, "strclr", uf_test_strclr);
                uf_add_test(test, "striter", uf_test_striter);
                uf_add_test(test, "striteri", uf_test_striteri);
                uf_add_test(test, "strmap", uf_test_strmap);
                uf_add_test(test, "strmapi", uf_test_strmapi);
                uf_add_test(test, "strequ", uf_test_strequ);
                uf_add_test(test, "strnequ", uf_test_strnequ);
                uf_add_test(test, "strsub", uf_test_strsub);
                uf_add_test(test, "strjoin", uf_test_strjoin);
                uf_add_test(test, "strsplit", uf_test_strsplit);
                uf_add_test(test, "itoa", uf_test_itoa);
                uf_add_test(test, "strtrim", uf_test_strtrim);*/

                i = 0;
                while (i < D_TEST && strcmp(test[i].name, str) != 0)
                        i++;

                printf("\n>----------------------");
                printf("Auto test [%s]: ", test[i].name);
                if (test[i].funct() == 0)
                {
                        printf("\033[31mFAIL\033[0m");

                printf("----------------------<\n\n");
                }
                else
                {
                        printf("\033[32mOK\033[0m"); 

                printf("------------------------<\n\n");
                } 
        }



        main();
        return (0);
}
