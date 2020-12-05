
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class FilePath {
    public static boolean dfs(TreeNode root,String target,ArrayList<String> route)
    {
        if(root.name.equals(target))
        {
//            route.add(root.name);
            return true;
        }
        else
        {
            for(TreeNode t:root.nodelist)
            {
                route.add(t.name);
                if(!dfs(t,target,route))
                {
                    route.remove(route.size()-1);
                }
                else
                    return true;

            }
            return false;
        }
    }
    public static void main(String[] args) {
        HashMap<Integer,ArrayList<TreeNode>> nodemap=new HashMap<Integer, ArrayList<TreeNode>>();
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        String temp=sc.nextLine();
        while(n!=0)
        {
            temp=sc.nextLine();
//            System.out.println(temp);
            int l=temp.length();
            int depth=l-4;
//            System.out.println(temp+" "+depth);
            String r=temp.trim();
            if(!nodemap.containsKey(depth))
                nodemap.put(depth,new ArrayList<TreeNode>());
            TreeNode t=new TreeNode(r,new ArrayList<>());
            nodemap.get(depth).add(t);
            if(depth!=0)
            {
                ArrayList<TreeNode> last =nodemap.get(depth-1);
//                System.out.println(last.size());
                last.get(last.size()-1).nodelist.add(t);
            }

            n--;
        }

        int m=sc.nextInt();
        for(int i=0;i<m;i++)
        {
            String k=sc.next();
            ArrayList<String> route= new ArrayList<>();
//            System.out.println(nodemap.get(0).get(0).name);
//            System.out.println(k);
            route.add(nodemap.get(0).get(0).name);
            if(!dfs(nodemap.get(0).get(0),k,route))
            {
                System.out.println("Error: "+ k +" is not found.");
                continue;
            }


            for(int l=0;l<route.size();l++)
            {
                if(l==0)
                    System.out.print(route.get(l));
                else
                    System.out.print("->"+route.get(l));
            }
            System.out.println();
        }
    }
}

class TreeNode{
    public String name;
    public ArrayList<TreeNode> nodelist;
    public TreeNode(String _name,ArrayList<TreeNode> _nodelist)
    {
        this.name=_name;
        this.nodelist=_nodelist;
    }
}