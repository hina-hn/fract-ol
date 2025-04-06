/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:09:27 by YourName          #+#    #+#             */
/*   Updated: 2025/04/06 14:17:43 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	is_valid_number(const char *s)
{
	int	dot_count;

	dot_count = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (++dot_count > 1)
			{
				fprintf(stderr, "Error: too many decimal points\n");
				return (0);
			}
		}
		else if (*s < '0' || *s > '9')
		{
			fprintf(stderr, "Error: invalid character in number\n");
			return (0);
		}
		s++;
	}
	return (1);
}

double	get_fractional_part(const char *s)
{
	double	fractional_part;
	double	pow;

	fractional_part = 0;
	pow = 1;
	while (*s)
	{
		pow /= 10;
		fractional_part += (*s++ - '0') * pow;
	}
	return (fractional_part);
}

double	atodbl(char *s)
{
	long	intefer_part;
	double	fractional_part;
	int		sign;

	intefer_part = 0;
	fractional_part = 0;
	sign = +1;
	if (!is_valid_number(s))
		exit(1);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		intefer_part = (intefer_part * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	fractional_part = get_fractional_part(s);
	return ((intefer_part + fractional_part) * sign);
}
