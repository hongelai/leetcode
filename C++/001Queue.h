#define Type int

struct Node
{
  Type val;
  Node *next;
  Node(Type v):val(v),next(NULL){}
};

class Queue
{
private:
    Node *first, *rear;
public:
    Queue(){
        first = rear = NULL;
    }
    ~Queue(){ 
         delete first;
         delete rear;
    }

    void enqueue(Type data) {
        Node *newNode = new Node(data);
        if (first == NULL)
        {
            first = rear = newNode;
        } else {
            rear->next = newNode;
            rear = rear->next;
        }
    }

    void dequeue() {
        if (!empty())
        {
            Node *tmp = first;
            first = first->next;
            if (first == NULL) rear = NULL;
            delete tmp;
        }
    }

    Type front(){
        return first->val;
    }

    bool empty() {
        return first == NULL ? true : false;
    }
};