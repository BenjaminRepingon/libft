#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <xlocale.h>
#include <stdbool.h>
#include <libft.h> /* compile with -I./ */
#define D_ERROR { printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }
 
#define D_TEST  50
 
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


int             uf_test_tolower(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (tolower(i) != ft_tolower(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
 
int             uf_test_toupper(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (toupper(i) != ft_toupper(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_isprint(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (isprint(i) != ft_isprint(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_isascii(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (isascii(i) != ft_isascii(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_isalnum(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (isalnum(i) != ft_isalnum(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_isdigit(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (isdigit(i) != ft_isdigit(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_isalpha(void)
{
        int     i;
 
        i = 0;
        while (i < 255)
        {
                if (isalpha(i) != ft_isalpha(i))
                        D_ERROR
                i = i + 1;
        }
        return (1);
}
 
int             uf_test_atoi(void)
{
        if (atoi("123") != ft_atoi("123"))
                D_ERROR
        if (atoi("-123") != ft_atoi("-123"))
                D_ERROR
        if (atoi("+123") != ft_atoi("+123"))
                D_ERROR
        if (atoi(" 123") != ft_atoi(" 123"))
                D_ERROR
        if (atoi(" - 123") != ft_atoi(" - 123"))
                D_ERROR
        if (atoi("\t -123") != ft_atoi("\t -123"))
                D_ERROR
        if (atoi("-2147483648") != ft_atoi("-2147483648"))
                D_ERROR
        if (atoi("2147483647") != ft_atoi("2147483647"))
                D_ERROR
        return (1);
}
 
int             uf_test_strncmp(void)
{
        if (strncmp("abc", "abc", 2) != ft_strncmp("abc", "abc", 2))
                D_ERROR
        if (strncmp("cba", "abc", 2) != ft_strncmp("cba", "abc", 2))
                D_ERROR
        if (strncmp("abc", "cba", 2) != ft_strncmp("abc", "cba", 2))
                D_ERROR
        if (strncmp("", "", 3) != ft_strncmp("", "", 3))
                D_ERROR
        return (1);
}
 
int             uf_test_strcmp(void)
{
        if (strcmp("abc", "abc") != ft_strcmp("abc", "abc"))
                D_ERROR
        if (strcmp("cba", "abc") != ft_strcmp("cba", "abc"))
                D_ERROR
        if (strcmp("abc", "cba") != ft_strcmp("abc", "cba"))
                D_ERROR
        if (strcmp("", "") != ft_strcmp("", ""))
                D_ERROR
        return (1);
}
 
int             uf_test_strnstr(void)
{
        char    *str = "Hello les genw";
 
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
 
int             uf_test_strstr(void)
{
        char    *str = "Hello les genw";
 
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
 
int     uf_test_strrchr(void)
{
        char    str[] = "Hello je tesx";
 
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
 
int     uf_test_strchr(void)
{
        char    str[] = "Hello je tesx";
 
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
 
int     uf_test_strlcat(void)
{
        char    dest[50] = {0};
        char    dest2[50] = {0};
 
 
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
        return (1);
}
 
int     uf_test_strncat(void)
{
        char    dest[50] = {0};
        char    dest2[50] = {0};
 
 
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
 
int     uf_test_strcat(void)
{
        char    dest[50] = {0};
        char    dest2[50] = {0};
 
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
 
int     uf_test_strncpy(void)
{
        char    dest[50] = {0};
        char    dest2[50] = {0};
 
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
        return (1);
}
 
int     uf_test_strcpy(void)
{
        char    dest[50] = {0};
        char    dest2[50] = {0};
 
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
 
int     uf_test_strdup(void)
{
        char    *ret1;
        char    *ret2;
 
        ret1 = strdup("");
        ret2 = strdup("");
        if (strcmp(ret1, ret2) != 0)
                D_ERROR
        free(ret1);
        free(ret2);
        ret1 = strdup("hello");
        ret2 = strdup("hello");
        if (strcmp(ret1, ret2) != 0)
                D_ERROR
        free(ret1);
        free(ret2);
        return (1);
}
 
int     uf_test_strlen(void)
{
        if (strlen("") != ft_strlen(""))
                D_ERROR
        if (strlen("abc") != ft_strlen("abc"))
                D_ERROR
        if (strlen("a") != ft_strlen("a"))
                D_ERROR
        return (1);
}
 
int     uf_test_memmove(void)
{
        char    str[] = "memmove can be very useful......";
        char    str2[] = "memmove can be very useful......";
        char    str3[] = "memmove can be very useful......";
        char    str4[] = "memmove can be very useful......";
 
        if (strcmp(memmove(str + 10, str + 5, 10), ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
                D_ERROR
        if (strcmp(memmove(str3 + 5, str3 + 10, 10), ft_memmove(str4 + 5, str4 + 10, 10)) != 0)
                D_ERROR
        return (1);
}
 
int     uf_test_memchr(void)
{
        char    tab[11] = "Hello boys\0";
        char    tab2[11] = "Hello boys\0";
        char    cpy[6] = "olleh\0";
 
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
 
int     uf_test_memcmp(void)
{
        char    tab[11] = "Hello boys\0";
        char    tab2[11] = "Hello boys\0";
        char    cpy[6] = "olleh\0";
 
        if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
                D_ERROR
        memcpy(tab, "Hello", 5);
        ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
        memccpy(tab, cpy, 'o', sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
                D_ERROR
        ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
        memccpy(tab + 1, cpy, 7, sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
                D_ERROR
        return (1);
}
 
int     uf_test_memccpy(void)
{
        char    tab[12] = "Hello boys\0";
        char    tab2[12] = "Hello boys\0";
        char    cpy[7] = "olleh\0";
 
        if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
                D_ERROR
        memcpy(tab, "Hello", 5);
        ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
        memccpy(tab, cpy, 'o', sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != 0)
                D_ERROR
        ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
        memccpy(tab + 1, cpy, 7, sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != 0)
                D_ERROR
        return (1);
}
 
int     uf_test_memcpy(void)
{
        int     tab[9];
        int     tab2[9];
        int     cpy[4];
 
        cpy[0] = 3;
        cpy[1] = 4;
        cpy[2] = 5;
        cpy[3] = 7;
        memset(tab, 0, sizeof(tab));
        memset(tab2, 0, sizeof(tab));
        if (ft_memcpy(tab, cpy, sizeof(cpy)) != memcpy(tab, cpy, sizeof(cpy)))
                D_ERROR
        memset(tab, 0, sizeof(tab));
        memset(tab2, 0, sizeof(tab));
        ft_memcpy(tab2, cpy, sizeof(cpy));
        memcpy(tab, cpy, sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != 0)
                D_ERROR
        ft_memcpy(tab2 + 1, cpy, sizeof(cpy));
        memcpy(tab + 1, cpy, sizeof(cpy));
        if (memcmp(tab, tab2, sizeof(tab)) != 0)
                D_ERROR
        return (1);
}
 
int     uf_test_memset(void)
{
        int             itab[9];
        char    ctab[3];
        char    ctab2[3];
        int             itab2[9];
 
        itab[0] = 3;
        itab2[0] = 3;
        itab[8] = 3;
        itab2[8] = 3;
        ctab[0] = 3;
        ctab2[0] = 3;
        ctab[2] = 3;
        ctab2[2] = 3;
        if (ft_memset(itab, 49, sizeof(itab)) != memset(itab, 49, sizeof(itab)))
                D_ERROR
        ft_memset(itab, 49, sizeof(itab));
        memset(itab2, 49, sizeof(itab));
        if (memcmp(itab, itab2, sizeof(itab)) != 0)
                D_ERROR
        ft_memset(ctab, 49, sizeof(ctab));
        memset(ctab2, 49, sizeof(ctab));
        if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
                D_ERROR
        return (1);
}
 
int     uf_test_bzero(void)
{
        int             itab[9];
        char    ctab[3];
        char    ctab2[3];
        int             itab2[9];
 
        itab[0] = 3;
        itab2[0] = 3;
        itab[8] = 3;
        itab2[8] = 3;
        ctab[0] = 3;
        ctab2[0] = 3;
        ctab[2] = 3;
        ctab2[2] = 3;
        ft_bzero(itab, sizeof(itab));
        bzero(itab2, sizeof(itab));
        if (memcmp(itab, itab2, sizeof(itab)) != 0)
                D_ERROR
        ft_bzero(ctab, sizeof(ctab));
        bzero(ctab2, sizeof(ctab));
        if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
                D_ERROR
        return (1);
}
 
void    uf_add_test(t_test *test, const char *name, int (*funct)(void))
{
        static int      i = 0;
 
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
 
        printf("\n>--------------------------------------------------------------------<\n\n");
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
                memset(test, 0, D_TEST);
                uf_add_test(test, "memset", uf_test_memset);
                uf_add_test(test, "bzero", uf_test_bzero);
                uf_add_test(test, "memcpy", uf_test_memcpy);
                uf_add_test(test, "memccpy", uf_test_memccpy);
                uf_add_test(test, "memmove", uf_test_memmove);
                uf_add_test(test, "memchr", uf_test_memchr);
                uf_add_test(test, "memcmp", uf_test_memcmp);
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
                uf_add_test(test, "atoi", uf_test_atoi);
                uf_add_test(test, "alpha", uf_test_isalpha);
                uf_add_test(test, "digit", uf_test_isdigit);
                uf_add_test(test, "alnum", uf_test_isalnum);
                uf_add_test(test, "isascii", uf_test_isascii);
                uf_add_test(test, "isprint", uf_test_isprint);
                uf_add_test(test, "toupper", uf_test_toupper);
                uf_add_test(test, "tolower", uf_test_tolower);
                /*
                uf_add_test(test, "memalloc_del", uf_test_memalloc_and_del);
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
                uf_add_test(test, "strjoin", uf_test_strjoin);*/
                while (i < D_TEST && test[i].set == true)
                {
                        printf("Test [\033[34m%s\033[0m]:", test[i].name);
                        if (strlen(test[i].name) < 8) 
                                printf("\t");
                        printf("---");
                        if (test[i].funct() == 0)
                                printf("\033[31mFAIL\033[0m");
                        else
                                printf("\033[32mOK\033[0m");
                        printf("---\n");
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
                memset(test, 0, D_TEST);
                uf_add_test(test, "memset", uf_test_memset);
                uf_add_test(test, "bzero", uf_test_bzero);
                uf_add_test(test, "memcpy", uf_test_memcpy);
                uf_add_test(test, "memccpy", uf_test_memccpy);
                uf_add_test(test, "memmove", uf_test_memmove);
                uf_add_test(test, "memchr", uf_test_memchr);
                uf_add_test(test, "memcmp", uf_test_memcmp);
                uf_add_test(test, "strlen", uf_test_strlen);
                uf_add_test(test, "strdup", uf_test_strdup);
                uf_add_test(test, "strcpy", uf_test_strcpy);
                uf_add_test(test, "strncpy", uf_test_strncpy);
                uf_add_test(test, "strcat", uf_test_strcat);
                uf_add_test(test, "strncat", uf_test_strncat);
                //uf_add_test(test, "strlcat", uf_test_strlcat);
                uf_add_test(test, "strchr", uf_test_strchr);
                uf_add_test(test, "strrchr", uf_test_strrchr);
                uf_add_test(test, "strstr", uf_test_strstr);
                uf_add_test(test, "strnstr", uf_test_strnstr);
                uf_add_test(test, "strcmp", uf_test_strcmp);
                uf_add_test(test, "strncmp", uf_test_strncmp);
                uf_add_test(test, "atoi", uf_test_atoi);
                uf_add_test(test, "alpha", uf_test_isalpha);
                uf_add_test(test, "digit", uf_test_isdigit);
                uf_add_test(test, "alnum", uf_test_isalnum);
                uf_add_test(test, "isascii", uf_test_isascii);
                uf_add_test(test, "isprint", uf_test_isprint);
                uf_add_test(test, "toupper", uf_test_toupper);
                uf_add_test(test, "tolower", uf_test_tolower);
                /*
                uf_add_test(test, "memalloc_del", uf_test_memalloc_and_del);
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
                uf_add_test(test, "strjoin", uf_test_strjoin);*/
/*
                while (i < D_TEST && test[i].name != str)
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
                }  */
        }

        main();
        return (0);
}
