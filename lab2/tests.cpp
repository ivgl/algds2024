#include <iostream>
#include "gtest/gtest.h"

extern "C"
{
#include "treap.h"
}

// Первый тест - прорсто добавление корня
TEST(TreapTest, Insert_InsertSingleNodeToEmptyTree_ValidTree)
{
	TreapNode *root = nullptr;
	root = insert(root, 5, 10);
	EXPECT_EQ(root->key, 5);
	EXPECT_EQ(root->priority, 10);
	EXPECT_EQ(root->left, nullptr);
	EXPECT_EQ(root->right, nullptr);
}

// Второй тест на добавление нескольких данных
TEST(TreapTest, Insert_InsertMultipleNodes_ValidTree)
{
	TreapNode *root = nullptr;
	root = insert(root, 5, 10);
	root = insert(root, 3, 15);
	root = insert(root, 7, 5);

	// Вершиной должен стать узел 3,15 из-за наибольшего приоритета
	EXPECT_EQ(root->key, 3);
	EXPECT_EQ(root->priority, 15);
	EXPECT_EQ(root->left, nullptr);
	EXPECT_NE(root->right, nullptr);

	// Затем справа должен быть 5,10
	EXPECT_EQ(root->right->key, 5);
	EXPECT_EQ(root->right->priority, 10);
	EXPECT_EQ(root->right->left, nullptr);
	EXPECT_NE(root->right->right, nullptr);

	// И еще правее 7,5
	EXPECT_EQ(root->right->right->key, 7);
	EXPECT_EQ(root->right->right->priority, 5);
	EXPECT_EQ(root->right->right->left, nullptr);
	EXPECT_EQ(root->right->right->right, nullptr);
}

// Тест на разрезание
TEST(TreapTest, Split_SplitTree_ValidSplit)
{
	TreapNode *root = nullptr;
	root = insert(root, 5, 10);
	root = insert(root, 3, 15);
	root = insert(root, 7, 5);

	TreapNode *left = nullptr;
	TreapNode *right = nullptr;
	split(root, &left, &right, 5);

	// Так как режем по ключу 5, слева будет 3, справа 7
	EXPECT_EQ(left->key, 3);
	EXPECT_EQ(left->priority, 15);
	EXPECT_EQ(right->key, 7);
	EXPECT_EQ(right->priority, 5);
}

// Тест на соединение
TEST(TreapTest, Merge_MergeTrees_ValidMerge)
{
	// Первый ключ будет вида, что корень - 5,10 , а левый сын 3,7
	TreapNode *root1 = nullptr;
	root1 = insert(root1, 5, 10);
	root1 = insert(root1, 3, 7);

	// Второй ключ будет вида, что корень - 8,20, а левый сын 7,5
	TreapNode *root2 = nullptr;
	root2 = insert(root2, 7, 5);
	root2 = insert(root2, 8, 20);

	TreapNode *merged = merge(root1, root2);

	// На первом шаге соединения, наверх встанет число с наибольшим приоритетом, то есть 8,20
	EXPECT_EQ(merged->key, 8);
	EXPECT_EQ(merged->priority, 20);

	// Затем слева встанет 5,10
	EXPECT_EQ(merged->left->key, 5);
	EXPECT_EQ(merged->left->priority, 10);

	// И последние сыновья разделятся по размерам ключа
	EXPECT_EQ(merged->left->right->key, 7);
	EXPECT_EQ(merged->left->right->priority, 5);
	EXPECT_EQ(merged->left->left->key, 3);
	EXPECT_EQ(merged->left->left->priority, 7);
}
