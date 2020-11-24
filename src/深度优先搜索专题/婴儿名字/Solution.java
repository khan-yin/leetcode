package 深度优先搜索专题.婴儿名字;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    private int[] parents;
    private Map<String, Integer> name_id = new HashMap<>();
    private Map<Integer, String> id_name = new HashMap<>();
    private Map<String, Integer> frequence = new HashMap<>(); // frequence == frequency

    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        // ---------- init begin ----------
        final int N = names.length;
        parents = new int[N];

        for (int i = 0; i < N; ++i) {
            parents[i] = i;

            final int idx = names[i].indexOf('(');
            final String name = names[i].substring(0, idx);//名字
            final String freq = names[i].substring(idx + 1, names[i].length() - 1);//数量
            name_id.put(name, i);
            id_name.put(i, name);
            frequence.put(name, Integer.parseInt(freq));
        }
        // ---------- init end ----------

        for (String synonym : synonyms) {
            final String[] pair = synonym.substring(1, synonym.length() - 1).split(",");
            final String name1 = pair[0], name2 = pair[1];
            final Integer id1 = name_id.get(name1), id2 = name_id.get(name2);

            if (null == id1 || null == id2)
                continue;

            union(id1, id2);
        }

        List<String> ans = new ArrayList<>();
        frequence.forEach((name, freq) -> {
            int id = name_id.get(name);
            ans.add(name + '(' + freq + ')');
        });

        return ans.stream().toArray((String[]::new));
    }

    private int find(final int x) {
        if (parents[x] == x) return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }

    private void union(final int a, final int b) {

        if (a == b) return;

        final int pa = find(a);
        final int pb = find(b);
        if (pa == pb) return;

        final String name1 = id_name.get(pa), name2 = id_name.get(pb);
        if (name1.compareTo(name2) < 0) { // 按字典序，看谁小谁就作为新的根节点
            frequence.put(name1, frequence.get(name1) + frequence.get(name2));
            parents[pb] = pa;
            frequence.remove(name2);
        } else {
            frequence.put(name2, frequence.get(name1) + frequence.get(name2));
            parents[pa] = pb;
            frequence.remove(name1);
        }
    }
}
