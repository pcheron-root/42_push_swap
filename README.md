# push_swap

Given a set of integers, sort it using a predefined set of instructions using two stacks. The instruction set is defined below. This program outputs a program in push_swap instructions that sorts the input integers.

## Algorithm
### Step 1 - push elements

Send all elements to stack B except 3 elements.
we keep 3 elements (we can order 3 elements very easily).
![Screenshot from 2023-06-04 14-16-34](https://github.com/pcheron-root/push_swap/assets/126467996/08ef34e1-9755-4a4d-9f52-c285e6542df3)

### Step 2 - order stack A

In the 3 remaining elements, we can have only 6 cases.

![Screenshot from 2023-06-04 14-18-36](https://github.com/pcheron-root/push_swap/assets/126467996/0a87c51f-4033-42d3-a562-55ee31fd8463)

In half of all cases, the stack is ordered as follows.

![Screenshot from 2023-06-04 14-18-45](https://github.com/pcheron-root/push_swap/assets/126467996/90e6725a-8a99-476b-8c1c-b9b2ffd44bca)

for the others we only have to use "swap a" move to order the stack :

![Screenshot from 2023-06-04 14-18-54](https://github.com/pcheron-root/push_swap/assets/126467996/f71806a9-3c49-4a91-919e-3109394e5e5f)

### Step 3 - return elements to stack A

we try to put the elements of the stack B in the stack A in such a way that the stack A remains ordered.

to keep the A stack ordered, we need to find the "big brother" element of the number we want to send.
This element is the smallest of the numbers above the "little brother" element.

![Screenshot from 2023-06-04 14-19-58](https://github.com/pcheron-root/push_swap/assets/126467996/718dd997-3803-47a1-a6ab-aed886d4cefe)

To be efficient, for each element of the stack B we will calculate in how many moves we can place this element in the stack A.

there are 4 possibilities to place an element from b to a :

- Using rotates (rr, ra and rb moves to put 1 and 2 at the top of each list)

![Screenshot from 2023-06-04 14-21-14](https://github.com/pcheron-root/push_swap/assets/126467996/c6e82ab0-ca4c-49d5-a322-49e50fb7e055)

- Using reverse rotates (rrr, rra and rrb moves to put 1 and 2 at the top of each list from the bottom)!

![Screenshot from 2023-06-04 14-21-37](https://github.com/pcheron-root/push_swap/assets/126467996/ccbe0264-0ff1-4963-a58d-d68660ecf4ab)

- Using rotate a and reverse rotate b

![Screenshot from 2023-06-04 14-21-29](https://github.com/pcheron-root/push_swap/assets/126467996/a62df96d-c0da-4ef2-b2f0-7a2e62fec7e7)

- Using rotate b and reverse rotate a!

![Screenshot from 2023-06-04 14-21-22](https://github.com/pcheron-root/push_swap/assets/126467996/6dcba55e-5181-427a-9ca6-ea2d8f588338)

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

### step 4 - make order

all elements have been returned to stack A, stack B is empty.
Use rotate and reverse rotate to put the smallest element on top of the stack

![Screenshot from 2023-06-04 14-22-17](https://github.com/pcheron-root/push_swap/assets/126467996/33ca7b89-4c37-4c21-be60-232a650fc9b1)
