#include<bits/stdc++.h>

int countsteps(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n == 0|| n ==1)
    {
        return 1;
    }
    else
    {
    return countsteps(n-1)+countsteps(n-2)+countsteps(n-3);
    }
}
int main()
{
    int n =10;
    std::cout << countsteps(n);

}