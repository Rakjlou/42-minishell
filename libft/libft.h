/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:48:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/10 15:00:50 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_uvector
{
	unsigned int	x;
	unsigned int	y;
}	t_uvector;

/* C type */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isblank(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/* Conversion */
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
char			*ft_itoa(int n);
char			*ft_utoa_base(unsigned long num, char *base, unsigned int bs);
char			*ft_ltoa_base(long num, char *base, unsigned int base_size);

/* I/O */
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_tmpfile(char **filepath);

/* Basic list */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));

/* Strings */
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_bool			ft_ends_with(char *haystack, char *needle);
t_bool			ft_cvalid(char ref, char *authorized);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_fill_str(char *str, char to_fill, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *str, const char *sep);

/* String arrays */
void			ft_cmatrix_print(char **matrix);
void			ft_cmatrix_free(char **matrix);
size_t			ft_cmatrix_size(char **matrix);
char			**ft_cmatrix_join(char **matrix1, char **matrix2);

/* Raw memory */
void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);

/* Math */
int				ft_max(int a, int b);
int				ft_min(int a, int b);
unsigned int	ft_umin(unsigned int a, unsigned int b);
unsigned int	ft_umax(unsigned int a, unsigned int b);
unsigned int	ft_uimin(unsigned int a, unsigned int b);
unsigned int	ft_uimax(unsigned int a, unsigned int b);

#endif
