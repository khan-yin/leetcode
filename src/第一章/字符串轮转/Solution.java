package 第一章.字符串轮转;

public class Solution {
    public static void main(String[] args) {
      Solution solution = new Solution();
      String s1="";
      String s2="";
      System.out.println(solution.best_isFlipedString(s1,s2));
    }

    public boolean best_isFlipedString(String s1, String s2)
    {
        /**
         *  长度不相等，肯定不符合要求
         *  长度相等时，若s2是s1旋转而成的，那么把s2和自身拼接一次，s1就会出现在其中
         *  "erbottlewat" + "erbottlewat" = erbottle waterbottle wat
         *  如果s2不是s1旋转而成的，那么那么把s2和自身拼接一次，s1就肯定不会出现在其中
         *
         * 作者：zui-weng-jiu-xian
         * 链接：https://leetcode-cn.com/problems/string-rotation-lcci/solution/xiang-xi-by-zui-weng-jiu-xian/
         * 来源：力扣（LeetCode）
         * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
         */
        return s1.length()==s2.length()&&(s2+s2).indexOf(s1)!=-1;
    }

    public boolean my_isFlipedString(String s1, String s2) {
        int len1=s1.length();
        int len2=s2.length();
        if(len1!=len2)
        {
            return false;
        }
        else
        {
            if(len1==0)
            {
                return true;
            }
            for(int i=0;i<len1;i++)
            {
                String m=s1.substring(i);
                String y=s1.substring(0,i);
                String news=m+y;
                if(news.equals(s2))
                {
                    return true;
                }
            }
            return false;
        }
    }
}

