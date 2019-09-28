#include<bits/stdc++.h>
/*
Write a function that adds two numbers. 
You should not use+ or any arithmetic operators 
*/

int add (int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    int sum = a^b;
    int carry = (a&b)<<1; //carry but do not add
    return add(sum,carry);
}
int main()
{
    int a = 132;
    int b = 900;
    std::cout<< add(a,b); 
}