--------------------BinarySearchTree--------------------
------------------BinNodeADT-------------------
->Abstruct Node class for Binary Tree
->Support for various types of data
Here BinNodeADT has 7 method-
1.element()- Return value in the node
2.setElement(item)- Set value in the node
3.left()- Return left Node
4.setLeft(node)- Set left node
5.right()- Return right node
6.setRight(node)- Set right node
7.isLeaf()- Return a node is leaf or not
--------------------BSTNode--------------------
->Node class for Binary search tree based on BinNodeADT
->Support for various types of data 
--------------------BST------------------------
->Class based on Binary Search Tree property
->Support for various types of data 
->Its size grows dynamically
->Support for creating empty Tree
It has 9 method-
1.clear()- Reinitialize the tree
2.insert(item)- Insert a node with item as value, based 
	        on binary search tree property
3.Delete(item)- Remove a node with matching item
4.Find(item)- If item is in the tree returns true, 
	      else returns false
5.size()- Returns total number of nodes
6.print()- Print the tree
7.preOrder()- Pre Order tree traversal
8.postOrder()- Post Order tree traversal
9.inOrder()- In Order tree traversal
----------------------BSTMain-----------------------
->Shows different operations on Binary search tree
->Takes input from Input.txt file
---------------------Input.txt----------------------
->Contains commands for different operations