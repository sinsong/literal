#pragma once

#include <type_traits>
#include <utility>

namespace literal
{

// 单链表

template <typename Type>
class singly_list_node
{
public:
    using value_type = Type;
    using node_type  = singly_list_node<Type>;

    singly_list_node() = default;
    singly_list_node(value_type &&v, node_type *n): value{std::forward<value_type>(v)}, next{n}
    {}

    value_type value;

    node_type *next;
};

// pointers are always nothrow swappable, so just check the value's type
// Using ADL for swap
template <class Type>
inline void swap(singly_list_node<Type> *x, singly_list_node<Type> *y)
    noexcept(std::is_nothrow_swappable_v<typename singly_list_node<Type>::value_type>)
{
    using std::swap;
    swap(x->next, y->next);
    swap(x->value, y->value);
}

// 双链表

template <typename Type>
class list_node
{
public:
    using value_type = Type;
    using node_type  = list_node<Type>;

    value_type value;

    node_type *prev;
    node_type *next;
};

template <typename Type>
inline void swap(list_node<Type> *x, list_node<Type> *y)
    noexcept(std::is_nothrow_swappable_v<typename list_node<Type>::value_type>)
{

    using std::swap;
    swap(x->prev, y->prev);
    swap(x->next, y->next);
    swap(x->value, y->value);
}

} // namespace literal
