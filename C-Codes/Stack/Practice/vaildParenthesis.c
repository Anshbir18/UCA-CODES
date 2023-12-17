bool isValid(char* s) {
    int len=strlen(s); //took out the length of tha string
    if(len%2 !=0){
        return false;
    }

    // declare a stack with a top pointer to help keep track

    int top=0;
    char*st=malloc(strlen(s)); //malloc for dynamic memory allocation 


    // now same logic as c++ //if open then push or else check the op with the closing and pop(top--);

    for(int i=0;i<strlen(s);i++){
        char c = s[i];

        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st[top]=c;
            top++;
         
        }
        else{
            if(c==')'){
                if(top>0 &&st[top-1]=='('){
                    top--;
                }
                else{
                    return false;
                }
            }
            else if(c==']'){
                if(top>0 && st[top-1]=='['){
                    top--;
                }
                else{
                    return false;
                }
            }
            else if(c=='}'){
                if(top>0 && st[top-1]=='{'){
                    top--;
                }
                else{
                    return false;
                }
            }
        }
    }

    free(st); //free memory
    if(top==0){
        return true;
    }
    return false;
}
