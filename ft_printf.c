#include "libft.h"

void	parse_format(t_fmt *data)
{
	while (*data->format)
	{
		if (*data->format == '%')
		{
			data->format++;
			handle_conversion(data);
		}
		else
			ft_putchar(data, *data->format);
		data->format++;
	}
}

void	handle_conversion(t_fmt *data)
{
	if (*data->format == 'c')
		ft_putchar(data, va_arg(data->ap, int));
	else if (*data->format == 's')
		ft_putstr(data, va_arg(data->ap, char *));
	else if (*data->format == 'p')
		ft_putptr(data, va_arg(data->ap, unsigned long long));
	else if (*data->format == 'd' || *data->format == 'i')
		ft_putnbr(data, va_arg(data->ap, int));
	else if (*data->format == 'u')
		ft_putunbr(data, va_arg(data->ap, unsigned int));
	else if (*data->format == 'x' || *data->format == 'X')
		ft_puthex(data, va_arg(data->ap, unsigned int), *data->format);
	else if (*data->format == '%')
		ft_putchar(data, '%');
}

int	ft_printf(const char *format, ...)
{
	t_fmt	data;

	data.ret = 0;
	data.format = format;
	va_start(data.ap, format);
	parse_format(&data);
	va_end(data.ap);
	return (data.ret);
}
