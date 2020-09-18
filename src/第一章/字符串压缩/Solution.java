package 字符串压缩;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String a="aabcccccaa";
        System.out.println(solution.esay_compressString(a));
        System.out.println(solution.compressString(a));
    }
    //参考题解的双指针做法更好
    public String compressString(String S){
        char[] ch=S.toCharArray();//转char数组更快
        int len=S.length();
        if(len<=2)
        {
            return S;
        }
        else
        {
            int i=0;
            StringBuilder sb = new StringBuilder();
            while(i<len)
            {
                int j=i+1;
                while(j<len&&ch[i]==ch[j]){
                    j++;
                }
                sb.append(ch[i]);
                sb.append(j-i);
                i=j;
            }
            String st=sb.toString();
            return st.length()<len?st:S;
        }
    }

    public String esay_compressString(String S) {
        String st="";
        int len=S.length();
        if(len<=1)
        {
            return S;
        }
        else
        {
            String Sc=S;
            Sc+="0";
            int cnt=1;
            for(int i=0;i<len;i++)
            {
                char c1=Sc.charAt(i);
                char c2=Sc.charAt(i+1);
                if(c1!=c2)
                {
                    st+=c1;//String的循环体中使用这个操作很占内存，多用StringBuilder比较好
                    st+=String.valueOf(cnt);
                    cnt=1;
                }
                else
                {
                    cnt++;
                }
            }
        }
        st=st.length()<len?st:S;
        return st;
    }
}
