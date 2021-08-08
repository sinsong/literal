#include <cstdio>

#include <gtest/gtest.h>
#include "literal/list/singly_list.h"

// TEST(SinglyListTest, )

// 能构造
TEST(SinglyListTest, ConstructTest)
{
    ASSERT_NO_FATAL_FAILURE({
        literal::singly_list<int> slist;
    });
}

// 添加数据
TEST(SinglyListTest, ConsTest)
{
    literal::singly_list<int> slist;
    ASSERT_NO_FATAL_FAILURE({
        slist.cons(5);
        slist.cons(4);
        slist.cons(3);
        slist.cons(2);
        slist.cons(1);

        printf("head: %p\n", slist.begin());
        for (auto curr = slist.begin() ; curr ; curr = curr->next)
        {
            printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
        }
    });
}

// 顺序
TEST(SinglyListTest, OrderTest)
{
    literal::singly_list<int> slist;
    slist.cons(5);
    slist.cons(4);
    slist.cons(3);
    slist.cons(2);
    slist.cons(1);

    auto curr = slist.begin();
    for (int _ = 0; _ < 2 ; ++_) { curr = curr->next; }

    ASSERT_EQ(curr->value, 3);
}

// 删除 中间的
TEST(SinglyListTest, RemoveTest)
{
    literal::singly_list<int> slist;
    slist.cons(5);
    slist.cons(4);
    slist.cons(3);
    slist.cons(2);
    slist.cons(1);

    auto three = slist.begin();
    for (int _ = 0; _ < 2 ; ++_) { three = three->next; }

    slist.remove(three);

    printf("head: %p\n", slist.begin());
    for (auto curr = slist.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

// 删除 第一个
TEST(SinglyListTest, RemoveFirstTest)
{
    literal::singly_list<int> slist;
    slist.cons(5);
    slist.cons(4);
    slist.cons(3);
    slist.cons(2);
    slist.cons(1);

    slist.remove(slist.begin());

    printf("head: %p\n", slist.begin());
    for (auto curr = slist.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

// 删除 最后一个
TEST(SinglyListTest, RemoveLastTest)
{
    literal::singly_list<int> slist;
    slist.cons(5);
    slist.cons(4);
    slist.cons(3);
    slist.cons(2);
    slist.cons(1);

    auto last = slist.begin();
    for (int _ = 0; _ < 4 ; ++_) { last = last->next; }
    ASSERT_EQ(last->next, nullptr);

    slist.remove(last);

    printf("head: %p\n", slist.begin());
    for (auto curr = slist.begin() ; curr ; curr = curr->next)
    {
        printf("value: %d | curr: %p | next: %p\n", curr->value, curr, curr->next);
    }
}

// 空容器修改操作
TEST(SinglyListTest, NullTest)
{
    // 就是 cons 么
    ASSERT_NO_FATAL_FAILURE({
        literal::singly_list<int> slist;
        slist.insert_head(1);
    });

    ASSERT_NO_FATAL_FAILURE({
        literal::singly_list<int> slist;
        slist.remove_head();
    });
}

// 删除比增加多
TEST(SinglyListTest, InsertRemoveTest)
{
    literal::singly_list<int> slist;

    slist.cons(1);
    slist.cons(2);

    slist.remove_head();
    slist.remove_head();

    ASSERT_NO_FATAL_FAILURE({
        slist.remove_head();
    });
}