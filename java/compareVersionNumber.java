public class Solution {
    public int compareVersion(String version1, String version2) {
      int l1 = version1.length(), l2 = version2.length();
      int i1 = 0, i2 = 0;
      while (i1 < l1 || i2 < l2) {
          int a = 0, b= 0;
          while (i1 < l1 && version1.charAt(i1) != '.') a = a*10 + version1.charAt(i1++) - '0';
          while (i2 < l2 && version2.charAt(i2) != '.') b = b*10 + version2.charAt(i2++) - '0';
          if (a > b) return 1;
          else if (a < b) return -1;
          else {
              i1++;
              i2++;
          }
      }
      return 0;
        
    }
    
    public int compareVersion1(String version1, String version2) {
        String[] a = version1.split("\\.");
        String[] b = version2.split("\\.");
        int l1 = a.length, l2 = b.length;
        int i = 0;
        while (i < l1 || i < l2) {
            int v1 = i < l1 ? Integer.parseInt(a[i]) : 0;
            int v2 = i < l2 ? Integer.parseInt(b[i]) : 0;
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            else {
                i++;
            }
        }
        return 0;
    }
}