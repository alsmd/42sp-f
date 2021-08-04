#include "../test.h"
#include "../../libft.h"

int	main(void)
{
	printf("%sMandatory:\n", CYN);
	ft_isalpha_tester();
	ft_isdigit_tester();
	ft_isalnum_tester();
	ft_isascii_tester();
	ft_isprint_tester();
	ft_toupper_tester();
	ft_tolower_tester();
	ft_memset_tester();
	ft_bzero_tester();
	ft_memcpy_tester();
	ft_memmove_tester();
	ft_memchr_tester();
	ft_memcmp_tester();
	ft_calloc_tester();
	ft_strlen_tester();
	ft_strlcpy_tester();
	ft_strlcat_tester();
	ft_strchr_tester();
	ft_strrchr_tester();
	ft_strncmp_tester();
	ft_strnstr_tester();
	ft_atoi_tester();
	ft_strdup_tester();
	ft_substr_tester();
	ft_strjoin_tester();
	ft_strtrim_tester();
	ft_split_tester();
	ft_itoa_tester();
	ft_strmapi_tester();
	ft_striteri_tester();
	ft_putchar_fd_tester();
	ft_putstr_fd_tester();
	ft_putendl_fd_tester();
	ft_putnbr_fd_tester();
	ft_lstnew_tester();
	ft_lstadd_front_tester();
	ft_lstsize_tester();
	ft_lstlast_tester();
	ft_lstadd_back_tester();
	ft_lstdelone_tester();
	ft_lstclear_tester();
	ft_lstiter_tester();
	ft_lstmap_tester();
	return (0);
}
