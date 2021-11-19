
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void push(struct node **head, int node_data)
{

    struct node *newnode = new node;
    newnode->data = node_data;
    newnode->next = (*head);
    (*head) = newnode;
}
void displayList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << "-->";
        node = node->next;
    }

    if (node == NULL)
        cout << "null";
}
void addatbegining(struct node **head)
{
    int node_data;
    cout << "enter the data you want to add " << endl;
    cin >> node_data;
    struct node *newnode = new node;
    newnode->data = node_data;
    newnode->next = (*head);
    (*head) = newnode;
}
void insertAfter(struct node *prev_node)
{
    int node_data;
    cout << "enter the data you want to add " << endl;
    cin >> node_data;
    if (prev_node == NULL)
    {
        cout << "previous node is null";
        return;
    }
    struct node *newnode = new node;
    newnode->data = node_data;
    newnode->next = prev_node->next;
    prev_node->next = newnode;
}
void addatend(struct node **head)
{
    int node_data;
    cout << "enter the data you want to add " << endl;
    cin >> node_data;
    struct node *newnode = new node;
    struct node *last = *head;
    newnode->data = node_data;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newnode;
    return;
}

void deletenode(struct node **head_ref)
{
    struct node *temp = *head_ref, *prev;
    int key;
    cout << "enter the element to delete " << endl;
    cin >> key;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
void reverse(struct node **head_ref)
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
void update(struct node **head_ref)
{
    struct node *temp = *head_ref;
    int prev, newdata;
    cout << "enter the data you want to change" << endl;
    cin >> prev;
    cout << "enter the updated data " << endl;
    cin >> newdata;
    while (temp != NULL)
    {
        if (temp != NULL && temp->data == prev)
        {
            temp->data = newdata;
            return;
        }
        temp = temp->next;
    }
}
int main()
{
    struct node *head = NULL;
    int option;
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    cout << "linked list: "<< endl;
    displayList(head);
    cout << "" << endl;
    cout << "choose any one option " << endl;
    cout << "1. add at starting og linked list" << endl;
    cout << "2. add in the middle of linked list" << endl;
    cout << "3. add at the last of the linked list " << endl;
    cout << "4. delete node of linked list " << endl;
    cout << "5. reverse of linked list" << endl;
    cout << "6. update data of linked list" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        addatbegining(&head);
        break;
    case 2:
        insertAfter(head->next);
        break;
    case 3:
        addatend(&head);
        break;
    case 4:
        deletenode(&head);
        break;
    case 5:
        reverse(&head);
        break;
    case 6:
        update(&head);
        break;

    default:
    cout<<"none of the above is selected"<<endl;
        break;
    }
    cout << endl
         << "final linked list:" << endl;
    displayList(head);

    return 0;
}    