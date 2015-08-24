    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int size = intervals.size();
        if(size < 1){
            res.push_back(newInterval);
            return res;
        }
        
        for(int i = 0; i < size; i++){ // do not need to sort it, because it is sorted
            if(newInterval.start > intervals[i].end){ //newInterval is behind
                res.push_back(intervals[i]);
            }else if(newInterval.end < intervals[i].start){ // newInterval is before, 
                res.push_back(newInterval);
                newInterval = intervals[i];  // 完成当前这个newInterval的merge后，更新下个interval作为newInterval, 就可以把剩下的nonoverlap的push进去
            }else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
               
        }
        res.push_back(newInterval);//最后必定会有一个没插入 ，第二个else if只把前一个newInterval 插进去了
        return res;
    }