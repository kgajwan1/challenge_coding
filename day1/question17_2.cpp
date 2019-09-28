#include<bits/stdc++.h>

void shuffleIter(std::vector<int> &cards)
{
    for (int i= 1; i < cards.size(); i++)
    {
        int k = rand()%i;
        int temp = cards[k];
        cards[k] = cards[i];
        cards[i] = temp;
    } 
}

int main()
{
    std::vector<int> v; 
    for (int i = 0;i<52;i++)
    {
        v.push_back(i);
        std::cout << v[i]<<" ";
    } 
    std::cout << '\n';
    shuffleIter(v);
    for (int i = 0;i<52;i++)
    {
        std::cout << v[i]<<" ";
    } 

}