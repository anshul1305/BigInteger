#ifndef _BIG_INTEGER_H
#define _BIG_INTEGER_H
#include "LinkedList.h"
#include <vector>
#include <iostream>

void addCarryToRem(NODEPTR head, NODEPTR curr, int &carry, NODEPTR *temp);

void addListAndSave(NODEPTR head1, NODEPTR head2, NODEPTR *temp, int &carry);

NODEPTR getSameLevel(NODEPTR head1, int len1, NODEPTR head2, int len2);

NODEPTR addList(NODEPTR head1, NODEPTR head2);

class BigInteger
{
private:
    NODEPTR head1;
    NODEPTR head2;

public:
    BigInteger(string str1, string str2);
    ~BigInteger();
    string Add();
};
#endif // BIGINTEGER_H
