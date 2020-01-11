    public String simplifyPath(String path) {
        LinkedList<String> s = new LinkedList<>();
        StringBuilder rs = new StringBuilder();
        Set<String> skip = new HashSet<>(Arrays.asList("..",".",""));
        
        for (String item : path.split("/")) {
            if ("..".equals(item) && !s.isEmpty()) {
                s.removeLast();
            } else if (!skip.contains(item)) {
                s.add(item);
            }
        }
        
        for (String item : s) {
            rs.append("/");
            rs.append(item);
        }
        return rs.length() == 0 ? "/" : rs.toString() ;
    }