<h1>BINARY TREE</h1>

Binary tree means that the node can have maximum two children. Here, binary name itself suggests that 'two'; therefore, each node can have either 0, 1 or 2 children.
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/6421a47e2bc875508be29b59810e97939529e6a3/figures/binary-tree.png">
</p>

The above tree is a binary tree because each node contains the utmost two children. The logical representation of the above tree is given below:

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/6421a47e2bc875508be29b59810e97939529e6a3/figures/binary-tree2.png">
</p>


In the above tree, node 1 contains two pointers, i.e., left and a right pointer pointing to the left and right node respectively. The node 2 contains both the nodes (left and right node); therefore, it has two pointers (left and right). The nodes 3, 5 and 6 are the leaf nodes, so all these nodes contain NULL pointer on both left and right parts.

<h2>Key Words</h2>
Root It is first node of the tree. or Root is the only node which doesn't have parent.

Branch/Edge/Arc Connectivity between the nodes. If we have N number of nodes then we will have N-1 branches.

Internal Nodes A node which has parent as well as child is called Internal nodes

Leaf Node A node without childrens are called leaf nodes.

<h3>Height Of Node</h3>
Number of edges or branches present in the longest path from the given node to leaf node. Height of tree is the height of root node.

<h3>Depth Of Node</h3>
Number of edges present in the path from the node to the root. Maximum depth and height of tree is same
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/ec9458ae077eedf3b9c9f9a75e34931a7e64a223/figures/depth%20of%20a%20tree.gif">
</p>


<h2>Properties of binary tree</h2>
At each level of i, the maximum number of nodes is 2^i
The height of the tree is defined as the longest path from the root node to the leaf node. The tree which is shown above has a height equal to 3. Therefore, the maximum number of nodes at height 3 is equal to (1+2+4+8) = 15. In general, the maximum number of nodes possible at height h is (20 + 21 + 22+….2h) = 2h+1 -1.
The minimum number of nodes possible at height h is equal to h+1.

<h1>Types of Binary Tree</h1>
Full/ proper/ strict Binary tree

Complete Binary tree

Perfect Binary tre

Degenerate Binary tree

Balanced Binary tree

<h2>Strict Binary Tree</h2>
The full binary tree is also known as a strict binary tree. The tree can only be considered as the full binary tree if each node must contain either 0 or 2 children. The full binary tree can also be defined as the tree in which each node must contain 2 children except the leaf nodes.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/strictly%20binary%20tree.png">
</p>

<h2>Complete Binary Tree</h2>
The complete binary tree is a tree in which all the nodes are completely filled except the last level. In the last level, all the nodes must be as left as possible. In a complete binary tree, the nodes should be added from the left.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/complete%20binary%20tree.png">
</p>


The above tree is a complete binary tree because all the nodes are completely filled, and all the nodes in the last level are added at the left first.

<h2>Perfect Binary Tree</h2>
A tree is a perfect binary tree if all the internal nodes have 2 children, and all the leaf nodes are at the same level.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/perfect%20binary%20tree.png">
</p>

<h2>Degenerate Binary Tree</h2>
The degenerate binary tree is a tree in which all the internal nodes have only one children.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/degenerate%20binary%20tree.png">
</p>

<h2>Balanced Binary Tree</h2>
The balanced binary tree is a tree in which both the left and right trees differ by atmost 1. For example, AVL and Red-Black trees are balanced binary tree.
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/balanced%20binary%20tree.png">
</p>


The above tree is a balanced binary tree because the difference between the left subtree and right subtree is zero.
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/e0541fb99413f607e728c36617361120e0109b5c/figures/balanced%20binary%20tree2.png">
</p>

The above tree is not a balanced binary tree because the difference between the left subtree and the right subtree is greater than 1.

<h1>Tree Traversal</h1>
Traversal is a process to visit all the nodes of a tree and may print their values too. Because, all nodes are connected via edges (links) we always start from the root (head) node. That is, we cannot randomly access a node in a tree. There are three ways which we use to traverse a tree

In-order Traversal
Pre-order Traversal
Post-order Traversal
<h2>In-Order Traversal</h2>
In this traversal method, the left subtree is visited first, then the root and later the right sub-tree. We should always remember that every node may represent a subtree itself.

If a binary tree is traversed in-order, the output will produce sorted key values in an ascending order.

<b>Algorithm</b>
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Visit root node.
Step 3 − Recursively traverse right subtree.
<h2>Pret Order Traversal</h2>
In this traversal method, the root node is visited first, then the left subtree and finally the right subtree

<b>Algorithm</b>
Until all nodes are traversed −
Step 1 − Visit root node.
Step 2 − Recursively traverse left subtree.
Step 3 − Recursively traverse right subtree.
<h2>Post-Order Traversal</h2>
In this traversal method, the root node is visited last, hence the name. First we traverse the left subtree, then the right subtree and finally the root node.

<b>Algorithm</b>
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Recursively traverse right subtree.
Step 3 − Visit root node.
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/562c6a05c5ab91e988a63e1acd131a3a68885fa6/figures/in%20order,pre%20order,post%20order.jpg.crdownload">
</p>



