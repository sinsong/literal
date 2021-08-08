#include <gtest/gtest.h>
#include "literal/list/tailq.h"

// TEST(TailQTest, )

TEST(TailQTest, ConstructTest)
{
    ASSERT_NO_FATAL_FAILURE({
       literal::tailq<int> tailq; 
    });
}

TEST(TailQTest, ConsTest)
{
    literal::tailq<int> tailq;
    ASSERT_NO_FATAL_FAILURE({
        tailq.cons(5);
        tailq.cons(4);
        tailq.cons(3);
        tailq.cons(2);
        tailq.cons(1);

        printf("first: %p | last: %p\n", tailq.begin(), tailq._last());
        for (auto curr = tailq.begin() ; curr ; curr = curr->next)
        {
            printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
        }
    });
}

TEST(TailQTest, OrderTest)
{
    literal::tailq<int> tailq;
    tailq.cons(5);
    tailq.cons(4);
    tailq.cons(3);
    tailq.cons(2);
    tailq.cons(1);

    auto curr = tailq.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { curr = curr->next; }

    ASSERT_EQ(curr->value, 3);
}

TEST(TailQTest, RemoveTest)
{
    literal::tailq<int> tailq;
    tailq.cons(5);
    tailq.cons(4);
    tailq.cons(3);
    tailq.cons(2);
    tailq.cons(1);

    auto three = tailq.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { three = three->next; }

    tailq.remove(three);

    printf("first: %p | last: %p\n", tailq.begin(), tailq._last());
    for (auto curr = tailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(TailQTest, RemoveFirstTest)
{
    literal::tailq<int> tailq;
    tailq.cons(5);
    tailq.cons(4);
    tailq.cons(3);
    tailq.cons(2);
    tailq.cons(1);

    tailq.remove(tailq.begin());

    printf("first: %p | last: %p\n", tailq.begin(), tailq._last());
    for (auto curr = tailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(TailQTest, RemoveLastTest)
{
    literal::tailq<int> tailq;
    tailq.cons(5);
    tailq.cons(4);
    tailq.cons(3);
    tailq.cons(2);
    tailq.cons(1);

    tailq.remove(tailq._last());

    printf("first: %p | last: %p\n", tailq.begin(), tailq._last());
    for (auto curr = tailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | prev: %p | next: %p\n", curr->value, curr, curr->prev, curr->next);
    }
}

TEST(TailQTest, NullTest)
{
    ASSERT_NO_FATAL_FAILURE({
        literal::tailq<int> tailq;
        tailq.push_front(1);
    });
    ASSERT_NO_FATAL_FAILURE({
        literal::tailq<int> tailq;
        tailq.push_front(1);
    });
}

TEST(TailQTest, InsertRemoveTest)
{
    literal::tailq<int> tailq;

    tailq.push_back(1);
    tailq.push_back(2);

    printf("here");

    // ASSERT_NO_FATAL_FAILURE({
        tailq.remove(tailq.begin());
        tailq.remove(tailq.begin());
    // });
}