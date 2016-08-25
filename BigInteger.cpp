#include "BigInteger.h"
#include <string>

void addCarryToRem(NODEPTR head, NODEPTR curr, int &carry, NODEPTR *temp)
{
    if(head->next != curr)
        addCarryToRem(head->next, curr, carry, temp);
    int sum = head->data + carry;
    if(sum > 9)
    {
        carry = 1;
        sum = sum%10;
    }
    else
    {
        carry = 0;
    }
    makeNext(temp,sum);
}

void addListAndSave(NODEPTR head1, NODEPTR head2, NODEPTR *temp, int &carry)
{
    if(head1->next && head2->next)
        addListAndSave(head1->next, head2->next, temp, carry);
    else if(head1->next && !head2->next)
        addListAndSave(head1->next, head2, temp, carry);
    else if(!head1->next && head2->next)
        addListAndSave(head1, head2, temp, carry);
    int sum = head1->data + head2->data + carry;
    if(sum > 9)
    {
        carry = 1;
        sum = sum%10;
    }
    else
    {
        carry = 0;
    }
    makeNext(temp,sum);
}

NODEPTR getSameLevel(NODEPTR head1, int len1, NODEPTR head2, int len2)
{
    while(len1>len2)
    {
        head1 = head1->next;
        len1--;
    }
    while(len2>len1)
    {
        head2 = head2->next;
        len2--;
    }
    return head1;
}

NODEPTR addList(NODEPTR head1, NODEPTR head2)
{
    int len1 = getLen(head1);
    int len2 = getLen(head2);
    
    if(len1 < len2)
    {
        swap(&head1, &head2);
        swap(len1, len2);
    }
    NODEPTR same = getSameLevel(head1, len1, head2, len2);
    NODEPTR temp = new NODE();
    temp->data = -1;
    temp->next = NULL;
    int carry = 0;
    addListAndSave(same, head2, &temp, carry);
    if(len1 != len2)
        addCarryToRem(head1, same, carry, &temp);
    if(carry)
        makeNext(&temp,1);
    NODEPTR t = temp->next;
    delete temp;
    return t;
}

BigInteger::BigInteger(string str1, string str2):head1(NULL),head2(NULL)
{
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i=0;i<len1;i++)
    {
        head1 = append(head1,str1[i]-'0');
    }
    for(int i=0;i<len2;i++)
    {
        head2 = append(head2,str2[i]-'0');
    }
    printList(head1);
    printList(head2);
}

string BigInteger::Add()
{
    NODEPTR res = addList(head1, head2);
    return toString(res);
}

BigInteger::~BigInteger()
{
    deleteList(head1);
    deleteList(head2);
}

