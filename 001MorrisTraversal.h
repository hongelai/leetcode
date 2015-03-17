void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1.没有左节点，访问当前节点，往右
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur) //节点往下走之后，会通过新添加的右节点线索指针再次访问这个点所以不能 == cur
                prev = prev->right;

            if (prev->right == NULL)   // 2.a) 如果没有添加线索右指针（未visited），添加，往下走
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                       // 2.b) 之前添加过右指针（往下走再次 通过添加的右指针回到同一个点），访问它
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}

void preorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL) //线索右指针是NULL ，表示该节点是第一次访问
            {
                printf("%d ", cur->val);  // the only difference with inorder-traversal
                prev->right = cur;
                cur = cur->left;
            }
            else                     //线索右指针不是NULL，表示是第二次访问
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}