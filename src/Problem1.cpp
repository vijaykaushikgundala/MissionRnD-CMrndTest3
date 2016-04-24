/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
void arthematic_sum_of_nodes(struct node *,int *,int );
int get_missing_value(struct node *root,int n)
{
	int sum_of_nodes = 0, total_sum_of_numbers = 0,missing_value;
	struct node *temp;
	temp = root;
	if (n < 0)
	{
		total_sum_of_numbers = ((-n)*(-n + 1)) / 2;
	}
	else
	{
		total_sum_of_numbers = (n*(n + 1)) / 2;
	}
	if (root == NULL||n==0)
	{
		return -1;
	}
	else
	{
     arthematic_sum_of_nodes(temp,&sum_of_nodes,n);
	}
	if (n > 0)
	{
		missing_value = total_sum_of_numbers - sum_of_nodes;
	}
	else
	{
		missing_value = total_sum_of_numbers + sum_of_nodes;
	}
	return missing_value;
}
void arthematic_sum_of_nodes(struct node *temp, int *sum,int n)
{
	if (temp != NULL)
	{
		arthematic_sum_of_nodes(temp->left,sum,n);
		if (n > 0)
		{
			if (temp->data >= 0 && temp->data <= n)
			{
				*sum = *sum + temp->data;
			}
		}
		else
		{
			if (temp->data <= 0 && temp->data >= n)
			{
				*sum = *sum + temp->data;
			}
		}
		arthematic_sum_of_nodes(temp->right, sum, n);
	}
}