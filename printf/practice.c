#include <stdio.h>
int main()
{
	printf("fff%+.1d\n", -123);
	printf("fff%+.5d\n", -123);
	printf("fff%+.10d\n", -123);
	printf("fff%+10d\n", -123);





}

// char	*ft_apply_flag_space(char *str)
// {
// 	int		converted_int;
// 	char	*positive_result;
// 	int		str_len;
	
// 	str_len = ft_strlen(str);
// 	converted_int = ft_itoa(str);
// 	if (converted_int > 0)
// 	{
// 		*positive_result = ' ';
// 		*(positive_result + 1) = '\0';
// 		ft_strlcat(positive_result, str, str_len + 2);
// 		return (positive_result);
// 	}
// 	return (str);
// }
