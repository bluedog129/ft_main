/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:39:18 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 21:34:37 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_apply_flag_minus(options* string_info) // 좌측 정렬
{
	char	*string;
	char	*new_string;
	int		index;
	int		strlen;

	if (string_info->flag_minus == 0)
		return ;
	index = 0;
	string = string_info->value;
	strlen = ft_strlen(strlen);
	ft_new_string(string, strlen);
	while (*(string + index) == ' ') //공백은 건너뛰고 출력 가능한 문자가 나올 때부터 복사
		index++;
	ft_memset(new_string, ' ', strlen);
	ft_strlcpy(new_string, (const char)(string + index), strlen - index);
	new_string[strlen - index] = ' ';  //널자리를 공백으로 바꿔줌
	new_string[strlen - 1] = '\0'; // 새로운 문자열의 마지막 자리에 널을 넣어 줌
	string_info->value = new_string;
	free(new_string);
}

void ft_apply_flag_plus(options* string_info) // 양수일 때 +, 음수일 때 -
{
	char	*string;
	char	*new_string;
	int		index;
	int		strlen;
	char	*tmp;

	if (string_info->flag_plus == 0)
		return ;
	index = 0;
	string = string_info->value;
	while (*(string + index) == ' ') //공백은 건너뛰고
		index++;
	if ((char)(*(string + index)) == '-')  // 처음 나오는 문자가 - 인지 확인
		return ;
	strlen = ft_strlen(string);
	tmp = ft_substr((const char)string, 0, index - 1);  //공백만큼 string
	new_string = ft_strjoin(tmp, "+"); // 공백 + "+"
	tmp = ft_substr((const char)string, index, strlen - index);
	new_string = ft_strjoin(new_string, tmp); // "공백" + "+" + "문자"
	string_info->value = new_string;
	free(new_string);
	free(tmp);
}

void ft_apply_flag_space(options* string_info) // 양수일 때 공백 음수일 때 -
{
	char	*string;
	char	*new_string;
	int		index;
	int		strlen;
	char	*tmp;

	if (string_info->flag_space == 0)
		return ;
	index = 0;
	string = string_info->value;
	while (*(string + index) == ' ') //공백은 건너뛰고
		index++;
	if ((char)(*(string + index)) == '-')  // 처음 나오는 문자가 - 인지 확인
		return ;
	strlen = ft_strlen(string);
	tmp = ft_substr((const char)string, 0, index - 1);
	new_string = ft_strjoin(tmp, " "); // 공백 + " "
	tmp = ft_substr((const char)string, index, strlen - index);
	new_string = ft_strjoin(new_string, tmp); // "공백" + " " + "문자"
	string_info->value = new_string;
	free(new_string);
	free(tmp);
}

void ft_apply_flag_zero(options* string_info)  // 앞 뒤 빈자리에 0 추가
{
	char	*string;
	int		index;
	int		strlen;

	if (string_info->flag_zero == 0)
		return ;
	index = 0;
	strlen = ft_strlen(string);
	string = string_info->value;
	while (*(string + index) == ' ')
	{
		*(string + index) = '0';
		index++;
	}
	while (*(string + strlen - 1) == ' ')
	{
		*(string + strlen - 1) = '0';
		strlen--;
	}
}

void ft_apply_flag_hash(options* string_info)
{
}