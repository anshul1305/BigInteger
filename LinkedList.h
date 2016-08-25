#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node* next;
}NODE;

typedef NODE* NODEPTR;

inline NODEPTR NewNode(int data, NODEPTR nextN = NULL)
{
	NODEPTR temp = new NODE();
	temp->data = data;
	temp->next = nextN;
	return temp;
}

inline void swap(NODEPTR *head1, NODEPTR *head2)
{
    NODEPTR temp = *head1;
    *head1 = *head2;
    *head2 = temp;
}

inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
inline void makeNext(NODEPTR *node, int data)
{
    NODEPTR newNode = NewNode(data, (*node)->next);
    (*node)->next = newNode;
}

inline NODEPTR append(NODEPTR head, int data)
{
    if(!head)
    {
        return NewNode(data);
    }
    NODEPTR current = head;
    while(current->next)
    {
        current = current->next;
    }
    makeNext(&current, data);
    return head;
}

inline int getLen(NODEPTR node)
{
    int len = 0;
    while(node)
    {
        len++;
        node = node->next;
    }
    return len;
}

inline NODEPTR makeList(int array[], int len)
{
    NODEPTR temp = NewNode(array[0]);
    NODEPTR curr = temp;
    for(int i=1;i<len;i++)
    {
        curr->next = NewNode(array[i]);
        curr = curr->next;
    }
    return temp;
}

inline void printList(NODEPTR head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

inline void deleteList(NODEPTR head)
{
     while(head)
    {
        NODEPTR temp = head->next;
        delete head;
        head = temp;
    }
}

inline string toString(NODEPTR head)
{
    char strBuf[getLen(head)+1];
    int i = 0;
    NODEPTR current = head;
    while(head)
    {
        strBuf[i++] = head->data + '0';
        head = head->next;
    }
    strBuf[i] = '\0';
    string res(strBuf);
    deleteList(current);
    return res;
}

#endif