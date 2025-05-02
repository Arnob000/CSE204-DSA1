-----------------Stack------------------
-------StackADT-------
->Data class based on Stack Abstruct data type.
->Support for various types of element.
Here StackADT has 6 function-
1.clear()- Clear contents from the stack and reinitialize it to 
make it empty.
2.push(item)- Inserts an element at fixed position.
3.pop()- Remove and return the fixed position's element.
4.length()- Return the number of elements in the stack. 
5.topValue()- Return the current element of the stack.
6.setDirection(direction)- Called on an empty stack
(only on array based) to set the direction of growth.  
-------Arr-------
Array based implementation of StackADT.
Its size grows(2*size) when allocated memory is exceeded. 
No other usable method except StackADT's method.
Support for creating empty Stack.
Support for creating 1 array 2 stack.
-------LL--------
Linked List based implementation of StackADT.
Its size grows dynamically. 
No other usable method except StackADT's method.
Support for creating empty Stack.
------Node-------
Node class required for nodes in Linkedstack. 
-----StackMain-----
Main function implementation using Arr.cpp or LL.cpp by common 
code. Shows different functionality.
----------------------------------------------------------
----------------Dishwasher--------------------
Dishwasher implementation using-
(1) Arr.cpp  
(2) LL.cpp 
(3) 1 Array 2 Stack. 
Implements task2 by common code.
-----1 Array 2 Stack------
For 1 Array 2 Stack Arr.cpp is used. Here, at first one stack 
object is created on an array(General constructor). Then this 
object(by its location) is used to create another stack object
(Another constructor) on the same array in reverse direction.