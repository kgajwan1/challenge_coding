#include<bits/stdc++.h>
//chapter 12
//Last K Lines: Write a method to print the
// last K-lines of an input file using C ++. 
void printLastKlines(char *fname, int n)
{
    if(n<=0)
    {
        return;
    }
    size_t cnt =0;
    char *target_pos = NULL;
    target_pos = strrchr(fname,'\n');
    if(target_pos == NULL)
    {
        std::cout << "ERROR: string doesn't contain '\\n' character\n";  
        return;  
    }
    while (cnt < n)
    {
        while (fname < target_pos && *fname != '\n')  
            --target_pos;  
        if (*target_pos == '\n')  
            --target_pos, ++cnt;
        else
            break;    
    }
    if (fname < target_pos)  
        target_pos += 2;  
  
    // Step 3: Print the string from target_pos  
    std::cout << target_pos << '\n';  
}
int main()
{
    char *str1 ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";  
    char *str2 ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7";  
    char *str3 ="\n";  
    char *str4 = "";  
  
    printLastKlines(str1, 10);  
    std::cout << "-----------------\n";  
  
    printLastKlines(str2, 10);  
    std::cout << "-----------------\n"; 
  
    printLastKlines(str3, 10);  
    std::cout << "-----------------\n";;  
  
    printLastKlines(str4, 10);  
    std::cout << "-----------------\n"; 
  
    return 0;  
}