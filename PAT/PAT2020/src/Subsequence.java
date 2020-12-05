import java.util.Scanner;

public class Subsequence {
    public static boolean getAns(String temp,String sub)
    {
        int k=0;
        int i=0;
        while(k<temp.length()&&i<sub.length())
        {
            int t=temp.indexOf(String.valueOf(sub.charAt(i)),k);
            if(t==-1||k>t)
                return false;
            k=t;
            i++;
        }
        return true;
    }

    public static void main(String[] args) {
        String str="";
        Scanner sc = new Scanner(System.in);
        str=sc.nextLine();
        String sub=sc.nextLine();
        int sl=sub.length();
        String ans="";
//        String[] slist=str.split(String.valueOf(sub.charAt(0)));
//        for(String t:slist)
//        {
//            String temp=sub.charAt(0)+t;
//            boolean flag=getAns(sub.charAt(0)+temp,sub);
//            if(ans.length()==0&&flag)
//            {
//                ans=temp;
//            }
//            else
//            {
//                if(flag&&ans.length()>temp.length())
//                {
//                    ans=temp;
//                }
//            }
//        }
        for(int i=0;i<str.length();i++)
        {
            for(int j=i+sl;j<=str.length();j++)
            {
                String temp=str.substring(i,j);
                boolean flag=getAns(temp,sub);
                if(ans.length()==0&&flag)
                {
                    ans=temp;
                }
                else
                {
                    if(flag&&ans.length()>temp.length())
                    {
                        ans=temp;
                    }
                }
            }
        }

        System.out.print(ans);
    }
}
