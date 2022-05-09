#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int i);
int		ft_isprint(int c);
void	*ft_memchr(const void *buf, int c, size_t count);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memcpy(void *dest, const void *source, size_t num);
void	*ft_memset(void *p, int value, size_t num);
char	*ft_strchr(char const *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int length);
char	*ft_strrchr(const char *s, int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
#endif
