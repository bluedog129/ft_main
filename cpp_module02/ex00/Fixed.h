/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:37:03 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/07 11:31:38 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:
	int					value;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif