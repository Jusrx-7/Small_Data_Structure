#ifndef DATA_STRUCTURE_LINKED_LIST_H
#define DATA_STRUCTURE_LINKED_LIST_H

#include <iostream>

template<class DATA_TYPE>
class LINKED_LIST
{
private:
    struct node
    {
        DATA_TYPE data;
        node* next;
    };
    typedef node* pointer;
    pointer head;

public:
    LINKED_LIST()
    {
        head = nullptr;
    }

    ~LINKED_LIST()
    {
        pointer current = head;
        while (current != nullptr)
        {
            pointer next = current->next;
            delete current;
            current = next;
        }
    }

    pointer CreateNODE(DATA_TYPE dat)
    {
        pointer new_node = new node;
        new_node->data = dat;
        new_node->next = nullptr;
        return new_node;
    }
    void AddNode(DATA_TYPE dat)
    {
        pointer new_node = CreateNODE(dat);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            pointer current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    void remove(DATA_TYPE dat)
    {
        pointer current = head;
        pointer prev = nullptr;

        while (current != nullptr && current->data != dat)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void SHOW()
    {
        pointer current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int getSize()
    {
        int size = 0;
        pointer current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    bool search(DATA_TYPE dat)
    {
        pointer current = head;
        while (current != nullptr)
        {
            if (current->data == dat)
            {
                // You can return anything else ex: return node number $i or return
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertAfter(pointer prev_node, DATA_TYPE dat)
    {
        if (prev_node == nullptr)
        {
            return;  // Cannot insert after a null node
        }
        pointer new_node = CreateNODE(dat);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    void insertBefore(pointer next_node, DATA_TYPE dat)
    {
        if (next_node == nullptr)
        {
            return;  // Cannot insert before a null node
        }
        // Special case: insert at the beginning
        if (next_node == head)
        {
            AddNode(dat);
        } else
        {
            pointer current = head;
            while (current->next != next_node)
            {
                current = current->next;
            }
            insertAfter(current, dat);
        }
    }
};

#endif //DATA_STRUCTURE_LINKED_LIST_H
