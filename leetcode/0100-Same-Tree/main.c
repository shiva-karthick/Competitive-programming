#include "../../header-files/common.h"
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    /* Base case */
    if (p == NULL || q == NULL)
        return p == q;

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char const *argv[])
{

    return 0;
};
