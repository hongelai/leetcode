    int maxPoints(vector<Point> &points) {
        unordered_map<double, int> map;
        int size = points.size();
        if(size < 3) return size;
        int samePoint = 0, sameSlope = 0, res = 0;
        
        for (int i = 0; i < size; i++) {
            map.clear();
            samePoint = 0;
            sameSlope = 0;
            
            for(int j = i + 1; j < size; j++){
                double slope = numeric_limits<double>::infinity();
                if(points[i].x != points[j].x){
                    slope = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                } else {
                    if(points[i].y == points[j].y){
                        samePoint++;
                        continue;
                    } 
                }
                map[slope]++;
                sameSlope = max(sameSlope, map[slope]);
            }
            res = max(res, sameSlope + samePoint + 1);//add the point itself and sameSlope, samePoiont count
        }
        return res;
    }