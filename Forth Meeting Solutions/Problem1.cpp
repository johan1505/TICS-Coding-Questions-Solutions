#include <string> 

string longestCommonPrefix(string strs[]) {
        if (strs.length == 0) return "";
        String first_str = strs[0];
        int CommonPrefixLength = first_str.length();
        for (int i = 1; i < strs.length; ++i){
            int j;
            for (j = 0; j < Math.min(CommonPrefixLength, strs[i].length()); ++j){
                if (strs[i].charAt(j) != first_str.charAt(j)){
                    break;
                }
            }
            CommonPrefixLength = j;        
            if (CommonPrefixLength <= 0) return "";
        }
        return first_str.substring(0, CommonPrefixLength);
}