#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct TreapNode
{
	int key;
	int priority;
	struct TreapNode *left;
	struct TreapNode *right;
} TreapNode;

void split(TreapNode *root, TreapNode **left, TreapNode **right, int key);

TreapNode *merge(TreapNode *left, TreapNode *right);

TreapNode *createNode(int key, int priority);

TreapNode *insert(TreapNode *root, int key, int priority);
