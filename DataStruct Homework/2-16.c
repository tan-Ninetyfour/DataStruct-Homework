typedef struct{
    int *data;
    int length;
} SeqList;

int ListFind(SeqList L, int x, int i){
    if(i < 0 || i > L.length){
        return -1;
    }

    for(int j = i; j < L.length; j++){
        if(L.data[j] == x){
            return j;
        }
    }

    return -1;
}