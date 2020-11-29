package 图论专题.除法求值;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
    public double dfs(String start, String end, HashMap<String, HashMap<String, Double>> routemap, List<String> isvisited) {
        if (!routemap.containsKey(start) || !routemap.containsKey(end))
            return -1;
        if (start.equals(end))
            return 1;
        isvisited.add(start);
        HashMap<String, Double> temp = routemap.get(start);
        for (Map.Entry<String, Double> entry : temp.entrySet()) {
            String key = entry.getKey();
            double value = entry.getValue();
            if (end.equals(key))
                return value;
            else if (!isvisited.contains(key)) {
                isvisited.add(key);
                double res = dfs(key, end, routemap, isvisited);
                if (res > 0)
                    return (res * value);
            }
        }
        // routemap.get(start).forEach((key, value) -> {
        //     // System.out.println(key.getClass().getName().toString());
        //     // System.out.println(value.getClass().getName().toString());

        // });
        return -1;
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        HashMap<String, HashMap<String, Double>> routemap = new HashMap();

        for (int i = 0; i < values.length; i++) {
            List<String> edge = equations.get(i);
            String start = edge.get(0);
            String end = edge.get(1);
            if (!routemap.containsKey(start))
                routemap.put(start, new HashMap<String, Double>());
            routemap.get(start).put(end, values[i]);

            if (!routemap.containsKey(end))
                routemap.put(end, new HashMap<String, Double>());
            routemap.get(end).put(start, 1 / values[i]);
        }
        // System.out.println(queries.size());
        int ql = queries.size();
        double[] result = new double[ql];
        int cnt = 0;
        for (List<String> query : queries) {
            List<String> isvisited = new ArrayList<>();
            result[cnt++] = dfs(query.get(0), query.get(1), routemap, isvisited);
        }
        return result;
    }
}
