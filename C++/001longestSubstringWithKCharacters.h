string distinctKChars(string s, int k) {
  int len = s.length();
  int count = 0, start = 0, end = 0, set[256] = {0};
  string res = "";
  if (len <= k) return s;

  while (end < len && start + res.length() < len) {
      set[s[end]]++;
      if (set[s[end]] == 1)
      {
          count++;
          while (start < end && count > k) {
              set[s[start]]--;
              if (set[s[start]] == 0) count--;
              start++;
          }
      } 
      if (res.length() < end - start + 1)
      {
          res = s.substr(start, end - start + 1);
      }
      end++;
  }
  return res;
}

//cdde is not test