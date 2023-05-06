#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data = 0;
    node *next = NULL;
};

class sll
{
    node *head = NULL, *tail = NULL;

public:
    sll()
    {
        head = new node;
        tail = head;
        head->next = NULL;
    }
    sll(int n, node *in = 0)
    {
        head = new node;
        tail = head;
        head->data = n;
        head->next = in;
        if (in != 0)
            tail = in;
    }
    node *getHead()
    {
        return head;
    }
    node *getTail()
    {
        return tail;
    }
    void insertAtHead(int n)
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = new node;
            tmp->data = n;
            tmp->next = head;
            head = tmp;
            tmp = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            head->data = n;
            return;
        }
        else
        {
            head = new node;
            head->data = n;
            head->next = NULL;
            tail = head;
        }
    }
    void insertAtTail(int n)
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = new node;
            tmp->data = n;
            tail->next = tmp;
            tail = tmp;
            tmp = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            head->data = n;
            return;
        }
        else
        {
            head = new node;
            head->data = n;
            head->next = NULL;
            tail = head;
        }
    }
    int size()
    {
        int count = 0;
        node *tmp = head;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        tmp = NULL;
        delete tmp;
        return count;
    }
    void insertAt(int n, int index)
    {
        if (index == 1)
        {
            insertAtHead(n);
            return;
        }
        if (index == size() + 1)
        {
            insertAtTail(n);
            return;
        }
        node *tmp = new node;
        node *tmp2 = head;
        tmp->data = n;
        tmp->next = head;
        while (--index)
        {
            if (index != 1)
                tmp2 = tmp2->next;
            tmp->next = tmp2->next;
        }
        tmp2->next = tmp;
        tmp2 = NULL;
        delete tmp2;
    }
    void removeAtHead()
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            delete head;
            delete tail;
            return;
        }
    }
    void removeAtTail()
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = head, *tmp2;
            while (tmp != tail)
            {
                tmp2 = tmp;
                tmp = tmp->next;
            }
            tail = tmp2;
            tail->next = NULL;
            tmp2 = NULL;
            delete tmp;
            delete tmp2;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            delete head;
            delete tail;
            return;
        }
    }
    void removeAt(int i)
    {
        node *tmp = head, *tmp2 = head;
        if (i == 1)
        {
            removeAtHead();
            return;
        }
        if (i == size())
        {
            removeAtTail();
            return;
        }
        while (--i)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        if (tmp != NULL)
        {
            tmp2->next = tmp->next;
            delete tmp;
            tmp2 = NULL;
            delete tmp2;
        }
    }
    int retrieveAt(int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        return tmp->data;
    }
    void replaceAt(int a, int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        tmp->data = a;
    }
    bool isExist(int i)
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == i)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    bool isItemAtEqual(int a, int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        if (tmp->data == a)
            return true;
        return false;
    }
    void swap(int i1, int i2)
    {
        node *tmp = head, *tmp2 = head, *tmp3 = head, *tmp4 = head;
        int y = 0;
        if ((i1 == 1 && i2 == 2) || (i1 == 2 && i2 == 1))
        {
            tmp2 = head->next;
            tmp->next = tmp2->next;
            tmp2->next = tmp;
            head = tmp2;
        }
        else if ((i1 == 1 && i2 != 1) || (i2 == 1 && i1 != 1))
        {
            if (i1 == 1 && i2 != 1)
            {
                while (--i2)
                {
                    tmp3 = tmp4;
                    tmp4 = tmp4->next;
                }
                tmp2 = tmp->next;
                head = tmp4;
                tmp->next = tmp4->next;
                tmp3->next = tmp;
                tmp4->next = tmp2;
            }
            else
            {
                node *tmp = head, *tmp2 = head, *tmp3 = head, *tmp4 = head;
                while (--i1)
                {
                    tmp3 = tmp4;
                    tmp4 = tmp4->next;
                }
                tmp2 = tmp->next;
                head = tmp4;
                tmp->next = tmp4->next;
                tmp3->next = tmp;
                tmp4->next = tmp2;
            }
        }
        tmp = NULL;
        tmp2 = NULL;
        tmp3 = NULL;
        tmp4 = NULL;
        delete tmp;
        delete tmp2;
        delete tmp3;
        delete tmp4;
    }
    void clear()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            removeAtHead();
        }
        delete tmp;
    }
    void print()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        delete tmp;
    }
    friend ostream &operator<<(ostream &out, sll &a)
    {
        node *tmp = a.getHead();
        while (tmp != NULL)
        {
            out << tmp->data << " ";
            tmp = tmp->next;
        }
        tmp = NULL;
        delete tmp;
        return out;
    }
};

int main()
{
    sll a;
    a.insertAtHead(2);
    a.insertAtHead(1);
    a.insertAtTail(3);
    a.insertAtTail(4);
    // a.insertAt(55, 3);
    // a.replaceAt(55, 4);
    // cout << a.isExist(5);
    // cout << a.isItemAtEqual(5, 1);
    a.swap(1, 4);
    a.print();
    // a.insertAt(555, 4);
    // a.removeAt(1);
    // cout << a.retrieveAt(1);
    // a.insertAtHead(3);
    // cout << a;
    return 0;
}