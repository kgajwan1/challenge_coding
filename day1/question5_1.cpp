#include<bits/stdc++.h>

int updatebits(int n, int m, int i, int j)
{
    if(i>j||i<0||i>32){
        return -1;
    }
    /* Create a mask to clear bits i through jinn. EXAMPLE: i = 2, j = 4.
     Result 3 * should be 11100011. 7*/
    int allones = -1;
    // 1s before position j, then 0s. left = 11100000 
    int left = j<31 ?(allones<<(j+1)):0;
    int right  =((1<<i)-1);
    int mask = (left | right);
    int n_cleared = n & mask;
    int m_shifted = m << i;
    return (n_cleared | m_shifted);

}

int main()
{
    auto result = updatebits(0b11111111111, 0b110, 6, 8);
    std::cout <<0b11111110111;
    //1024 input, 1100 output
    std::cout << result;
}