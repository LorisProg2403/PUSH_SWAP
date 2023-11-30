# Push Swap
## Correct Input
check si les input donner son correct et renvoie vers exit_error sinon
## Fill Stack Values
Rempli la stack A avec les values donner en argument
## Assign index
Donne l'index final de chaque nombre. Le plus grand sera stack_len et le plus petit sera 1.
- Chercher la plus grande value, lui assigne la stack_size, chercher le 2eme plus grand et lui assigne la size - 1, etc...
## Push Swap
- Size = 2 ==> sa()
- Size = 3 ==> tiny_sort()
- Size = 4 ==> sort()
### Tiny sort
Sort easily a stack of 3
### Sort
Push every nodes of A to B until there is only 3 left in A

Then tiny_sort() A.

Then while until B is empty :
- get_target_postion()
- get_cost
- do_cheapest_move

After this if A isnt sorted, use shift_stack() to rotate the stack until the lowest value is at the top. Check if the lowest value is in the top half of the stack or in the botttom half to choose between rra() and ra().

### Get_Target_Position
Assigns a target position in stack A to each element of stack B.
The target position is the spot the element in B needs to
get to in order to be sorted correctly. This position will
be used to calculate the cost of moving each element to 
its target position in stack A.

### Get_Cost
Calculates the cost of moving each element of stack B into the correct
position in stack A.
Two costs are calculated :
- cost_b represents the cost of getting the element to the top of the B stack
- cost_a represents the cost of getting to the right position in stack A.
If the element is in the bottom half of the stack, the cost will be negative,if it is in the top half, the cost is positive. 

### Do_cheapest_move
Finds the element in stack B with the cheapest cost to move to stack A
and moves it to the correct position in stack A.
##### Do Move
Chooses which move to make to get the B stack element to the correct position in stack A.
If the costs of moving stack A and B into position match (i.e. both negative
of both positive), both will be	rotated or reverse rotated at the same time.
They might also be rotated separately, before finally pushing the top B element
to the top stack A.

## Frees
if split has been used ==> free av;

free stack A and stack B