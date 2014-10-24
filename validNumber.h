    bool isNumber(const char *s) {
        char* endptr;
        
        strtod(s,&endptr);
        if(endptr == s) return false;
        
        for(;*endptr != '\0';endptr++)
            if(!isspace(*endptr)) return false;
        return true;
    }

    bool isNumber(const char *s) {
	    int i = 0;
	    for(;s[i] ==' ';i++); //skip space
	    
	    if(s[i]=='+' || s[i] == '-') i++;
	    
	    int digit_count=0, point_count=0;
	    for(;(s[i]<='9'&& s[i]>='0') || s[i] == '.';i++)
	        s[i] != '.'?digit_count++:point_count++;
	    if(digit_count < 1 || point_count > 1) return false;
	    
	    if(s[i] =='e'){
	        i++;
	        if(s[i]=='+' || s[i] == '-') i++;
	        digit_count=0;
	        for(;s[i]<='9'&& s[i]>='0';i++) digit_count++;
	        if(digit_count < 1) return false;
	    }
	    for(;s[i] ==' ';i++);
	    
	    return s[i] == 0;//has to reach the end
	}

	bool isNumber(const char *s) {

        regex e("(\\s*)[+-]?((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))(e[+-]?[0-9]+)?(\\s*)");
        if(regex_match(s,e))
            return true;
        else return false;
    }