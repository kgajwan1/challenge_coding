#include<bits/stdc++.h>

using namespace std;



int main()
{
unordered_map<string,int> u_map;
u_map["GeeksforGeeks"] = 10; 
u_map["Practice"] = 20; 
u_map["Contribute"] = 30; 

for (auto x:u_map)
{
    cout << x.first<<"  "<< x.second<<'\n';
}

    unordered_map<string, double> umap; 
    umap["PI"] = 3.14; 
    umap["root2"] = 1.414; 
    umap["root3"] = 1.732; 
    umap["log10"] = 2.302; 
    umap["loge"] = 1.0; 
    umap.insert(make_pair("e", 2.718)); 
    for (auto y:umap)
{
    cout << y.first<<"  "<< y.second<<'\n';
}
}
