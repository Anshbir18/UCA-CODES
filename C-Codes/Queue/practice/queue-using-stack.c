typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;

    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj=malloc(sizeof(MyQueue));
    obj->stack1=(int*)malloc(sizeof(int)*100);
     obj->stack2=(int*)malloc(sizeof(int)*100);
     obj->top1=-1;
     obj->top2=-1;

     return obj;
    
}

void myQueuePush(MyQueue* obj, int x) {

    obj->top1++;
    obj->stack1[obj->top1]=x;
    
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2>=0){
        obj->top2--;
        return obj->stack2[obj->top2+1];
    }else{
        while(obj->top1>=0){
            obj->top2++;
            obj->stack2[obj->top2]=obj->stack1[obj->top1];
            obj->top1--;
        }
        obj->top1=-1;
        obj->top2--;
        return obj->stack2[obj->top2+1];
    }
    
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top1==-1 && obj->top2==-1)return -1;
    else if(obj->top2>=0){
        return obj->stack2[obj->top2];
    }else{
         while(obj->top1>=0){
            obj->top2++;
            obj->stack2[obj->top2]=obj->stack1[obj->top1];
            obj->top1--;
        }
        obj->top1=-1;
        return obj->stack2[obj->top2];

    }
    
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->top1==-1 && obj->top2==-1)return true;
    return false;
    
}

void myQueueFree(MyQueue* obj) {
    free(obj);
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
