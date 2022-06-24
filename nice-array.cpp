]<<" ";
		

	return 0;
}


/*
Antonio has an array A consisting of N integers.

An array B is a prefix of array A if B can be formed by deleting several(possibly zero but not all) elements from the end of array A. Like for array A = [5,1,4,2], the prefixes are A1..1 = [5], A1..2 = [5,1], A1..3 = [5,1,4], A1..4 = [5,1,4,2].

A prefix is considered good if the sum of its elements is an odd number. Like for A = [5,1,4,2], A1..1 and A1..4 are the good prefixes.

Now, Antonio wants to rearrange the elements of array A such that there are a maximum number of good prefixes in final array A.

Given array A, print the maximum number of good prefixes Antonio can get in final array A.

Input Format

First line contains a single integer denoting N.
Next line contains N space separated integers denoting the elements of array A.
Output Format

First print the maximum number of good prefixes Antonio can get in final array A.
Constraints

1<=N<=105
1<=Ai<=105
Sample Input 1

3

4 3 6

Sample Output 1

3

Explanation of Sample 1

Rearrange the elements of array A as [3,4,6]

Sum of elements in prefix A1..1 = 3

Sum of elements in prefix A1..2 = 3+4 = 7

Sum of elements in prefix A1..3 = 3+4+6 = 13

Hence it is possible to rearrange the elements of the given array such that all its three prefixes are good.



Things to Note for the Candidate:



? You can use your own IDE like Visual Studio Code, Eclipse, or any other IDE that you are comfortable with to build your solution code.

The IDE provided on the platform is purely for submission. Avoid using the IDE for coding out the solution.

Test against any custom input in your own IDE. In the IDE provided on the platform, you cannot pass custom test cases and see the output.

Use standard input and standard output in your program for the IDE to run the test cases smoothly against your code. We are giving a sample problem statement along with a solution that will pass the test cases in the IDE. - Sample Problem Statement (Right Click and Open in New Tab to view.)
*/

/*
Antonio has an array A consisting of N integers.

An array is called a nice array if the sum of all elements of that array is utmost K. Like for K=9, [1,4,1,0], [1,1,1,1], [1,4,4] etc. are nice arrays whereas [1,2,10], [10,10,10], [2,8] etc. are not.

To convert array A into a nice array Antonio repeatedly performs the below operation on it till it becomes a nice array :

Let X = minimum non-zero element of array A.
Subtract X from all non-zero elements of array A.
Given array A and K, print the final elements of array A.

See sample explanation for more clarity on the question.



Input Format



First line of input contains two space separated integers denoting N and K.
Next line contains N space separated integers denoting the elements of array A.


Output Format



Print the final elements of array A.


Constraints



1<=N<=105
1<=Ai<=109
1<=K<=1014


Sample Input 1



4 11

10 1 7 3



Sample Output 1



7 0 4 0



Explanation of Sample 1



Operation 1 :
A = [10 1 7 3]. X = Minimum non-zero element = 1.
A becomes = [9 0 6 2]. Sum of elements = 17.
Operation 2 :
A = [9 0 6 2]. X = Minimum non-zero element = 2.
A becomes = [7 0 4 0]. Sum of elements = 11. Hence array A is now nice.
*/


#include <bits/stdc++.h>
using namespace std;

#define F for(int i=0;i<n;i++)


int minelement(int *arr, int n){
	
	int min = arr[0];
	
	for(int i=1;i<n;i++)
		{
			if(arr[i]!=0){
				if(arr[i]<min)
				min = arr[i];
			}
		}
//		cout<<min<<endl;
		return min;
		
		
	
}


int main() {
	// your code goes here


		int n,k;
		cin>>n>>k;
		int arr[n];
		
		int sum=0;
		int count = 0;
		
		F {
			cin>>arr[i];
			sum+=arr[i];
//			cout<<sum<<endl;
		}
//		cout<<sum(arr);
		
		while(sum>k)
		{
			
		sum=0;
		int minEle = minelement(arr,n);
//		cout<<minEle<<endl;
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=0) arr[i]=arr[i]-minEle;
			sum= sum+arr[i];
		}
//		cout<<sum<<endl;
			
		}
		
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		

	return 0;
}
