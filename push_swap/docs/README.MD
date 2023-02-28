# push_swap

## Main fuctions flow
- [x] main
	- [x] args_parsing
		- [x] validate_args
			- [x] validate_not_digit
			- [x] validate_not_duplicate
			- [x] validate_range (INT_MIN ~ INT_MAX)

- [ ] push_swap (main_function)
	- [ ] put_args_to_stack 
			- [ ] inputed_no_args
			- [ ] pick_last_char_from_args
			- [ ] put_num_to_stack
				- [ ] ft_atoi
				- [ ] put_to_stack
	- [ ] divide_arrays_to_n_chunks (where n is a constant that depends on the size of the input array)
	- [ ] sort_each_chunks (Push each chunk onto the stack in order, starting with the smallest chunk)
	- [ ] merge the chunks (At each step, pop the top element from one of the stacks, compare it to the top element of the other stack, and push the smaller element onto the other stack and Repeat this process until one of the stacks is empty)

## Tools to make
- [ ] make_stack (exactly daeque, and it will create two in this project)
	- [ ] create, delete, enque_front, enque_rear, deque_front, deque_rear

- [ ] make_command (using stack)
	- [ ] pa, pb, ss, sb, rr, ra, rrr, rra, rrb

- [ ] checker (bonus)
	- [ ] 