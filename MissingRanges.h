/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, 
return its missing ranges. For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, 
return ["2", "4->49", "51->74", "76->99"].
*/

string makeRange(int from, int to) {
  ostringstream ss;
  if (from < to)
  {
    ss<<from<<"->";
  }
  ss<<to;
  return ss.str();
}
vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
  vector<string> res;
  for (int i = 0; i < n && lower <= upper &&  A[i] <= upper; ++i)
  {   //lower-->A[i]-1
      if (A[i] > lower)
      {
          res.push_back(makeRange(lower, A[i] - 1));
          lower = A[i] + 1;
      } else if (A[i] == lower)
      {
         lower++;
      }
  }
  if (lower <= upper)
  {
    res.push_back(makeRange(lower, upper));
  }
}