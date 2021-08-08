#pragma once

#include <utility>

namespace literal
{

// 单链表

template <typename Type>
class singly_list_node
{
public:
    typedef Type                   value_type;
    typedef singly_list_node<Type> node_type;

    value_type value;

    node_type *next;
};

template <class Type>
inline void swap(singly_list_node<Type> *x, singly_list_node<Type> *y)
{
    singly_list_node<Type> *tempptr = x->next;
    x->next = y->next;
    y->next = tempptr;

    std::swap(x->value, y->value);
}

// 双链表

template <typename Type>
class list_node
{
public:
    typedef Type            value_type;
    typedef list_node<Type> node_type;

    value_type value;

    node_type *prev;
    node_type *next;
};

template <typename Type>
inline void swap(list_node<Type> *x, list_node<Type> *y)
{

    list_node<Type> *tempprev = x->prev;
    x->prev = y->prev;
    y->prev = tempprev;
    
    list_node<Type> *tempnext = x->next;
    x->next = y->next;
    y->next = tempnext;

    std::swap(x->value, y->value);
}

} // namespace literal
