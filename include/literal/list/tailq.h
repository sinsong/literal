#pragma once

#include "literal/debug.h"
#include "literal/list/node.h"

namespace literal
{

template <typename Type>
class tailq
{
public:
    typedef Type            value_type;
    typedef list_node<Type> node_type;

    tailq()
        : first(nullptr),
          last(nullptr){}

    ~tailq()
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
    node_type *_last() const { return last; }

    void cons(const value_type &value) { push_front(value); }
    void push(const value_type &value) { push_back(value); }

    // TODO: pull & pop
    value_type pull() = delete;
    value_type pop() = delete;

    void push_front(const value_type &value)
    {
        // construct
        node_type *target = new node_type;
        target->value = value;

        // property
        if ( (target->next = first) != nullptr )
            first->prev = target;
        else // first == nullptr
            last = target; // special
        target->prev = nullptr;

        // special
        first = target;
    }

    void push_back(const value_type &value)
    {
        // construct
        node_type *target = new node_type;
        target->value = value;

        target->next = nullptr;
        if(last)
        {
            target->prev = last;
            last->next = target;
        }
        else
        {
            first = target; // special
            target->prev = nullptr;
        }
        last = target; // special
    }

    void insert_before(node_type *node, const value_type &value)
    {
        // construct
        node_type *target = new node_type;
        target->value = value;

        // property
        if ( (target->prev = node->prev) == nullptr )
            first = target; // special
        target->next = node;
        node->prev = target;
    }

    void insert_after(node_type *node, const value_type &value)
    {
        // construct
        node_type *target = new node_type;
        target->value = value;

        // property
        if ( (target->next = node->next) != nullptr ) // 要不要改 node->next 的 prev
            node->next->prev = target;
        else // node == last
            last = target; // special
        node->next = target;
        target->prev = node;
    }

    void remove(node_type *node)
    {
        node_type *target = node;
        
        if ( target->next != nullptr ) // 存在 next
            target->next->prev = target->prev;
        else
            last = target->prev;
        
        if ( target->prev != nullptr ) // 存在 prev
            target->prev->next = target->next;
        else
            first = target->next;

        delete target;
    }


private:
    node_type *first;
    node_type *last;
};

} // namespace literal