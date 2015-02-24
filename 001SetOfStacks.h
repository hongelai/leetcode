//cc 3.3
#define SIZE 10
class SetStack
{
    private:
        int capacity;
        int index;
        vector<stack<int> > sk;
    public:
        SetStack(int capa = SIZE){
            capacity = capa;
            index = 0;
            sk.push_back(stack<int>());
        }

        ~SetStack(){
          sk.clear();
        }

        void push(int d) {
          stack<int> tmp = sk[index];
          if (tmp.size() == capacity)
          {

            sk.push_back(stack<int>());
            index++;
          }

          sk[index].push(d);
        }

        void pop(){
          stack<int> tmp = sk[index];
          if(tmp.size() == 0 && index > 0){
            sk.erase(sk.begin() + index);
            index--;
          }
          
          sk[index].pop();
          
        }

        int top(){
          if (sk[index].size() == 0 && index > 0)
          {
            sk.erase(sk.begin() + index);
            index--;
          }
          return sk[index].top();
        }
        
        bool empty() {
          if (index == 0 && sk[index].size() == 0)
          {
            return true;
          } else {
            return false;
          }
        }
        void popAt(int idx) {
          while (sk[idx].empty() && index > 0)
          {
            sk.erase(sk.begin() + idx);
            index--;
          }
          sk[idx].pop();
        }
        stack<int> getStack(int idx) {
          return sk[idx];
        }
        int getStackSize(int idx) {
          return sk[idx].size();
        }
        int getSize() {
          return sk.size();
        }
};