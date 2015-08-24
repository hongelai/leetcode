    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        int N = s.size();
        int inc = (nRows-1)*2;
        string res="";
        
        for(int i = 0; i < nRows; i++){
            int j = 0;
            while(true){   //要是 J< N 就可能会跳过 最后的斜线的点
                if(i>0 && i < nRows-1 && j-i > 0 && j-i < N)  //处理斜线 转折点留给竖线处理
                    res+=s[j-i];
                if(j+i < N)
                    res+=s[j+i];
                if(j+i >= N) break;
                j+=inc;
            }
        }
        return res;
    }