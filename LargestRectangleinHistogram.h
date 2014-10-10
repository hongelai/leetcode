
    int largestRectangleArea(vector<int> &height) {
       height.push_back(0);
       stack<int> s;
       int N = height.size();
       int result = 0;
       
       for(int i = 0; i < N;){
           if(s.empty() || height[i] > height[s.top()])
                s.push(i++);
            else{
                int tmp = s.top();
                s.pop();
                result = max(result,height[tmp]*(s.empty()?i:i-s.top()-1));
            }
       }
       return result;
    }
    