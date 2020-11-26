package 图论专题.克隆图;

import 图论专题.Node;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

//dfs解法
public class Solution {
    public HashMap<Node, Node> node_nodecopy = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null)//剪枝
            return node;
        if (node_nodecopy.containsKey(node))//该节点已经拷贝过了,直接返回拷贝以后的新节点
            return node_nodecopy.get(node);
        Node newnode = new Node(node.val, new ArrayList<Node>());
        node_nodecopy.put(node, newnode);//加入列表

        for (Node node_neighbor : node.neighbors) {
            newnode.neighbors.add(cloneGraph(node_neighbor));//将旧node的neighbor的clone赋值给newnode
        }

        return newnode;

    }


    public Node cloneGraph_bfs(Node node) {
        if (node == null)//剪枝
            return node;
        HashMap<Node, Node> node_nodecopy = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();
        queue.offer(node);
        node_nodecopy.put(node, new Node(node.val, new ArrayList<Node>()));

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node temp = queue.remove();
                for (Node neighbor : temp.neighbors) {
                    if (!node_nodecopy.containsKey(neighbor)) {
                        node_nodecopy.put(neighbor, new Node(neighbor.val, new ArrayList<Node>()));
                        queue.offer(neighbor);
                    }
                    node_nodecopy.get(temp).neighbors.add(node_nodecopy.get(neighbor));
                }
            }
        }
        return node_nodecopy.get(node);
    }
}
