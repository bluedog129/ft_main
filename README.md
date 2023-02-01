# 가장 큰 글씨
## 두번째로 큰 글씨 ~~
##### 이게 가장 작은거였나?

**이건 진한 글씨**
*기울기*

- [히히(요게 보이는 링크)][printf]
```c
void	apply_conversion(t_options *options_check, va_list *args, \
		t_arrayList *arraylist)
{
	if (options_check->conversion == PERCENT)
		apply_percent(options_check, arraylist);
	else if (options_check->conversion == CHARACTER)
		apply_character(options_check, args, arraylist);
	else if (options_check->conversion == STRING)
		apply_string(options_check, args, arraylist);
	else if (options_check->conversion == DECIMAL_D || \
			options_check->conversion == DECIMAL_I)
		apply_d(options_check, args, arraylist);
	else if (options_check->conversion == UNSIGNED_DECIMAL)
		apply_unsigned_decimal(options_check, args, arraylist);
	else if (options_check->conversion == POINTER)
		apply_pointer(options_check, args, arraylist);
	else if (options_check->conversion == UPPER_HEX)
		apply_upper_hex(options_check, args, arraylist);
	else if (options_check->conversion == LOWER_HEX)
		apply_lower_hex(options_check, args, arraylist);
}
```

<img src = "./image/fu.png">

[printf]: https://github.com/bluedog129/42_seoul/tree/master/ft_printf