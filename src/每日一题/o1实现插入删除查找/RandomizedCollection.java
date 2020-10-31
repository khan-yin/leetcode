package 每日一题.o1实现插入删除查找;

import java.util.*;

public class RandomizedCollection {
    public HashMap<Integer, Integer> map = new HashMap<>();

    /**
     * Initialize your data structure here.
     */
    public RandomizedCollection() {

    }

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
     */
    public boolean insert(int val) {
        if (map.get(val) == null) {
            map.put(val, 1);
            return true;
        } else {
            int cnt = map.get(val);
            map.put(val, ++cnt);
            return false;
        }
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified element.
     */
    public boolean remove(int val) {
        // System.out.println("remove"+map.get(val));
        if (map.get(val) == null) {
            return false;
        } else {
            int cnt = map.get(val);
            cnt--;

            if (cnt == 0) {
                map.remove(val);
            } else {
                map.put(val, cnt);
            }
            return true;
        }
    }

    /**
     * Get a random element from the collection.
     */
    public int getRandom() {
        int len = 0;
        List<Integer> list = new ArrayList();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            len += entry.getValue();
            for (int i = 0; i < entry.getValue(); i++) {
                list.add(entry.getKey());
            }
        }
        int t = new Random().nextInt(len);
        int res = list.get(t);
        return res;
        // Random r = new Random();
        // int k=r.nextInt(map.size()+1);
        // for(Integer key: map.keySet()){
        //     Integer value = map.get(key);
        //     k=k-value;
        //     if(k<=0){
        //         return key;
        //     }
        // }
        // return 0;
    }
}
