#include <bits/stdc++.h>
//remove duplicates from unsorted linked list

class Node
{
public:
    Node *next;
    int data;
    
};

void push(Node **n, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
} 
void remove_dupe2(Node **n)
{
    if((*n)== nullptr || (*n)->next == nullptr)
    {
        return ;
    }
    Node *temp = *n;
    while (temp)
    {
        /* code */
        Node *runner = temp;
        while(runner->next != nullptr)
        {
            if(runner->next->data == temp->data)
            {
                runner->next= runner->next->next;
            }
            else 
            {
                runner= runner->next;
            }

        }
        temp = temp->next;
    }
    
}
void remove_dupe(Node *n)
{
    std::unordered_set<int> seen; 
  
    /* Pick elements one by one */
    struct Node *curr = n; 
    struct Node *prev = NULL; 
    while (curr != NULL) 
    { 
        // If current value is seen before 
        if (seen.find(curr->data) != seen.end()) 
        { 
           prev->next = curr->next; 
           delete (curr); 
        } 
        else
        { 
           seen.insert(curr->data); 
           prev = curr; 
        } 
        curr = prev->next; 
    }

}
void printList(Node *n)
{
    while (n!=nullptr)
    {
        std::cout<< n->data<<"  ";
        n = n->next;
    }

}
int main()
{
    Node* head = NULL; 
  	push (&head, 4);
	push (&head, 3);
	push (&head, 4);
	push (&head, 3);
	push (&head, 4);
	push (&head, 4);
	push (&head, 2);
	push (&head, 2);

    std::cout<<"Created Linked List: "; 
    printList(head); 
     
    std::cout<<"\nLinked List after removal of duplicates method 1: "; 
	remove_dupe(head);
	printList(head); 
	std::cout<<"\nLinked List after removal of duplicates method 2: "; 
	remove_dupe2(&head); 
    printList(head);
    return 0; 
}