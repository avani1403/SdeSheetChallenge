bool areAnagram(string &str1, string &str2){
    // Write your code here.
    
   if(str1.size() != str2.size()) return false;
    int freq[26] = {0};
    
    for(auto ch : str1)
        freq[ch - 'a']++;
    
    for(auto c : str2)
        freq[c - 'a']--;
    
    for(int i = 0; i<26; i++)
        if(freq[i]) return false;
    
    return true;
}
