typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj=malloc(sizeof(MyCircularQueue));
    obj->arr=(int*)malloc(sizeof(int)*k);
    obj->front=-1;
    obj->rear=-1;
    obj->size=k;

    return obj;
    
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front==-1)return true;
    return false;
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->front==0 && obj->rear==obj->size-1) || ((obj->front-1)%(obj->size)==obj->rear))return true;
    return false;

    
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(myCircularQueueIsFull(obj))return false;
    if(obj->front==-1){
        obj->front=0;
        obj->rear=0;
        obj->arr[obj->rear]=value;
    }else if(obj->front!=0 && obj->rear==obj->size-1){
        obj->rear=0;
        obj->arr[obj->rear]=value;
    }else{
        obj->rear++;
        obj->arr[obj->rear]=value;
    }

    return true;

    
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))return false;
    else if(obj->front==obj->rear){
        obj->front=-1;
        obj->rear=-1;
    }else if(obj->front==obj->size-1){
        obj->front=0;
    }else{
        obj->front++;
    }
    return true;
    
}

int myCircularQueueFront(MyCircularQueue* obj) {
    
    if(myCircularQueueIsEmpty(obj))return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))return -1;
    return obj->arr[obj->rear];
    
}



void myCircularQueueFree(MyCircularQueue* obj) {
    
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
