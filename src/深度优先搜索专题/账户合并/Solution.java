package 深度优先搜索专题.账户合并;

public class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        HashMap<String,String> email2owner=new HashMap<>();//email映射到owner上
        HashMap<String,ArrayList<String>> Emailmap= new HashMap<>();//Email之间的相关关系
        for(List<String> account:accounts)
        {
            String owner="";
            for(String email:account)
            {
                if(owner=="")
                {
                    owner=email;
                }
                else
                {
                    email2owner.put(email,owner);
                    Emailmap.computeIfAbsent(email, x-> new ArrayList<String>()).add(account.get(1));
                    Emailmap.computeIfAbsent(account.get(1), x-> new ArrayList<String>()).add(email);
                    //该代码意思如下：
                    // email2owner.put(email,owner);
                    // if(Emailmap.get(email)!=null)
                    // {
                    //     if(Emailmap.get(account.get(1))!=null)
                    //         Emailmap.get(email).add(account.get(1));
                    //     else
                    //     {
                    //         Emailmap.put(account.get(1),new ArrayList<String>());
                    //     }
                    //     Emailmap.get(account.get(1)).add(email);
                    // }
                    // else
                    // {
                    //     Emailmap.put(email,new ArrayList<String>());
                    //     if(Emailmap.get(account.get(1))!=null)
                    //         Emailmap.get(email).add(account.get(1));
                    //     else
                    //     {
                    //         Emailmap.put(account.get(1),new ArrayList<String>());
                    //     }
                    //     Emailmap.get(account.get(1)).add(email);
                    // }
                }
            }
        }

        Set<String> seen = new HashSet();//记录访问过的节点，用于减枝递归
        List<List<String>> ans = new ArrayList();
        for(String email:Emailmap.keySet())//遍历每个邮箱的映射关系
        {
            if(!seen.contains(email))
            {
                seen.add(email);
                Stack<String> sk= new Stack<>();//用栈来模拟控制递归
                sk.push(email);
                ArrayList<String> emailroute=new ArrayList();
                while(!sk.empty())
                {
                    String temp=sk.pop();
                    emailroute.add(temp);//每次记录和email相关的其他email并存到该数组
                    ArrayList<String> relatedEmails=Emailmap.get(temp);
                    for(String e:relatedEmails)
                    {
                        if(!seen.contains(e))//遇到了没访问过的email就加入当中
                        {
                            seen.add(e);
                            sk.add(e);
                        }
                    }
                }
                Collections.sort(emailroute);//按字典排序
                emailroute.add(0,email2owner.get(email));//在最前面把ownername加入数组当中
                ans.add(emailroute);//新增一条记录
            }
        }
        return ans;
    }
}
