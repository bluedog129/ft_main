# push_swap

## Main fuctions flow
- [x] main

- [x] validate_args
	- [x] validate_not_digit
	- [x] validate_not_duplicate
	- [x] validate_range (INT_MIN ~ INT_MAX)
- [x] push_swap (main_function)
	- [x] set_dequeue 
		- [x] create_deque
		- [x] put_num_to_deque (this is while roof)
			- [x] ft_atoi
			- [x] push_back
	- [ ] divide_arrays_to_n_chunks (where n is a constant that depends on the size of the input array)
	- [ ] sort_each_chunks (Push each chunk onto the stack in order, starting with the smallest chunk)
	- [ ] merge the chunks (At each step, pop the top element from one of the stacks, compare it to the top element of the other stack, and push the smaller element onto the other stack and Repeat this process until one of the stacks is empty)

## Tools to make
- [x] make_stack (exactly dequeue, and it will create two in this project)
	- [x] create_deque, is_full, is_empty, push_front, push_back, pop_front, pop_back, print_deque

- [x] make_command (using stack)
	- [x] pa, pb, ss, sb, rr, ra, rrr, rra, rrb

- [ ] utils
	- [x] print_error

- [ ] checker (bonus)
	- [ ] 