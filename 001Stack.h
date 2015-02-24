#define Type int
struct Node
{
  Type val;
  Node *next;
  Node(Type v):val(v), next(NULL){}
};
class Stack
{
private:
    Node *first;
public:
    Stack(){ 
      first = NULL;
    }

    ~Stack(){
      delete first;
    }

    void push(Type data) {
        Node *newNode = new Node(data);
        newNode->next = first;
        first = newNode;
    }

    void pop(){
        if (!empty())
        {
          Node *tmp = first;
          first = first->next;
          delete tmp;
        }
    }

    Type top() { 
        if (!empty()) return first->val;
        else return -1;
    }

    bool empty() {
      return first ? false : true;
    }
};