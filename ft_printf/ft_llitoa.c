
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


int		get_un_long_strlen(unsigned long long int n, int base)
{
	int	len;

	len = 1;
	while (n /= base)
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
	bzero(str, len + 1);
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

char	*ft_un_llitoa(unsigned long long int n, int base, char format)
{
	char			*str;
	int				len;
	unsigned long long int	new_n;

	len = get_un_long_strlen(n, base);
	new_n = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	bzero(str, len + 1);
	if (format == 'X')
		str[--len] = NUMERALS_CAP[new_n % base];
	else
		str[--len] = NUMERALS[new_n % base];
	if (format == 'X')
		while (new_n /= base)
			str[--len] = NUMERALS_CAP[new_n % base];
	else
		while (new_n /= base)
			str[--len] = NUMERALS[new_n % base];
	return (str);
}
