# Binary-Tree
In this program, we want to experimentally validate the method by developing a program in C++ environment. The 
random binary tree for a given number of the nodes is generated as mentioned in the following, and then the amortized complexity is calculated. 

# Description

Let’s assume each node as a root of a sub-tree that has left (LS) and right (RS) sub-trees. As a result, 
```
𝐾𝑒𝑦 𝑣𝑎𝑙𝑢𝑒 𝑜𝑓 𝑒𝑎𝑐ℎ 𝑛𝑜𝑑𝑒 = 𝑁𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑛𝑜𝑑𝑒𝑠 𝑖𝑛 𝐿𝑆 + 𝑁𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑡ℎ𝑒 𝑛𝑜𝑑𝑒𝑠 𝑖𝑛 𝑅𝑆 + 1 
```
I generate random binary tree recursively. The total number of the nodes is given as a key value in root. The 
number of the nodes in left sub-tree can be calculated randomly and the remaining amount of the nodes is 
assigned to the right sub-tree. 

 
<p align = "center">
  <img src = "https://github.com/mandanaGh/Binary-Tree/blob/main/images/BinaryTree.jpg" />
  </p>
  
