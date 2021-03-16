# Stack-Permutation
Used data structures to print all permutaions of a stack in C



/* This is a readMe file solely for the purpose of explaining the procedure of execution of the code */

The user is requested to input an integer k as represented in the question but the number of outputs will be large for a value of 
k more than 15 because the number of stack permutations will become extremely huge.

So input the value of k less than 15.

Followed by your input will be an input of k integers followed by spacebars which will determine your input queue.

The output will produce a sequence of stack permutations depending on input.
Now the stack permutations are produced on the basis of: 
A recursive algorithm is used where we use the input queue

Now if stack is empty we only push from input queue
Now if stack has some elements and input queue is not empty then we have 2 options 
1- Either pop from stack into output queue
2- Push from input queue to stack
Using each possible combination we print an output queue permutation 
This continues recursively until all elements of input queue is empty and all 
elements of stack are popped out

If the input queue is empty then we have no other option but to pop all the elements out of the stack which will 
thus complete each of our permutation in all permutation

/* Now as I have clearly the mechanism of obtaining all the stack permutation 

There is a very interesting property which tells about the number of permutations that is the property of catalan number.*/

Based on the number of inputs the numer of outputs is the catalan number 

Here if k is input there are k inputs;

So no of outputs = Catalan number = (C(2*k,k))/(k+1)
where C is the representation for combination in P&C;

A more optimised algorithm for this is [(2^k)(3*5*7......(2*k-1)]/(k+1)!
where (k+1)! is the factorial of (k+1) i.e. the product of all numbers from 1 to k

(k+1)! = 1*2*3*4.......(k-1)*k*(k+1)

This direct formula will give the number of outputs of stack permutation.

This optimised approach is aldready implemented in our program which checks the usage of this function and can be verified.


