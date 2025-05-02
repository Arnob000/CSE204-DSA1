-----------------Queue------------------
-------QueueADT-------
->Data class based on Queue Abstruct data type.
->Support for various types of element.
Here QueueADT has 7 function-
1.clear()- Clear contents from the queue and reinitialize it to 
make it empty.
2.enqueue(item)- Inserts an element at last position.
3.dequeue()- Remove and return the first position's element.
4.length()- Return the number of elements in the queue. 
5.frontValue()- Return the front element of the queue.
6.rearValue()- Return the rear element. 
7.leaveQueue()- Return the rear element which has left the queue.  
-------Arr-------
Array based implementation of QueueADT.
Its size grows(2*size) when allocated memory is exceeded. 
Support for enqueue and dequeue operation as O(1).
No other usable method except QueueADT's method.
Support for creating empty Queue.
-------LL--------
Linked List based implementation of QueueADT.
Its size grows dynamically. 
No other usable method except QueueADT's method.
Support for creating empty Queue.
------Node-------
Node class required for nodes in Linked Queue. 
-----QueueMain-----
Main function implementation using Arr.cpp or LL.cpp by common 
code. Shows different functionality.
----------------------------------------------------------
----------------Booth--------------------
BankBooth implementation using-
(1) Arr.cpp  
(2) LL.cpp 
Implements task2 by common code.