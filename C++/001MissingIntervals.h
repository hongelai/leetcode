void missingInterval(vector<pair<int, int>> &interval){
    auto  lessthan = [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    };
    sort(interval.begin(),interval.end(),lessthan);
    int start = interval[0].first, end = interval[0].second;
    for(int i = 1; i < interval.size(); i++){
        if(interval[i].first <= end) {
            end = max(end, interval[i].second);
        } else {
            if(end + 1 < interval[i].first) cout<<end+1<<" ---"<<interval[i].first-1<<endl;
            start = interval[i].first;
            end = interval[i].second;
        }
    }
}