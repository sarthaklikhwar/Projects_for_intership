#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company
struct Employee* noaf(struct Employee* head,int t){
    if(head==NULL){
        return NULL;
    }
    if(head->emp_id==t){
        return head;
    }
    struct Employee* left=noaf(head->subordinate_1,t);
    if(left){
        return left;
    }
    struct Employee* right=noaf(head->subordinate_2,t);
    if(right){
        return right;
    }

    return NULL;
}

struct Employee* helper(struct Employee* head,int a,int b){
    if(head==NULL){
        return NULL;
    }
    if(head->emp_id==a||head->emp_id==b){
        return head;
    }
    if(helper(head->subordinate_1,a,b)!=NULL && helper(head->subordinate_2,a,b)!=NULL){
        return head;
    }
    if(helper(head->subordinate_1,a,b)!=NULL){
        return helper(head->subordinate_1,a,b);
    }
    if(helper(head->subordinate_2,a,b)!=NULL){
        return helper(head->subordinate_2,a,b);
    }
}
// The below function returns the employee id of the first common boss
int get_first_common_boss(int emp_id1,int emp_id2){
    struct Employee* k=helper(CEO,emp_id1,emp_id2);
    return k->emp_id;
}

//Print the employees with the same last name sperated by a space in the order of their level
int height(struct Employee* head){
    if(head==NULL){
        return 0;
    }
    else{
        int l=height(head->subordinate_1);
        int r=height(head->subordinate_2);

        if(l>r){
            return l+1;
        }
        else{
            return r+1;
        }
    }
}

    

void printCurrentLevel(struct Employee* root, int level,struct Employee* u)
{
    if (root == NULL)
        return;
    if (level==1){

          if(strcmp(root->emp_name,u->emp_name)==0){
            printf("%d ",root->emp_id);
          }
    }
        
    else if (level > 1) {
        printCurrentLevel(root->subordinate_1, level - 1,u);
        printCurrentLevel(root->subordinate_2, level - 1,u);
    }
}
void same_last_names(int emp_id){
    struct Employee* e=noaf(CEO,emp_id);
    int h = height(CEO);
    for (int i = 0; i <= h; i++){
        printCurrentLevel(CEO, i,e);
    }
    return;
}


struct Node
{
    int data;
    struct Node* next;
};


struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

struct Node* PythonListHead = NULL;
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur!=NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
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
int  helper2(struct Employee* head ,int a){
    if(head==NULL){
        return 0;
    }
    append(head->emp_id);
    if(head->emp_id==a){
        return 1;
    }
    if(helper2(head->subordinate_1,a)||helper2(head->subordinate_2,a)){
        return 1;
    }
   pop();
   return 0;
}

void get_all_bosses(int emp_id){
    if(CEO->emp_id==emp_id){
        printf("%d ",-1);
    }
    else{
        helper2(CEO,emp_id);
        pop();
        print_list(PythonListHead);
        clear();
    }
    return;
}

// Return the average salary of the team with the given employee as head
int countnodes(struct Employee* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->subordinate_1)+countnodes(root->subordinate_2)+1;
}
double sumnodes(struct Employee* root){
    if(root==NULL){
        return 0.00;
    }
    return sumnodes(root->subordinate_1)+sumnodes(root->subordinate_2)+root->emp_salary;
}

double get_average_salary(int emp_id){
    int k=countnodes(noaf(CEO,emp_id));
    double z=sumnodes(noaf(CEO,emp_id));
    return (z/k);
    
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}