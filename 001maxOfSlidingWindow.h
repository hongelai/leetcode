vector<int> maxArray(vector<int> a, int k) {
  deque<int> q;
  vector<int> res;
  int size = a.size();

  for (int i = 0; i < k && i < size; i++) {
    if (q.empty()) q.push_back(a[i]);
    else if (q.back() < a[i]){
      q.pop_back();
      q.push_back(a[i]);
    }
  }

  for (int i = 0; i <= size - k; i++) {
    res.push_back(q.front());
    while(!q.empty() && q.back() < a[i+k]) q.pop_back();
    q.push_back(a[i+k]);
    if (a[i] == q.front()) q.pop_front();
  }
  return res;
}