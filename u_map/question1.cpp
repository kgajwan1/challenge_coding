#include <bits/stdc++.h>
using namespace std;

//count frequencies in unordered map
void print_freq(const string &str)
{
    unordered_map <string,int> wordFreq;
    stringstream ss(str);
    string word;
    while (ss>>word)
    {
        wordFreq[word]++;
    }
    for (auto p :wordFreq) 
        cout << "(" << p.first << ", " << p.second << ")\n"; 
    //way 2
    //when you refer by beginning and end, you use -> instead of . 
    for (auto q = wordFreq.begin(); q != wordFreq.end(); q++) 
        cout << "(" << q->first << ", " << q->second << ")\n"; 

}

int main()
{
        string str = "geeks for geeks geeks quiz "
                 "practice qa for"; 
    print_freq(str); 
    return 0; 
}
