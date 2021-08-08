#include <gtest/gtest.h>
#include "literal/list/singly_tailq.h"

// TEST(SinglyTailQTest, )

TEST(SinglyTailQTest, ConstructTest)
{
    ASSERT_NO_FATAL_FAILURE({
        literal::singly_tailq<int> stailq;
    });
}

TEST(SinglyTailQTest, ConsTest)
{
    literal::singly_tailq<int> stailq;
    ASSERT_NO_FATAL_FAILURE({
        stailq.cons(5);
        stailq.cons(4);
        stailq.cons(3);
        stailq.cons(2);
        stailq.cons(1);

        printf("first: %p | last: %p\n", stailq.begin(), stailq._last());
        for (auto curr = stailq.begin() ; curr ; curr = curr->next)
        {
            printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
        }
    });
}

TEST(SinglyTailQTest, OrderTest)
{
    literal::singly_tailq<int> stailq;
    stailq.cons(5);
    stailq.cons(4);
    stailq.cons(3);
    stailq.cons(2);
    stailq.cons(1);

    auto curr = stailq.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { curr = curr->next; }

    ASSERT_EQ(curr->value, 3);
}

TEST(SinglyTailQTest, RemoveTest)
{
    literal::singly_tailq<int> stailq;
    stailq.cons(5);
    stailq.cons(4);
    stailq.cons(3);
    stailq.cons(2);
    stailq.cons(1);

    auto three = stailq.begin();
    for (int _ = 0 ; _ < 2 ; ++_) { three = three->next; }

    stailq.remove(three);

    printf("first: %p | last: %p\n", stailq.begin(), stailq._last());
    for (auto curr = stailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

TEST(SinglyTailQTest, RemoveFirstTest)
{
    literal::singly_tailq<int> stailq;
    stailq.cons(5);
    stailq.cons(4);
    stailq.cons(3);
    stailq.cons(2);
    stailq.cons(1);

    stailq.remove(stailq.begin());

    printf("first: %p | last: %p\n", stailq.begin(), stailq._last());
    for (auto curr = stailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

TEST(SinglyTailQTest, RemoveLastTest)
{
    literal::singly_tailq<int> stailq;
    stailq.cons(5);
    stailq.cons(4);
    stailq.cons(3);
    stailq.cons(2);
    stailq.cons(1);

    stailq.remove(stailq._last());

    printf("first: %p | last: %p\n", stailq.begin(), stailq._last());
    for (auto curr = stailq.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

TEST(SinglyTailQTest, NullTest)
{
    ASSERT_NO_FATAL_FAILURE({
        literal::singly_tailq<int> stailq;
        stailq.push_front(1);
    });
    ASSERT_NO_FATAL_FAILURE({
        literal::singly_tailq<int> stailq;
        stailq.push_back(1);
    });
}

TEST(SinglyTailQTest, InsertRemoveTest)
{
    literal::singly_tailq<int> stailq;

    stailq.push_back(1);
    stailq.push_back(2);

    ASSERT_NO_FATAL_FAILURE({
        stailq.remove_head();
        stailq.remove_head();
    });
}