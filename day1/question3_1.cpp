#include<bits/stdc++.h>
//re- see
class nStacks
{
    private:
    int *arr;
    int *top;
    int *navigate_array;
    int n,k,free;

    public:
    nStacks(int k, int n);

    bool isFull() {return (free == -1);}
    void push(int item, int sn);
    int pop(int sn);
    bool isEmpty(int sn){ return (top[sn] == -1 );}
};

nStacks::nStacks(int k1,int n1)
{
    k = k1;
    n = n1;
    arr = new int[n];
    top = new int[k];
	navigate_array = new int[n];

    for (int i = 0;i<k;i++)
    {
        top[i] = -1; 
    } 
    free =0;

    for (int i =0;i<n-1;i++)
    {
        navigate_array[i] = i+1;
    }
    navigate_array[n-1] = -1;
}

void nStacks::push(int item, int sn)
{
	if (isFull())return;
	int current_free = free;
	int next_free = navigate_array[current_free];
	free = next_free;
	navigate_array[current_free] = top[sn];
	arr[current_free] = item;
	top[sn] = current_free;
}

int nStacks::pop(int sn)
{
	if (isEmpty(sn))return INT_MAX;
	int current_free = top[sn];
	int next_free = free;
	top[sn] = navigate_array[current_free];
	navigate_array[current_free] = next_free;
	free = current_free;
	return arr[current_free];
}

int main()
{
    int k = 3, n = 10;
    nStacks ns(k, n);

    for (int i =0;i<10;i++)
    {
        ns.push(i,1);   
    }
    for (int i =0;i<10;i++)
    {
        std::cout <<ns.pop(1)<<'\n';   
    } 
}