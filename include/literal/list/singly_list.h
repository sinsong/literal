#pragma once

#include "literal/debug.h"
#include "literal/list/node.h"

namespace literal
{

template <typename Type>
class singly_list
{
public:
    typedef Type                   value_type;
    typedef singly_list_node<Type> node_type;

    singly_list()
        : first(nullptr){}
    
    ~singly_list()
    {
        node_type *target;

        while(first != nullptr)
        {
            target = first;      // cache
            first = first->next; // read
            delete target;       // delete
        }
    }

    bool empty() const { return first == nullptr; }

    node_type *begin() const { return first; };
    node_type *end()   const { return nullptr; }

    void cons(const value_type &value) { return insert_head(value); }
    // TODO: insert_head &&
    void cons(value_type &&value) { return insert_head(value); }

    void insert_head(const value_type &value)
    {
        node_type *target = new node_type;
        target->value = value;
        target->next = first;
        first = target;
    }

    void insert_after(node_type *node, const value_type &value)
    {
        node_type *target = new node_type;
        target->next = node->next;
        target->value = value;

        node->next = target;
    }

    void remove(node_type *node)
    {
        if(first == node)
            return remove_head();
        else
        {
            // 没找到就是 ub，炸！
            node_type *curr = first;
            while (curr->next != node)
                curr = curr->next;
            return remove_after(curr);
        }
        literal_unreachable("can't be here.");
    }

    void remove_after(node_type *node)
    {
        node_type *target = node->next;
        node->next = target->next;
        delete target;
    }

    void remove_head()
    {
        node_type *target = first;
        if (!first)
            return;
        first = first->next;
        delete target;
    }

private:
    node_type *first;
};

} // namespace literal
