package 图论专题.克隆图;

import 图论专题.Node;

import java.util.ArrayList;
import java.util.HashMap;

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
}
