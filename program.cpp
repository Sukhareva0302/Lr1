﻿#include <iostream>
using namespace std;

class Node {
    private:
        int data; //data in the node
        Node* next; //pointer to the next node
    public:
        Node(int intdata)
        {
            data = intdata; //the initialized data is set as the head
            next = NULL; //the text node is set as 'NULL', as there no next node
        }
        int getData() //function that return data of a given node
        {
            return data;
        }
        Node* getNext() //function that return pointer to the next element of given node
        {
            return next;
        }
        void setData(int newData) //function that set data as the new value
        {
            data = newData;
        }
        void setNext(Node *newNext) //function that set pointer as the new value
        {
            next = newNext;
        }
};

class List
{
private:
    Node* head; //begining of the List
    unsigned int error; //to find errors when using methods
    Node* search(size_t index) //searches for the node corresponding to the index
    {
        Node* cur = head; //current = head
        size_t counter = 0;
        while (counter < index)
        {
            cur = cur->getNext();
            counter++;
        }
        return cur;
    }
    void insert_first(int newData) //inserts first element in the List
    {
        Node* newNode = new Node(newData);
        head = newNode;
    }
    void delete_one()
    {
        Node* tmp = head;
        head = NULL;
        delete tmp;
    }
public:
    List() //start of the new List
    {
        head = NULL;
        error = 0;
    }
    void reset_error()
    {
        error = 0;
    }
    unsigned int get_error()
    {
        return error;
    }

    void push_back(int newData) //adds newData to the end of the List
    {
        if (isEmpty())
        {
            insert_first(newData);
        }
        else
        {
            Node* tmp = new Node(newData);
            Node* cur = head; //current = head
            while (cur->getNext() != NULL) { cur = cur->getNext(); }
            cur->setNext(tmp);
        }
    }
    void push_front(int newData) //adds newData to the beginning of the List
    {
        if (isEmpty())
        {
            insert_first(newData);
        }
        else
        {
            Node* tmp = new Node(newData);
            tmp->setNext(head);
            head = tmp;
        }
    }
    void pop_back() //deletes the node in the end
    {
        if (isEmpty())
        {
            error = 1;
        }
        else
        {
            if (head->getNext() == NULL)
            {
                delete_one();
            }
            else
            {
                Node* cur = head; //current = head
                Node* tmp = cur->getNext();
                while (tmp->getNext() != NULL)
                {
                    cur = cur->getNext();
                    tmp = tmp->getNext();
                }
                cur->setNext(NULL);
                delete tmp;
            }
        }
    }
    void pop_front() //deletes the node in the beginning
    {
        if (isEmpty())
        {
            error = 1;
        }
        else
        {
            Node* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }
    void insert_Node(int newData, size_t index)//inserts an element by index (before the element that has been available by this index earlier)
    {
        if((isEmpty())||(get_size()<=index))
        {
            if (get_size() == index)
            {
                push_back(newData);
            }
            else
            {
                error = 1;
            }
        }
        else
        {
            if(index==0)
            {
                push_front(newData);
            }
            else
            {
                Node* prev = search(index - 1); // prev (previous) is set to node previous to the one that should be replaced
                Node* newNode = new Node(newData); // the newNode is the new node that will be available by this index
                newNode->setNext(prev->getNext());
                prev->setNext(newNode);
            }
        }
    }
    int at(size_t index) //gets data element in the node corresponding to the index
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            error = 1;
            return 0;
        }
        else
        {
            return search(index)->getData();
        }
    }
    void remove(size_t index) //deletes the node corresponding to the index
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            error = 1;
        }
        else
        {
            if (index!=0)
            {
                Node* forDelete = search(index); // forDelete is set to the node that should be deleted 
                Node* prev = search(index - 1); // prev (previous) is set to node previous to the one that should be deleted 
                prev->setNext(forDelete->getNext());
                delete forDelete;
            }
            else
            {
                pop_front();
            }
        }
    }
    size_t get_size() //gets the size of the List
    {
        Node* cur = head; //current = head
        size_t counter = 0;
        while (cur != NULL)
        {
            counter++;
            cur = cur->getNext();
        }
        return counter;
    }
    void clear() //clears the entire List
    {
        Node* cur; //current
        while (head != NULL)
        {
            cur = head->getNext();
            delete head;
            head = cur;
        }
    }
    void set(size_t index, int newData) //replacing an element by index with a new value
    {
        if ((isEmpty()) || (get_size() <= index))
        {
            error = 1;
        }
        else
        {
            search(index)->setData(newData);
        }
    }
    bool isEmpty() //checks if the List is empty
    {
        return head == NULL;
    }
    void insert_List(List* newList, size_t index) //inserts tne new List starting from the index
    {
        if (newList->head != NULL)
        {
            if ((isEmpty()) || (get_size() < index))
            {
                if (index == 0)
                {
                    head = newList->head;
                }
                else
                {
                    error = 1;
                }
            }
            else
            {
                if (index == 0)
                {
                    Node* tmp = newList->head;
                    while (tmp->getNext() != NULL)
                    {
                        tmp = tmp->getNext();
                    }
                    tmp->setNext(head->getNext());
                    head->setNext(tmp);
                }
                else
                {
                    Node* prev = search(index - 1); //prev (previous) is set to node previous to the one starting from which a new list will be inserted
                    Node* newList_cur = newList->head; //newList_cur=current of the new List
                    while (newList_cur->getNext() != NULL)
                    {
                        newList_cur = newList_cur->getNext();
                    }
                    newList_cur->setNext(prev->getNext());
                    prev->setNext(newList->head);
                }
            }
        }
    }
    friend ostream& operator<<(ostream& stream, const List& List);
};
ostream& operator<<(ostream& stream, const List& List)
{
    if (List.head==NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node* node = List.head;
        while (node != NULL)
        {
            cout << node->getData() << " -> ";
            node = node->getNext();
        }
        cout << "XX" <<endl << endl;
    }
    return stream;
}



