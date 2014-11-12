    vector<int> plusOne(vector<int> &digits) {
        
        reverse(digits.begin(),digits.end());
        bool carry = false;
        
        for(int i = 0; i < digits.size(); i++){
            int tmp = digits[i] + 1;
            if (tmp > 9) carry =true;
            else carry = false;
            if(carry){
                digits[i] = 0;
                if(i == digits.size()-1){
                    digits.resize(digits.size()+1);
                    digits[i+1] = 1;
                    break;
                }
            }else{
                digits[i] = tmp;
                break;
            }
            
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }

    vector<int> plusOne(vector<int> &digits) {
        
        int carry = 1;
        
        for(auto it = digits.rbegin();it != digits.rend() && carry > 0; it++){
            *it += carry;
            carry = *it /10;
            *it = *it %10;
        }
        if(carry>0)
            digits.insert(digits.begin(),carry);

        return digits;
    }