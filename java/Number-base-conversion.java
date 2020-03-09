    char[] index = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
        'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'};

    public int getValue(char c) {
        if (c <= '9') return c-'0';
        else if (c <= 'Z') return c-'A' + 10;
        else if (c <= 'z') return c-'a' + 36;

        return -1;
    }

    /**
     * Divide m base string by n, get a new m base string which is quotient, 
     * the remainder of each iteration is a bit in n base.
     * eg. 2 base to 3 base
     * 1011 -> 0011 remainder 2
     * 0011 -> 0001 remainder 0
     * 0001 -> 0000 remainder 1
     *
     * so answer to 3 base is 102
     */
    public String baseConversion(String s, int m, int n) {
        String res= "";

        while (s.length()!= 0) {
            int remain = 0;
            String tmp = "";

            //from higher bit to lower bit
            for (int i = 0; i < s.length(); i++) {
                remain = remain * m + getValue(s.charAt(i));

                if (remain < n) {
                    tmp = tmp + "0";
                    continue;
                }
                else {
                    tmp = tmp + index[remain/n];
                    remain %= n;
                }
            }

            //put final remainder in each iteration in to result
            res = index[remain] + res;

            //trim preceding 0s
            int pos = 0;
            for (; pos < tmp.length() && tmp.charAt(pos) == '0'; pos++);
            s = tmp.substring(pos);
        }
        return res;
    }
