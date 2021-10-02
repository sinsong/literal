#pragma once

#include "literal/debug.h"
#include "literal/list/node.h"

namespace literal
{

template <typename Type>
class list
{
public:
    using value_type = Type;
    using node_type  = list_node<Type>;
    using iterator = node_type*;
    using constant_iterator = const node_type*;

    list()
        : first(nullptr){}

    ~list()
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

    constant_iterator cbegin() const { return const_cast<constant_iterator>(first); }
    constant_iterator cend() const { return nullptr; }
    iterator begin() { return first; }
    iterator end() { return nullptr; }
    constant_iterator begin() const { return cbegin(); }
    constant_iterator end()   const { return cend(); }

    void cons(const value_type &value) { return push_front(value); }

    void push_front(const value_type &value)
    {
        // construct
        node_type *target = new node_type{value};

        // property
        if ( (target->next = first) != nullptr ) // first != nullptr
            first->prev = target;
        target->prev = nullptr;

        // special
        first = target;
    }

    void insert_before(node_type *node, const value_type &value)
    {
        // construct
        node_type *target = new node_type{value};

        // property
        if ( (target->prev = node->prev) == nullptr ) // node == first
            first = target; // special
        target->next = node;
        node->prev = target;
    }

    void insert_after(node_type *node, const value_type &value)
    {
        // construct
        node_type *target = new node_type{value};

        // property
        if ( (target->next = node->next) != nullptr ) // 要不要改 node->next 的 prev
            node->next->prev = target;
        node->next = target;
        target->prev = node;
    }

    void remove(node_type *node)
    {
        node_type *target = node;
        
        if ( target->next != nullptr ) // 存在 next
            target->next->prev = target->prev;

        if ( target->prev != nullptr ) // 存在 prev
            target->prev->next = target->next;
        else
            first = target->next; // target->next 可以是 null
        
        delete target;
    }

private:
    node_type *first;
};

} // namespace literal