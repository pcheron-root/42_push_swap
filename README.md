# push_swap

### Step 1 - push elements

Send all elements to stack B except 3 elements.
we keep 3 elements (we can order 3 elements very easily).

### Step 2 - order stack A

In the 3 remaining elements, we can have only 6 cases.

![Screenshot from 2023-04-26 12-46-01](https://user-images.githubusercontent.com/126467996/234555686-9e25d6de-8d4c-413a-8800-cfbc5dd31cd8.png)

for 3 of them the stack is ordered.
for the others we only have to use "swap a" move to order the stack :

![Screenshot from 2023-04-26 12-47-40](https://user-images.githubusercontent.com/126467996/234555769-3c2ada36-5ecb-4c26-9c2c-8e19f46cc8b0.png)

### Step 3 - most important part

we try to put the elements of the stack b in the stack in such a way that the stack a remains ordered.

![Screenshot from 2023-04-26 12-50-41](https://user-images.githubusercontent.com/126467996/234555864-cff36d72-01a7-43db-896e-20aa83742d95.png)

For each element of the stack B we will calculate in how many moves we can place this element in the stack A.
first we have to find out in front of which element of the stack our element of the stack B is placed.
for example the 4 must be placed in front of the 7

there are 4 possibilities to place an element from b to a :

- Using rotates (rr, ra and rb moves for put 4 and 7 at the top of each list)
- Using reverse rotates (rrr, rra and rrb moves for put 4 and 7 at the top of each list from the bottom)
- Using rotate a and reverse rotate b
- Using rotate b and reverse rotate a

We will calculate the number of moves for each possibility and retain the least expensive.
To calculate each possibility we can use indexes.

![Screenshot from 2023-04-26 12-52-02](https://user-images.githubusercontent.com/126467996/234555994-db4b773f-de2a-4a23-b44d-fa2a9b1e806b.png)

**Rotate A and B**
The larger index of the two numbers

**Reverse rotate A and B**
the biggest difference between size of stack and index of number

**Rotate A and reverse rotate B**
index of a + (size of stack b - current index of b)

**Reverse rotate A and rotate B**
index of b + (size of stack a - current index of a)

### Last step - make order

Use rotate and reverse rotate for put the smallest element on top of the stack
