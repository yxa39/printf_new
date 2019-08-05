
#include "libft.h"

int		get_long_strlen(long long int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char	*ft_llitoa(long long int n)
{
	char			*str;
	int				len;
	long long int	new_n;

	len = get_long_strlen(n);
	new_n = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		new_n = -n;
		str[0] = '-';
	}
	str[--len] = new_n % 10 + '0';
	while (new_n /= 10)
		str[--len] = new_n % 10 + '0';
	return (str);
}
