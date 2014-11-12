    bool isPalindrome(int x) {
        if(x < 0) return false;
        int h = 1;
        while(x/h >= 10) h *= 10; //calculate high divider
        
        while(x > 0){
            int high = x / h;
            int low = x % 10;
            if(high != low) return false;
            x %= h;
            x /= 10;
            h /= 100;
        }
        return true;
    }