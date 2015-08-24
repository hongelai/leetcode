    uint32_t reverseBits(uint32_t n) {
        int size = sizeof(n) * 8;
        uint32_t ret = 0;
        for (int i = 1; i <= size; i++) {
            ret |= (n & 1) << (size - i);
            n = n >> 1; 
        }
        return ret;
    }