package 第三章.动物收容所;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class AnimalShelf {
    Queue<int[]> queue;

    public AnimalShelf() {
        queue = new LinkedList<>();
    }

    public void enqueue(int[] animal) {
        queue.offer(animal);
    }

    public int[] dequeueAny() {
        if (queue.isEmpty())
            return new int[]{-1, -1};
        return queue.poll();
    }

    public int[] dequeueDog() {
        for (int[] animal : queue)
            if (animal[1] == 1) {
                queue.remove(animal);
                return animal;
            }
        return new int[]{-1, -1};
    }

    public int[] dequeueCat() {
        for (int[] animal : queue)
            if (animal[1] == 0) {
                queue.remove(animal);
                return animal;
            }
        return new int[]{-1, -1};
    }
    // LinkedList<int[]> a;
    // int[] num={0,0};
    // public AnimalShelf() {
    //     a = new LinkedList<>();
    // }

    // public void enqueue(int[] animal) {
    //     if(animal==null)return;
    //     if(num[animal[1]]==0){
    //         a.add(animal);
    //         num[animal[1]]++;
    //     }
    //     else{
    //         int[] k=a.getFirst();
    //         if(k[1]==animal[1]){
    //             a.add(animal);
    //         }
    //     }
    // }

    // public int[] dequeueAny() {
    //     int[] d={-1,-1};
    //     if(a.isEmpty()){
    //         return d;
    //     }else{
    //         d=a.removeFirst();
    //         num[d[1]]--;
    //         return d;
    //     }
    // }

    // public int[] dequeueDog() {
    //     int[] d={-1,-1};
    //     if(!a.isEmpty()){
    //         for(int[] m:a){
    //             // System.out.println(m[1]);
    //             if(m[1]==1){
    //                 d=m;
    //                 a.remove(m);
    //                 num[d[1]]--;
    //             }
    //         }
    //     }

    //     return d;
    // }

    // public int[] dequeueCat() {
    //     int[] d={-1,-1};
    //     if(!a.isEmpty()){
    //         for(int[] m:a){
    //             // System.out.println(m[1]);
    //             if(m[1]==0){
    //                 d=m;
    //                 a.remove(m);
    //                 num[d[1]]--;
    //             }
    //         }
    //     }
    //     return d;
    // }
}
