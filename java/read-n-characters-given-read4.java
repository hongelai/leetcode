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
        char[] tmp = new char[4];
        int count = 0, index = 0;
        
        while ((count = read4(tmp)) > 0) {
            for (int i = 0; i < count && index < n; i++) {
                buf[index++] = tmp[i];
            }
        }
        
        return index;
     }
}