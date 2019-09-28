#include<bits/stdc++.h>

//swap in place. i.e w/o any temp char

void swap(int &a,int &b)
{
    a = a-b;
    b = a+b;
    a = b-a;
}

void swap2(int &a,int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}
int main()
{
    int a = -5;
    int b = 9;
    std::cout <<a<<'\t'<<b;
    swap (a,b);
    swap2(a,b);
    std::cout <<"\n2 swaps\n";
    std::cout <<a<<'\t'<<b;
}