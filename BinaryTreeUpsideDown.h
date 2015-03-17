public TreeNode UpsideDownBinaryTree(TreeNode root) {
   TreeNode p = root, parent = null, parentRight = null;
   while (p != null) {
      TreeNode left = p.left;//把当前节点的左节点作为下个节点保存下来作为next指针，接下来把p和p.right单独提取出来赋值构建树
      p.left = parentRight;   //把原始的树中p的父节点的右节点作为p的新左节点
      parentRight = p.right;  //把p.right保存下来给后面节点用（p->next）
      p.right = parent;       //把p的原始树中的parent作为p的右节点
      parent = p;             //update p 作为parent
	  p = left;                //move on to next
	}
   	return parent;
}

public TreeNode UpsideDownBinaryTree(TreeNode root) {
   return dfsBottomUp(root, null);
}
private TreeNode dfsBottomUp(TreeNode p, TreeNode parent) {
   if (p == null) return parent;
   TreeNode root = dfsBottomUp(p.left, p);
   p.left = (parent == null) ? parent : parent.right; //把parent 和 parent的右节点 作为孩子， 返回上一级再去取parent的parent和和parent.right作为子节点
   p.right = parent;
   return root;//最后一个节点就是根节点，所以一路返回
}