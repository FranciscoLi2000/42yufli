#include "libft.h"

void	handle_spec(t_spec *spec)
{
	spec->flag_hash = 0;
	spec->flag_zero = 0;
	spec->flag_minus = 0;
	spec->flag_space = 0;
	spec->flag_plus = 0;
	spec->width = -1;
	spec->precision = -1;
	spec->length_mod[0] = '\0';
	spec->type = '\0';
}
/*
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
}*/
void	parse_flags(t_fmt *data, t_spec *spec)
{
	while (*data->format)
	{
		if (ft_strchr(*data->format, '#'))
			spec->flag_hash = 1;
		else if (ft_strchr(*data->format, '0'))
			spec->flag_zero = 1;
		else if (ft_strchr(*data->format, '-'))
			spec->flag_minus = 1;
		else if (ft_strchr(*data->format, ' '))
			spec->flag_space = 1;
		else if (ft_strchr(*data->format, '+'))
			spec->flag_plus = 1;
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

	/* 初始化 data 结构，比如设置返回值初始为 0，初始化 va_list 等 */
	data.ret = 0;
	data.format = format;
	va_start(data.ap, format);

	while (*data.format)
	{
		if (*data.format == '%')
		{
			data.format++;
			parse_specifier(&data);/* 解析 % 后面的内容，存储在结构体中 */
		}
		else
		{
			ft_putchar(&data, *data.format);/* 输出普通字符 */
			data.format++;
		}
	}
	va_end(data.ap);
	return (data.ret);
}
