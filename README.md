# Binary-Tree
In this program, we want to experimentally validate the method by developing a program in C++ environment. The 
random binary tree for a given number of the nodes is generated as mentioned in the following, and then the amortized complexity is calculated. 

### Description

Letβs assume each node as a root of a sub-tree that has left (LS) and right (RS) sub-trees. As a result, 
```
πΎππ¦ π£πππ’π ππ πππβ ππππ = ππ’ππππ ππ π‘βπ πππππ  ππ πΏπ + ππ’ππππ ππ π‘βπ πππππ  ππ ππ + 1 
```
I generate random binary tree recursively. The total number of the nodes is given as a key value in root. The 
number of the nodes in left sub-tree can be calculated randomly and the remaining amount of the nodes is 
assigned to the right sub-tree. 

 
<p align = "center">
  <img src = "https://github.com/mandanaGh/Binary-Tree/blob/main/images/BinaryTree.jpg" />
  </p>
  
