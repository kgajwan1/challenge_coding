#include <bits/stdc++.h>
/*
Implement a function void reversetchar* str) 
in C or C++ which reverses a nullterminated string.
*/ 

void swap(char* a, char* b){
    char c = *a;
    *a = *b;
    *b = c;
}

void reverse (char *str)
{
    if(!str)
    {
        return;
    }
    char *begin  =str;
    char *end = begin + strlen(str)-1;
    while (begin < end)
    {
        swap(begin,end) ;
        begin++;
        end--;
    }
}

int main(){
    char strArray[] = "1point3acres";
    std::cout<< "Before Reverse: \n"<< strArray<<'\n';
    reverse(strArray);
    std::cout<<"After Reverse: \n"<< strArray<<'\n';
}
