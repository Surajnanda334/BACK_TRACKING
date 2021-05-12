// permutations of a string using recursion(Back-Tracking)

#include <iostream>
#include <string>

using namespace std;


void permutation(string str, int start, int end)
{
  if(start==end)    //base condition (when left and right are same then )
  {
    cout<<str<<"\n";
  }
  for(int i=start; i<=end; i++)
  {
    swap(str[start],str[i]);    //Swap ith element with First element to fix the first element

    permutation(str,start+1,end);   //Recurring call

    swap(str[start],str[i]);    //Swap again to Back track and return to the previous node
  }
}

int main()
{
  string str = "abcd";
  permutation(str,0,str.length()-1);
  return 0;
}