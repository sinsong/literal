#pragma once

#include "literal/debug.h"
#include "literal/list/node.h"

namespace literal
{

template <typename Type>
class singly_list
{
public:
    using value_type = Type;
    using node_type  = singly_list_node<Type>;
    using iterator = node_type*;
    using constant_iterator = const node_type*;

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

    constant_iterator cbegin() const { return const_cast<constant_iterator>(first); }
    constant_iterator cend() const { return nullptr; }
    iterator begin() { return first; }
    iterator end() { return nullptr; }
    constant_iterator begin() const { return cbegin(); }
    constant_iterator end()   const { return cend(); }

    void cons(const value_type &value) { return insert_head(value); }
    void cons(value_type &&value) { return insert_head(std::forward<value_type>(value)); }

    void insert_head(const value_type &value)
    {
        node_type *target = new node_type{value, first};
        first = target;
    }

    void insert_head(value_type &&value)
    {
        node_type *target = new node_type{std::forward<value_type>(value), first};
        first = target;
    }

    void insert_after(node_type *node, const value_type &value)
    {
        node_type *target = new node_type{value, node->next};
        node->next = target;
    }

    void insert_after(node_type *node, value_type &&value)
    {
        node_type *target = new node_type{std::forward<value_type>(value), node->next};
        node->next = target;
    }

    void remove(node_type *node)
    {
        if(first == node)
            return remove_head();
        node_type *curr = first;
        while (curr != nullptr && curr->next != node)
            curr = curr->next;
        if (!curr) {
            return;
        }
        return remove_after(curr);
        
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
