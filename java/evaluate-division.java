class Solution {
    class Node {
        String parent;
        double ratio; //distance to parent;
        
        Node (String p, double r) {
            this.parent = p;
            this.ratio = r;
        }
    }
    
    class UnionFind {
        HashMap<String, Node> parents = new HashMap<>();
        
        public Node find(String x) {
            if (!parents.containsKey(x)) return null;
            
            Node n = parents.get(x);
            if (!x.equals(n.parent)) {
                Node p = find(n.parent);
                n.parent = p.parent;
                n.ratio *= p.ratio;
            }
            
            return n;
        }
        
        /*
            Union 的策略
            s -> p 
            1. 如果s 和p 都不存在， 那么p给根节点，根节点同时需要指向自己
               否则，query是（p， p） 就查不到
            2. s 存在，p 不存在， 那么把p反过来挂到s下面就算union了，值就是
               1/ratio
            3. s 不存在，p 存在，直接挂
            4. s 和 p 都在，各自找到根，把s的根rS挂到p下面
               s->rS = r1, p->rP = r2, s->p = ratio
               那么 rS -> s -> p -> rP = 1/r1 * r2 * ratio
        */
        public void union(String s, String p, Double ratio) {
            boolean hasS = parents.containsKey(s);
            boolean hasP = parents.containsKey(p);
            
            if (!hasS && !hasP) {
                parents.put(s, new Node(p, ratio));
                parents.put(p, new Node(p, 1.0));
            } else if (!hasP) {
                parents.put(p, new Node(s, 1.0 / ratio));
            } else if (!hasS) {
                parents.put(s, new Node(p, ratio));
            } else {
                Node rS = find(s);
                Node rP = find(p);
                rS.parent = rP.parent;
                rS.ratio = ratio / rS.ratio * rP.ratio;
             }
        }
    }
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        UnionFind uf = new UnionFind();
        double[] res = new double[queries.size()];
        
        for (int i = 0; i < values.length; i++) {
            List<String> e = equations.get(i);
            uf.union(e.get(0), e.get(1), values[i]);
        }
        
        for (int i = 0; i < queries.size(); i++) {
            String x = queries.get(i).get(0);
            String y = queries.get(i).get(1);
            Node xr = uf.find(x);
            Node yr = uf.find(y);
            
            if (xr == null || yr == null || !xr.parent.equals(yr.parent))  res[i] = -1.0;
             else res[i]= xr.ratio/yr.ratio;
        }
        
        return res;
    }
    
    
    
    
    
    HashMap<String, HashMap<String, Double>> map = new HashMap<>();
    
    public double[] calcEquation_dfs(List<List<String>> equations, double[] values, List<List<String>> queries) {
        HashSet<String> visit = new HashSet<>();
        double[] res = new double[queries.size()];
        
        for (int i = 0; i < values.length; i++) {
            String x = equations.get(i).get(0);
            String y = equations.get(i).get(1);
            
            map.putIfAbsent(x, new HashMap<String, Double>());
            map.putIfAbsent(y, new HashMap<String, Double>());
            
            map.get(x).put(y, values[i]);
            map.get(y).put(x, 1/values[i]);
        }
        
        for (int i = 0; i < queries.size(); i++) {
            res[i] = divide(visit, 
                           queries.get(i).get(0), 
                           queries.get(i).get(1));
            visit.clear();
        }
        
        return res;
    }
    
    private double divide(HashSet<String> visit, 
                         String start, String target) {
        if (start == target) return 1.0;
  
        if (!map.containsKey(start) || visit.contains(start)) {
            return -1.0;
        }
        if (map.get(start).get(target) != null) {
            return map.get(start).get(target);
        }
        visit.add(start);
        
        for (String neighbor : map.get(start).keySet()) {
            double res = divide(visit, neighbor, target);
            if (res != -1.0) {
                res *= map.get(start).get(neighbor);
                
                return res;
            }
        }
        
        return -1.0;
    }
}
