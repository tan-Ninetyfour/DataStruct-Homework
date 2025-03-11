typedef struct{
    int *data;
    int length;
} SeqList;

int Insert(SeqList *L, int x){
    int i = L->length - 1;
    while (i >= 0 && L->data[i] > x){
        L->data[i + 1] = L->data[i];
        i--;
    }

    L->data[i+1] = x;
    L->length++;
}