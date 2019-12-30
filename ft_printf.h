/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:43:29 by cnguyen           #+#    #+#             */
/*   Updated: 2019/11/18 21:32:29 by cnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>




#include "libft/libft.h"
#include <stdarg.h>

# define SYMBOLS "%-+#0123456789 +cspdDiouxXf.lhLjUz%"
# define JUSTIFY "-+0 #"
# define SPECIFIERS "cspdDiouUxXf%"
# define LENGTHS "lhLjz"

typedef	struct	s_format
{
	int			plus;
	int			minus;
	int			hash;
	int			zero;
	int			space;

	int			width;
	int			prec_flag;
	int			precision;
	int 		hash_case;

	char		length;
	char		l_j;
	char		l_z;

	char		pad;

	int			dubs;
	char		specifier;
}				t_format;

int  	g_count;
int		g_value;

void		free_struct(t_format **dp);
int		ft_printf(char *str, ...);
int		parse_flag(char *s, va_list ap, t_format **dp, int pos);

void	create_struct(t_format **dp);
void	reset_struct(t_format **dp);
int		set_tokens(char *s, va_list ap, t_format **dp);
int		set_justify(char *s, t_format **dp);

int		print_padding(int zeroes, int remaining, char pad);
void		print_width(int width, char pad);
void	print_width(int width, char pad);
int		print_spec(char c, va_list ap, t_format **dp);
void	print_chr(va_list ap, t_format **dp);
void	print_int(va_list ap, t_format **dp);
void	print_str(va_list ap, t_format **dp);

void	precision_print(char *str, int prec_flag, int precision);
int		determine_len(char *str, int prec_flag, int precision);
int		determine_len_int(char *str, t_format *format);

int		handle_sign (char **dp, char *str, t_format *format);
void 		write_zeroes(char **dp, int *i, int number);
void		write_from_str(char **dp, int *i, char *str);
int		adjust_for_sign(char **pi_dp, char *str, int *len);
void		check_octal_case(int *number, t_format *format, int i, int len);
char		*malloc_int(char *str, t_format *format);
void		zero_no_prec(char *integer, t_format *format);
void	print_int(va_list ap, t_format **dp);
void	handle_default(va_list ap, t_format **dp);

void		subtract_width_hash(t_format **dp, char *str);
void		handle_hash(t_format **dp, char *str);
char		*convert_to_octal(long long decimal);
void		handle_octal(va_list ap, t_format **dp);
void		solve_int(char *str, t_format *format);
void		reverse_string(char **dp);
void        handle_hex(va_list ap, t_format **dp, int c);
void		handle_float(va_list ap, t_format **dp);

void	ft_putstr_count(char *str);
void	ft_putchar_count(char c);

void		solve_ptr(char *str, t_format *format);
void		handle_pointer(va_list ap, t_format **dp);
char		*convert_to_pointer(long long decimal);

void		no_width_int(t_format *format, char *integer, char *str);
void		width_int(t_format *format, char *integer, int len);


void		construct_integral_ld(long double value, char **dp, int precision);
void		construct_decimal_ld(double value, double integral, \
char **dp, int precision);
void		construct_integral(double value, char **dp, int precision);
void		construct_decimal(double value, double integral, \
char **dp, int precision);
double		exponents(int precision);

char			*ft_itoa_u_long(unsigned long long the_long);
char			*ft_itoa_long(long long the_long);
char		*u_l_flag_dec(va_list ap, t_format **dp);
char		*u_h_flag_dec(va_list ap, t_format **dp);
char		*u_flag_dec(va_list ap, t_format **dp);

int		set_length_jz(char c, t_format **dp);

#endif