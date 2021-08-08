#include <gtest/gtest.h>
#include "literal/list/list.h"

// TEST(ListTest, )

TEST(ListTest, ConstructTest)
{
    ASSERT_NO_FATAL_FAILURE({
       literal::list<int> list;
    });
}

TEST(ListTest, ConsTest)
{
    literal::list<int> list;
    ASSERT_NO_FATAL_FAILURE({
        list.cons(5);
        list.cons(4);
        list.cons(3);
        list.cons(2);
        list.cons(1);

        printf("head: %p\n", list.begin());
        for (auto curr = list.begin() ; curr ; curr = curr->next)
        {
            printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
        }
    });
}

TEST(ListTest, OrderTest)
{
    literal::list<int> list;
    list.cons(5);
    list.cons(4);
    list.cons(3);
    list.cons(2);
    list.cons(1);

    auto curr = list.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { curr = curr->next; }

    ASSERT_EQ(curr->value, 3);
}

TEST(ListTest, RemoveTest)
{
    literal::list<int> list;
    list.cons(5);
    list.cons(4);
    list.cons(3);
    list.cons(2);
    list.cons(1);

    auto three = list.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { three = three->next; }

    list.remove(three);

    printf("head: %p\n", list.begin());
    for (auto curr = list.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(ListTest, RemoveFirstTest)
{
    literal::list<int> list;
    list.cons(5);
    list.cons(4);
    list.cons(3);
    list.cons(2);
    list.cons(1);

    list.remove(list.begin());

    printf("head: %p\n", list.begin());
    for (auto curr = list.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(ListTest, RemoveLastTest)
{
    literal::list<int> list;
    list.cons(5);
    list.cons(4);
    list.cons(3);
    list.cons(2);
    list.cons(1);

    auto last = list.begin();
    for (int _ = 0 ; _ < 4 ; ++_) { last = last->next; }

    list.remove(last);

    printf("head: %p\n", list.begin());
    for (auto curr = list.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(ListTest, NullTest)
{
    ASSERT_NO_FATAL_FAILURE({
        literal::list<int> list;
        list.cons(1);
    });
}

TEST(ListTest, InsertRemoveTest)
{
    literal::list<int> list;

    list.cons(1);
    list.cons(2);

    ASSERT_NO_FATAL_FAILURE({
        list.remove(list.begin());
        list.remove(list.begin());
    });
}