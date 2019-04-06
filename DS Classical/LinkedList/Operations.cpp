//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Linked list vs arrays :
    Advantages :
        1. Dynamic size
        2. Easy insertion and deletion

    Disadvantages :
        1. random access is difficult
        2. extra space for pointers
        3. no cache as there is no locality of reference

    -Memory assignment is runtime here

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

struct LL
{
    ll data;
    LL *next;
};

LL *Node(ll val)
{
    LL *newnode = new LL();
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

void printList(LL *list)
{
    LL *head = list;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtBegin(ll val, LL *&head)
{
    LL *newnode = Node(val);

    newnode->next = head;
    head = newnode;
}

void insertAtEnd(ll val, LL *&head)
{
    LL *newnode = Node(val);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    LL *list = head;

    while (list->next != NULL)
        list = list->next;

    list->next = newnode;
}

void deleteAtBegin(LL *&head)
{
    if (head == NULL)
        return;

    LL *temp = head;
    head = head->next;
    delete temp;
}

ll lengthOfList(LL *head)
{
    if (head == NULL)
        return 0;

    return 1 + lengthOfList(head->next);
}

LL *nthNodeInList(LL *head, ll N)
{
    if (head == NULL)
        return NULL;
    if (N == 1)
        return head;
    return nthNodeInList(head->next, N - 1);
}

void nthNodeFromEnd(LL *head, ll N)
{
    static int i = 0;

    if (head == NULL)
        return;
    nthNodeFromEnd(head->next, N - 1);

    if (++i == N)
        cout << head->data << endl;
}

void reverseList(LL *&head)
{
    LL *curr = head, *prev = NULL, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printList(head);
}

LL *reverseListTwoPtr(LL *head)
{
    LL *prev = NULL, *next;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void reverseRecur(LL *&head, LL *curr)
{
    if (head == NULL)
    {
        return;
    }

    if (curr->next == NULL)
    {
        head = curr;
        return;
    }

    reverseRecur(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;
}

LL *middleOfList(LL *list)
{
    //count length and count/2 next
    // only increase the next for odd counts
    // fast and slow
    if (list == NULL)
        return list;

    LL *fast = list, *slow = list;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindromeList(LL *&left, LL *right)
{
    if (right == NULL)
        return true;

    bool isP = isPalindromeList(left, right->next);

    if (!isP)
        return false;

    isP = isP && (left->data == right->data);

    left = left->next;

    return isP;
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    LL *list = NULL;
    while (true)
    {
        ll x;
        cin >> x;
        if (x)
            insertAtEnd(x, list);
        else
        {
            printList(list);
            cout << "Length of list is : " << lengthOfList(list) << endl;
            deleteAtBegin(list);
            printList(list);
            cout << "Length of list is : " << lengthOfList(list) << endl;
            cin >> x;
            LL *temp = nthNodeInList(list, x);
            if (temp != NULL)
                cout << x << "th node in list is " << temp->data << endl;
            cout << "Reverse of the list is" << endl;
            reverseRecur(list, list);
            printList(list);
            cout << "Middle of the list is " << middleOfList(list)->data << endl;
            cout << "List is a palindrome : " << (isPalindromeList(list, list) ? "Yes" : "No") << endl;
            break;
        }
    }
    return 0;
}
// END OF SOURCE CODE