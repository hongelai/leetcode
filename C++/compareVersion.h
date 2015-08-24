vector<int> split(string source, char del){
    int index = 0,pos = -1;
    vector<int> res;
    while((pos = source.find('.',index)) != -1){
        res.push_back(stoi(source.substr(index,pos-index)));
        index = pos + 1;
    }
    res.push_back(stoi(source.substr(index)));
    return res;
}
int compareVersion(string version1, string version2) {
        
        vector<int> v1,v2;
        v1 = split(version1,'.');
        v2 = split(version2,'.');
        int i = 0;
        for(;i < v1.size() || i < v2.size(); i++){
            int a = (i >= v1.size() ? 0: v1[i]);
            int b = (i >= v2.size() ? 0: v2[i]);
            if(a > b) return 1;
            else if(a < b) return -1;
            
        }
        return 0;
        
    }

int compareVersion(string version1, string version2) {
    int result = 0;
    char *vStr1 = (char*) version1.c_str();
    char *vStr2 = (char*) version2.c_str();

    while (result == 0 && (*vStr1 != '\0' || *vStr2 != '\0')) {
        long v1 = *vStr1 == '\0' ? 0 : strtol(vStr1, &vStr1, 10);
        long v2 = *vStr2 == '\0' ? 0 : strtol(vStr2, &vStr2, 10);
        if (v1 > v2) result = 1;
        else if (v2 > v1) result = -1;
        else {
            if (*vStr1 != '\0') vStr1++;
            if (*vStr2 != '\0') vStr2++;
        }
    }        

    return result;
}