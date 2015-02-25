class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
};
const int TABLE_SIZE = 128;
 
class HashMap {
private:
      HashEntry **table; //table[hash] 就是一个 HashEntry* 个体
public:
      HashMap() {
            table = new HashEntry*[TABLE_SIZE]; //创建HashEntry*类型的数组
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == NULL)
                  return -1;
            else
                  return table[hash]->getValue();
      }
 
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key) //key 已被占用
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] != NULL) //找到了key,而且里面存有东西
                  delete table[hash]; //删去指针
            table[hash] = new HashEntry(key, value); //重新指向
      }     
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }
};