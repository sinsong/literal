#pragma once

#include "literal/debug.h"
#include "literal/list/node.h"

namespace literal
{

template <typename Type>
class singly_tailq
{
public:
    using value_type = Type;
    using node_type = list_node<Type>;
    using iterator = node_type*;
    using constant_iterator = const node_type*;

    singly_tailq()
        : first(nullptr),
          last(nullptr){}
    
    ~singly_tailq()
    {
        node_type *target;

        while(first != nullptr)
        {
            target = first;     // cache
            first = first->next; // read
            delete target;     // delete
        }
    }

    bool empty() const { return first == nullptr; }

    constant_iterator cbegin() const { return const_cast<constant_iterator>(first); }
    constant_iterator cend() const { return nullptr; }
    iterator begin() { return first; }
    iterator end() { return nullptr; }
    constant_iterator begin() const { return cbegin(); }
    constant_iterator end()   const { return cend(); }

    node_type *_last() const { return last; }

    void cons(const value_type &value) { return push_front(value); }
    void push(const value_type &value) { return push_back(value); }

    // TODO: pull & pop
    value_type pull() = delete;
    value_type pop() { remove_head(); }

    void push_front(const value_type &value)
    {
        node_type *target = new node_type;
        target->value = value;

        // 空列表
        if ( (target->next = first) == NULL )
            last = target;

        first = target;
    }

    void push_back(const value_type &value)
    {
        node_type *target = new node_type;
        target->value = value;

        target->next = nullptr;
        if (last)
            last->next = target; 
        else
            first = target; // special
        last = target; // special
    }

    void insert_after(node_type *node, const value_type &value)
    {
        node_type *target = new node_type;
        target->value = value;

        // node == last
        if ( (target->next = node->next) == nullptr )
            last = target;
        node->next = target;
    }

    void remove(node_type *node)
    {
        if(first == node)
            return remove_head();
        else
        {
            // TODO: 没找到真的要爆炸？
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
        if ( (node->next = target->next) == nullptr)
            last = node->next;
        delete target;
    }

    void remove_head()
    {
        node_type *target = first;
        if ((first = target->next) == nullptr)
            last = first;
        delete target;
    }

private:
    node_type *first;
    node_type *last;
};

} // namespace literal