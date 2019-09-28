//question 1.1 from CTCI

#include <bits/stdc++.h>
/*
Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures? */

bool allUnique_noDS(std::string str)
{
    if(str.length()>256)
    {
        return false;
    }
    std::sort(str.begin(),str.end());
    for (int i=0;i<str.length();i++)
    {
        if(str[i]== str[i+1])
        {
            return false;
        }
    }
    return true;
}

bool allUnique(std::string str)
{
    if(str.length()> 256)
    {
        return false;
    }
    std::vector<bool> char_set(256);

    for (int i=0;i<str.length();i++)
    {
        int val = str[i];
        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}
int main()
{
    std::string str="Helol";
    std::string str2="Helo";
    
    std::cout <<std::boolalpha<< allUnique_noDS(str)<<'\n';
    std::cout<<std::boolalpha << allUnique_noDS(str2)<<'\n';
    std::cout<<std::boolalpha << allUnique(str)<<'\n';
    std::cout<<std::boolalpha << allUnique(str2)<<'\n';
    
}