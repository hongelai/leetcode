// recurisve
public void preorder(TreeNode root) {
    if (root != null) {
        visit(root);
        preorder(root.left, res);
        preorder(root.right, res);
    }
} 

public void inorder(TreeNode root) {
    if (root != null) {
        inorder(root.left, res);
        visit(root);
        inorder(root.right, res);
    }
}

public void postOrder(TreeNode root) {
    if (root != null) {
	    postOrder(root.left, rs);
	    postOrder(root.right, rs);
	    visit(root);
	}
}

// iterative
public void preorder(TreeNode root) {
    Stack<TreeNode> stack = new Stack<>();
    TreeNode cur = root;
    
    while (cur != null || !stack.isEmpty()) {
        if (cur != null) {
            visit(cur);
            stack.push(cur);
            cur = cur.left;
        } else {
            cur = stack.pop();
            cur = cur.right;
        }
    }
}

public void inorder(TreeNode root) {
    Stack<TreeNode> stk = new Stack<>();
    TreeNode cur = root;
    
    while (cur != null || !stk.isEmpty()) {
        if (cur != null) {
            stk.push(cur);
            cur = cur.left;
        } else {
            cur = stk.pop();
            visit(cur);
            cur = cur.right;
        }
    }
}

public void postOrder(TreeNode root) {
    Stack<TreeNode> stk = new Stack<>();
    TreeNode cur = root;
    TreeNode lastVisited = null;
    
    while (cur != null || !stk.isEmpty()) {
        if (cur != null) {
            stk.push(cur);
            cur = cur.left;
        }
        else {
            TreeNode node = stk.peek();
            if (node.right != null && node.right != lastVisited) {
                cur = node.right;
            }
            else {
                visit(node);
                lastVisited = stk.pop();
            }
        }
    }
}

// Morris
public void preorder(TreeNode root) {
    TreeNode cur = root, pre = null;
    
    while (cur != null) {
        if (cur.left == null) { //leftmost
            visit(cur);
            cur = cur.right;
        }
        else {
            // find the rightmost node as predecessor and connect it
            pre = cur.left;
            while (pre.right != null && pre.right != cur) { //cannot == cur because it may already be connect
                pre = pre.right;
            }
            
            if (pre.right == null) { // not connect
            	visit(cur); // the only difference between inorder traversal
                pre.right = cur;
                cur = cur.left;
            }
            else { // already connect, which means it is second visit and we returning from leaf. revert connection to recover to original tree
                pre.right = null;
                cur = cur.right;
            }
        }
    }
}

public void inorder(TreeNode root) {
    TreeNode cur = root, pre = null;
    
    while (cur != null) {
        if (cur.left == null) { //leftmost
            visit(cur);
            cur = cur.right;
        }
        else {
            // find the rightmost node as predecessor and connect it
            pre = cur.left;
            while (pre.right != null && pre.right != cur) { //cannot == cur because it may already be connect
                pre = pre.right;
            }
            
            if (pre.right == null) { // not connect
                pre.right = cur;
                cur = cur.left;
            }
            else { // already connect, which means it is second visit and we returning from leaf. revert connection to recover to original tree
                pre.right = null;
                visit(cur);
                cur = cur.right;
            }
        }
    }
}

//https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html

