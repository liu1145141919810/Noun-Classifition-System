# Noun-Classifition-System
Using the c++ code to implement the noun classifition system
## Aim for the code
To implement the noun classsification system which would construct the classification tree and asking the customer questions `for example, if a belongs to b` accroding to the calculation.
## Using syntax
### 1) First you should construct the instance of the class `System` and give it two int values standing for the all nodes in the classification tree and  the amount of question which would be given respectively.
### 2) Then is a line where you would give each node a so-called `weight` value and accroding to the following algorithm the superiority of questioning would be calculated
#### The algorithm of weight
Every time the total classification tree would be narrowed to a smaller range, for all the nodes in the range, calculating two value `value1 and value2` respectively. Value1 adds up all the weight for a node and the subnodes belong to it, while value2 add up all the weight for the nodes which is not belong to it in the limited range. Then we could get the value which is the abstract value for `value1 - value2`. The smaller it is the higher superiority it would have.
### 3) This is a line demonstrating the structure for the classification tree. It starts with the parameter for the second node and ends with the last node's. Each parameter shows that which node would be its `father node`.
### 4) Then comes the lines whose amount equal to the asking times, each line has only one number which shows the node would be asked.
## The output form
1) Each line shows the node that the system would throw out to ask the tester, untill the final limited range for the requiered node is fixed
## Examples and Explanation
!