int main()
{
    List list = List();
    List list_for_insert = List();
    for (int counter = 1; counter < 4; counter++)
    {
        list_for_insert.push_back(counter);
    }
    int instruction, data;
    size_t index;
    data = 0; index = 0; //default values
    unsigned int not_end = 1;// 1 - not the end of the program, 0 - end of the program
    while (not_end)
    {
        list.reset_error();
        cout << "\n\n"<<list;
        cout << "\nWhat do you want to do?\n\n";
        cout << "1) Add new Data to the end of the List.\n"
            << "2) Add new Data to the beginning of the List\n"
            << "3) Delete the node in the end of the List\n"
            << "4) Delete the node in the beginning of the List\n"
            << "5) Insert an element by Index (before the element that has been available by this index earlier)\n"
            << "6) Get Data element in the node corresponding to the Index\n"
            << "7) Delete the node corresponding to the Index\n"
            << "8) Get the size of the List\n"
            << "9) Clear the entire List\n"
            << "10) Replace an element by Index with a new Data\n"
            << "11) Check if the List is empty\n"
            << "12) Insert different List (1->2->3->XX) starting from the Index\n"
            << "13) Finish the program\n";
        cin >> instruction;
        cout << "\n\n";
        if ((instruction < 1) || (instruction > 13))
        {
            cout << "Incorrectly entered instruction" << endl;
            cout << "Do you want to continue?\n";
            cout << " 0)No\n 1)Yes\n";
            cin >> not_end;
        }
        else
        {
            switch (instruction)
            {
            case 1:
                cout << "Insert Data\n";
                cin >> data;
                list.push_back(data);
                break;
            case 2:
                cout << "Insert Data\n";
                cin >> data;
                list.push_front(data);
                break;
            case 3:
                list.pop_back();
                if (list.get_error())
                {
                    cout << "There is no element to delete\n";
                }
                break;
            case 4:
                list.pop_front();
                if (list.get_error())
                {
                    cout << "There is no element to delete\n";
                }
                break;
            case 5:
                cout << "Insert Data\n";
                cin >> data;
                cout << "Insert Index\n";
                cin >> index;
                list.insert_Node(data, index);
                if (list.get_error())
                {
                    cout << "There is no element corresponding to the index. The operation cannot be done\n";
                }
                break;
            case 6:
            {
                int tmp;// tmp - temporary value
                cout << "Insert Index\n";
                cin >> index;
                tmp = list.at(index);
                if (list.get_error())
                {
                    cout << "There is no element corresponding to the index. The operation cannot be done\n";
                }
                else
                {
                    cout << "Data in this element = " << tmp << endl;
                }
                break;
            }
            case 7:
                cout << "Insert Index\n";
                cin >> index;
                list.remove(index);
                if (list.get_error())
                {
                    cout << "There is no element corresponding to the index. The operation cannot be done\n";
                }
                break;
            case 8:
            {
                size_t tmpr;// tmpr - temporary value
                tmpr = list.get_size();
                if (tmpr == 0)
                {
                    cout << "List is empty\n";
                }
                else
                {
                    cout << "The size of the list = " << tmpr << " element(s)\n";
                }
                break;
            }
            case 9:
                list.clear();
                break;
            case 10:
                cout << "Insert Data\n";
                cin >> data;
                cout << "Insert Index\n";
                cin >> index;
                list.set(index, data);
                if (list.get_error())
                {
                    cout << "There is no element corresponding to the index. The operation cannot be done\n";
                }
                break;
            case 11:
                if (list.isEmpty())
                {
                    cout << "List is empty\n";
                }
                else
                {
                    cout << "List is not empty\n";
                }
                break;
            case 12:
                cout << "Insert Index\n";
                cin >> index;
                list.insert_List(&list_for_insert, index);
                if (list.get_error())
                {
                    cout << "There is no element corresponding to the index. The operation cannot be done\n";
                }
                break;
            case 13:
                not_end = 0;
                break;
            }
            if (not_end)
            {
                cout << "The List after completing the instruction is:\n" << list;
                cout << "Do you want to continue?\n";
                cout << " 0)No\n 1)Yes\n";
                cin >> not_end;
            }
        }
    }
}

/*    List list = List();
    cout << list << endl;
    list.push_front(5);
    cout << list;
    for (int i = 0; i < 3; i++)
    {
        list.push_back(i);
    }
    cout << list;
    list.insert_Node(8, 1);
    cout << list;
    list.remove(3);
    cout << list;*/