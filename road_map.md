# Push_Swap

## Finishing this code
First trying to find why there is **leaks** and that the program doesn't work with **100+** arguments.


## Understand the code

Read the code slowly while being sure that every step and way to do them is **understood**

## Code Road-Map (to finish)
- Header
	- struct t_stack
		- value
		- index
		- pos
		- target_pos
		- cost_a
		- cost_b
		- next
	- include libft and any other libs
	- separating functions
- Number of arguments
	- 1 arg || 2 arg with av[1][0] == NULL  ⇒ no sorting
	- 2 arg ⇒ split
- Input_checks
	- No duplicate
	- INT_MIN <= x => INT_MAX (atolong)
	- only digit and sign
- Error message
	- Display "error" in stderr, why not extra message to see where it fails
	- Adding "%e" in ft_printf to write in the stderr
	- Freeing the stacks (coding free_stack)
- stack A init
	- malloc stack A (coding the stack_new(int value))
	- put every inputs in A
- Operations
	- push
	- swap
	- rotate
	- reverse_rotate
- Push_swap algo
	- size == 2 ⇒ sa()
	- size == 3 ⇒ sort_three()
	- size > 3 ⇒ sort()
- sort_three
	- sorting a basic 3 numbers stack
- sort
	- push_all_but_three_to_B
	- #TODO why and how :
		- index
		- position
		- target
		- cost_a, cost_b
		- move
	- do move
	- do cheapest
- free both stacks

## Utils

-	Split
-	Stack_len
-	Get_last
-	add_bottom
-	get_before_last
-	is_sorted
