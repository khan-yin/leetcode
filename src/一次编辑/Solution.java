package 一次编辑;

public class Solution {
    public static void main(String[] args) {

        String first="teacher";
        String second="treacher";
        System.out.println(oneEditAway(first,second));
    }

    public static boolean oneEditAway(String first, String second) {
        // char[] ch1= first.toCharArray();
        // char[] ch2=second.toCharArray();
        // Arrays.sort(ch1);
        // // Arrays.sort(ch2);
        // System.out.println(ch1);
        // System.out.println(ch2);
        int len1=first.length();
        int len2=second.length();
        if(len1-len2==1)
        {
            if(len2==0)
            {
                return true;
            }
            else{
                int flg=0;
                int i=0;
                int j=0;
                while(i<len1&&j<len2)
                {
                    char c1 = first.charAt(i);
                    char c2 = second.charAt(j);
                    if(c1!=c2)
                    {
                        flg++;
//                        i++;
                        j--;
                    }
                    i++;
                    j++;
                }
                if(flg>1)
                {
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        else if(len1==len2)
        {
            int flg=0;
            for(int i=0;i<len1;i++)
            {
                char c1 = first.charAt(i);
                char c2 = second.charAt(i);
                if(c1!=c2)
                {
                    flg++;
                }
            }
            if(flg>1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (len1-len2==-1)
        {
            if(len1==0)
            {
                return true;
            }else{
                int flg=0;
                int i=0;
                int j=0;
                while(i<len1&&j<len2)
                {
                    char c1 = first.charAt(i);
                    char c2 = second.charAt(j);
                    if(c1!=c2)
                    {
                        flg++;
//                        j++;
                        i--;
                    }
                    i++;
                    j++;
                }
                if(flg>1)
                {
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        else{
            return false;
        }
    }


}
