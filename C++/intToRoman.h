    string intToRoman(int num) {
        //左加只能一位，所以下面这个组合能组成任何数字
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        
        for(int i = 0;num>0; i++){   
            int count = num / value[i];
            num %= value[i];
            while(count>0){
                res += symbol[i];
                count--;
            }
        }
        return res;
    }