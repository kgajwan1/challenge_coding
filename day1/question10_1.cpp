#include <bits/stdc++.h>
//merge sort on sorted arrays:
// i was writing a generic one but special should work

void sortedMerge(int *arr,int *b_arr, int l,int r)
{
    int i = l-1;
    int j = r-1;
    int l_val = l+r-1;

    while (j>0)
    {
        if(i>=0 && arr[i]>=b_arr[j])
        {
            arr[l_val] = arr[i];
            i--;
        }
        else
        {
            arr[l_val] = b_arr[j]; 
            j--;
        } 
    }
    l_val--;
}

void printarray(int *arr,int n)
{
    for (int i = 0;i< n; i++)
        std::cout << arr[i]<<" ";
}
int main()
{
  int a[] = {10, 12, 13, 14, 18,-1, -1, -1, -1, -1}; 
  int n = 5; 
  int size_a = 10; 
  int b[] = {16, 17, 19, 20, 22}; 
  int m = 5; 
  sortedMerge(a, b, n, m); 
  printarray(a, size_a); 
  return 0; 
} 
