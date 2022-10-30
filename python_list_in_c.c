#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    struct Node* ptr1 =create_node(x);     
    struct Node* temp; 
    if(PythonListHead==NULL){
        PythonListHead=create_node(x);
        return ;
    }
    temp=PythonListHead;
    while (temp ->next != NULL)  {  
            temp = temp ->next;  
                }  
    temp->next = ptr1;    
    
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
int helper() {
    struct Node* temp;
    temp=PythonListHead;
    int cont=1;
    if(PythonListHead==NULL){
        return 0;
    }
    while(temp->next!=NULL){
        cont++;
        temp=temp->next;
    }
    return cont;
}


void insert(int position, int x) {
    struct Node* ptr=create_node(x);
   struct Node* temp=PythonListHead;
   if(position>helper()-1){
       return ;
   }
   if(position==0){
       ptr->next=PythonListHead;
       PythonListHead=ptr;
   }
   else{
        struct Node* temp1=create_node(x);
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next=temp1;
   }
}


// Remove the item at the end of the list
void pop() {
   if(PythonListHead==NULL){
        return;
    }
    struct Node* ans=PythonListHead;
    struct Node* last=PythonListHead;
    struct Node* selast=PythonListHead;
    if(ans->next == NULL){
      free(PythonListHead);
      PythonListHead=NULL;
        return;
    }
   while(last->next!=NULL){
        selast=last;
        last=last->next;
    }
    selast->next=NULL;
    free(last);
    last=NULL;
}


// Remove all items from the list
void clear() {
 struct Node* ans1=PythonListHead;
    struct Node* check=ans1;
    if(PythonListHead==NULL){
        return ;
    }
    while(check!=NULL){
        check=check->next;
        free(PythonListHead);
        PythonListHead=check;
    }
}

// Return the number of times x appears in the list.
int count(int x) {
    struct Node* ans=PythonListHead;
    int counter=0;
    while(ans!=NULL){
        if(ans->data==x){
            counter++;
        }
        ans=ans->next;
    }
    return counter;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* currptr=PythonListHead;
    struct Node* preptr=NULL;
    struct Node* nextptr;
    while(currptr!=NULL){
    nextptr=currptr->next;
    currptr->next=preptr;
    preptr=currptr;
    currptr=nextptr;
    }
    PythonListHead=preptr;
}


// Return the number of elements in the list
int len() {
    struct Node* temp;
    temp=PythonListHead;
    int cont=1;
    if(PythonListHead==NULL){
        return 0;
    }
    while(temp->next!=NULL){
        cont++;
        temp=temp->next;
    }
    return cont;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
     struct Node* ans1=PythonListHead;
    if(len()-1<position){
        return;
    }
    for(int i=0;i<position;i++){
        ans1=ans1->next;
    }
    ans1->data=x;
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    struct Node* ans1=PythonListHead;
    if(len()-1<position){
        return -1;
    }
    for(int i=0;i<position;i++){
        ans1=ans1->next;
    }
    int z=ans1->data;
    return z;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
   struct Node* curr=PythonListHead;
   struct Node* pre=PythonListHead;
   if(position>len()-1){
       return;
   }
   if(PythonListHead==NULL){
       return;
   }
   if(position==0){
       PythonListHead=curr->next;
       free(curr);
       curr=NULL;
   }
   else{
       while(position!=0){
           pre=curr;
           curr=curr->next;
           position--;
       }
       pre->next=curr->next;
       free(curr);
       curr=NULL;
   }
}


// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* first=NULL;
void app(int x) {
    struct Node* ptr1 =create_node(x);     
    struct Node* temp; 
    if(first==NULL){
        first=create_node(x);
        return ;
    }
    temp=first;
    while (temp ->next != NULL)  {  
            temp = temp ->next;  
                }  
    temp->next = ptr1;  
}
struct Node* index_into(int *positions, int n) {
   
    for (int i=0;i<n;i++){
       int  dat=*(positions+i);
       struct Node* key=PythonListHead;
       if(dat>len()-1){
        continue;
       }
       if(dat==0){
           int l=key->data;
           app(l);
           continue;
       }
       else{
        while(dat!=0){
            key=key->next;
            dat--;
        }
        int j=key->data;
        app(j);
       }
    }
    struct Node* gh=first;
    first=NULL;
   if(gh==NULL){
    return gh ;
   }
   return gh;
}



// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position){
   struct Node* p=PythonListHead;
    struct Node* r=PythonListHead;
    struct Node* q;
    int i=0;
    
    if((len()-1<position)|| (len()-1<position+1)){
        return ;
    }
    if(position==0){
        p=p->next;
        r->next=p->next;
        p->next=r;
        PythonListHead=p;
        
    }
    else
    {   
        while(i<position-1)
        {
            p=p->next;
            i++;
        }
    q=p->next;
    r=q->next;
    q->next=r->next;
    r->next=q;
    p->next=r;
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you.
void sort() {
     int n=len();
 for(int i=0;i<n;i++){
     
     for(int j=0;j<n-1;j++){
        if(getitem(j)>getitem(j+1)){
            swap(j);
        }
     }
 }
}



// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}