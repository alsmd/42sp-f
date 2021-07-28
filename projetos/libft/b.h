#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

/*-------TYPES-------*/

//	@param (c)		char that will be tested.
//	@description	checks if $c is an alphabedic character on ascii table.
//	@return			return 1 if $c is alpha or 0 otherwise.

int		ft_isalpha(int c);

//	@param (c)		char that will be tested.
//	@description	checks if $c is a digit character on ascci table.
//	@return			return 1 if $c is a digit or 0 otherwise.

int		ft_isdigit(int c);

//	@param (c)		char that will be tested.
//	@description	checks if $c is a alphanumeric character on ascci table.
//	@return			return 1 if $c is an alphanumeric or 0 otherwise.

int		ft_isalnum(int c);

//	@param (c)		char that will be tested.
//	@description	checks if $c is a character on ascci table.
//	@return			return 1 if $c is into ascii or 0 otherwise.

int		ft_isascii(int c);

//	@param (c)		char that will be tested.
//	@description	checks for any printable character including space.
//	@return			return 1 if $c is printable or 0 otherwise.

int		ft_isprint(int c);

//	@param (c)		char that will be converted.
//	@description	convert lowercase letters to uppercase.
//	@return			the value returned is the converted letter, or c if the conversion failed.

int		ft_toupper(int c);

//	@param (c)		char that will be converted.
//	@description	convert uppercase letters to lowercase.
//	@return			the value returned is the converted letter, or c if the conversion failed.

int		ft_tolower(int c);

/*-------BYTES-------*/

//	@param (s)		pointer to the memory area.
//	@param (c)		byte that will be alocated.
//	@param (n)		quantity of bytes that will be filled.
//	@description	fills the first n bytes fo the memory area pointed to by $s with the byte c.
//	@return			returns a pointer to the memory area s.

void	*ft_memset(void *s, int c, size_t n);

//	@param (s)		pointer to the memory area.
//	@param (n)		quantity of bytes that will be erased.
//	@description	erases the data in the n bytes of the memory stating at the location pointed to by s, by writing zeroes.
//	@return			returns a pointer to the memory area s.

void	ft_bzero(void *s, size_t n);

//	@param (dest)	where the bytes will be saved.
//	@param (src)	where the bytes come from.
//	@param (n)		quantity of bytes that will be copied.
//	@description	copies the data in the n bytes of the memory from src to memory area dest, the memory areas must not overlap.
//	@return			returns a pointer to the memory area dest.

void	*ft_memcpy(void *dest, const void *src, size_t n);

//	@param (dest)	where the bytes will be saved.
//	@param (src)	where the bytes come from.
//	@param (n)		quantity of bytes that will be copied.
//	@description	copies the data in the n bytes of the memory from src to memory area dest, the memory areas may overlap.
//	@return			returns a pointer to the memory area dest.

void	*ft_memmove(void *dest, const void *src, size_t n);

//	@param (s)		memory area where we will be searching.
//	@param (c)		byte that we are looking for.
//	@param (n)		quantity of bytes that will be scanned.
//	@description	scans the initial n bytes of the memory area pointed to by s for the first instance of c.
//					Both c and the bytes of the area s are interpreted as unsigned char.
//	@return			returns a pointer to the match byte or null if the char was not found.

void	*ft_memchr(void *s, int c, size_t n);

//	@param (s1)		first memory area that will be compared.
//	@param (s2)		second memory area that will be compared.
//	@param (n)		quantity of bytes that will be compared.
//	@description	compares the initial n bytes of the memory areas s1 and s2.
//					Both interpreted as unsigned char.
//	@return			returns a value less than, equal to, or greater than zero depending on the difference of s1 and s2.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//	@param (nmemb)	number of elements;
//	@param (size)	size of each element;
//	@description	allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
//					The memory is set to zero. If nmemb or size is 0, then calloc() return either null, or a unique pointer,
//					value that can be later be passed to free().
//					Both interpreted as unsigned char.
//	@return			returns a pointer to the allocated memory, on error return null, null may also be returned if size or nmemb is zero.

void	*ft_calloc(size_t nmemb, size_t size);

/*-------STRINGS-------*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

#endif