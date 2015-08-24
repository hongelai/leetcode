    vector<Interval> merge(vector<Interval> &intervals) {
        int size = intervals.size();
        vector<Interval> res;
        if(size < 1) return res;
        
        auto lessthan = [](Interval a, Interval b)->bool{return a.start < b.start;};
        
        sort(intervals.begin(),intervals.end(),lessthan);
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 0; i < size; i++){
            if(intervals[i].start <= end){
                end = max(end, intervals[i].end);
            }else{
                res.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        res.push_back(Interval(start,end));
        
        return res;
    }