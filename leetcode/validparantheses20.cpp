//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//created a stack. when not empty check if ]}) are given and the stack top is [{(. if so pop it.
//at the end check if the stack is empty. above operaion should remove all parantheses if properly present



class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s){
            if(!stk.empty()){// only check if not empty
                if((c==']'&& stk.top()=='[')||(c=='}'&& stk.top()=='{')||(c==')'&& stk.top()=='(')){
                    stk.pop();//remove the ({[
                    continue;// prevent adding to stack
                }
                
            }
            stk.push(c); 
            }
        if(stk.empty()){// if the stack doesnt get emptied by the above operation it means all werent closed or there were ]})
            return true;
        }
        else{
            return false;
        }
        
    }
};