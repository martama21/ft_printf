#include <stdlib.h>//para malloc y free
#include "libft/libft.h"
#include "ft_printf.h"

static int	number_length(long int n)
{
	int			len;
	long int	n_aux;

	len = 0;
	n_aux = n;
	/// se podria borrar
	// if (n_aux < 0)
	// 	n_aux = -n_aux;
	/// hasta aqui
	if (n_aux == 0)
		return (1);
	while (n_aux != 0)
	{
		n_aux = n_aux / 10;
		len++;
	}
	return (len);
}

static void	fill_array(char *str_num, int i, long int n)
{
	if (n == 0)
		return ;
	str_num[i] = (n % 10) + '0';
	fill_array(str_num, i - 1, n / 10);
}

char	*ft_uitoa(long int n)
{
	int			len;
	long int	n_aux;
	char		*str_num;
	int			i;

	n_aux = n;
	i = 0;
	len = number_length(n_aux);
	///se podria borrar
	// if (n_aux < 0)
	// 	len++;
	/// hasta aqui
	str_num = malloc ((len + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	/// se podria borrar
	// if (n_aux < 0)
	// {
	// 	str_num[i] = '-';
	// 	i++;
	// 	n_aux = -n_aux;
	// }
	/// hasta aqui
	if (n_aux == 0)
		str_num[i] = '0';
	if (i < len && n_aux != 0)
		fill_array(str_num, len - 1, n_aux);
	str_num[len] = '\0';
	return (str_num);
}