//难点在于random pointer的复制，可能指向未来的节点，所以要先把链表复制 然后赋值random pointer。
//但是两个链表的的同一个节点的random pointer指向的地址是不同的，所以要在原来的链表上插入构造新的链表