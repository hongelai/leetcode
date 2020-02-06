/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf); 
 */
public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        int index = 0;
        while (index < n) {
            if (readPos == count) { // all buf in tmp are read
                count = read4(tmp);
                readPos = 0;
                if (count == 0) break;
            }
            buf[index++] = tmp[readPos++];
        }
        return index;
    }
    
    private char[] tmp = new char[4];
    private int readPos =  0, count = 0;
}