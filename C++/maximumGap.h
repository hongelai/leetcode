    int maximumGap(vector<int> &num) {
        //drawer theory, put all nums in n+1 drawer, each drawer keep track of its smallest and biggest
        // the max gap will always bigger than Max(num) - Min(num) / (n-1) becasue for n number there will be at most n-1 gap between them when they are distributed evenly
        int size = num.size(), res = 0;
        if (size < 2) return 0;
        int minN = num[0], maxN = num[0];
        for (int i = 0; i < size; i++) {
            minN = min(num[i], minN);
            maxN = max(num[i], maxN);
        }
        // delta = (maxN - minN) / (size - 1);
        // int boxNum = (maxN - minN) / delta + 1; // size + 1
        vector<pair<int, int> > boxes(size + 1, make_pair(-1, -1));
        for (int i = 0; i < size; i++) {
            int index = (long long)(num[i] - minN) * (size - 1) / (maxN - minN); //cast to long to avoid INT_MAX - INT_MIN
            if (boxes[index].first == -1){
                boxes[index] = make_pair(num[i], num[i]);
            } else {
                boxes[index].first = min(boxes[index].first, num[i]);
                boxes[index].second = max(boxes[index].second, num[i]);
            }
        }
        int last = boxes[0].second;
        for (int i = 1; i < size + 1; i++) {
            if (boxes[i].first != -1)
            {
              res = max(boxes[i].first - last, res);
              last = boxes[i].second;
            }
        }
        return res;
    }