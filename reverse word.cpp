void reverseWords(string &s) {
    string str="",word="";
    string::iterator first;

    reverse(s.begin(),s.end());
    for(first  = s.begin(); first != s.end(); )
    {
    	while(*first != ' ' && first != s.end())
    	{
    		word += *first;
    		first++;
    	}
    	if(first != s.end() && *first  == ' ' && word.length() == 0)
    	{
    		first++;
    	}
    	if(*first  == ' ' && word.length() != 0)
    	{
    		reverse(word.begin(),word.end());
    		str += word + ' ';
    		word = "";
    	}
    }
    if(!word.empty()){
            reverse(word.begin(),word.end());
          	str += word; 	
    }
    s = "";
    if(*(str.end()-1) == ' ')
	    s  = string(str.begin(),str.end()-1);
	else
		s = str;
}
