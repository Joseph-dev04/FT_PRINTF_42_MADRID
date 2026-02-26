/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:23:25 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 16:38:24 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	hash;
	int	point;
	int	minus;
	int	plus;
	int	num;
	int	num_dot;
	int	zero;
	int iter;
	int space;
}	t_flags;

typedef struct s_d
{
	long	nb;
	char	sign;
	int		num_len;
	int		zeros;
	int		padding;
}	t_d;

typedef struct s_u
{
	unsigned int	nb;
	int				num_len;
	int				zeros;
	int				padding;
}	t_u;

int		ft_printf(char	const *str, ...);
int		ft_detec_plus(char const *str, int *i, va_list list, t_flags *flags);
void	ft_detec_args(char const **str, int *i, va_list list, t_flags *flags);
void	ft_detec_flags(char const *str, t_flags *flags);

int		ft_printstring(va_list list, int *i, t_flags *flags);
int		ft_printchar(va_list list, int *i, t_flags *flags);
int		ft_printpointer(va_list list, int *i, t_flags *flags);
int		ft_printinteger(va_list list, int *len, t_flags *flags);
int		ft_printunsigned(va_list list, int *len, t_flags *flags);
int ft_printhexa(va_list ap,char uppercase, int *len , t_flags *f);
char	*ft_utoa_base(unsigned int n, char *base);
void	ft_zero(int num, char c, int *i);
void	ft_hexa(char *str, unsigned int i, int *len);
int		ft_lenhexa(int num);
void	ft_long(char *str, unsigned long long i, int *len);

void	ft_flags_caracters(t_flags *flags, char *src, int *i);
void	ft_flags_trings(t_flags *flags, char c, int *i);
void	ft_flags_int(t_flags *flags, char *str, int *i, int len);
void	ft_flags_unint(t_flags *flags, char *str, int *i, int len);
void	ft_flags_hexa(t_flags *flags, unsigned int i, char *str, int *len);

char	*ft_utoa(unsigned int n);
void	ft_check_num(char **str, int len);


void	ft_init_struct(t_flags *flags);
void print_padding(int n, char c, int *len);
#endif