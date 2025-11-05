#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* createnode(int value){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right= NULL;
    return newnode;
}

struct node* insert( struct node* root, int value){
    if(root== NULL){
        return createnode(value);
    }
    if(value < root->data){
        root->left=insert(root->left,value);}
    else{
        root->right=insert(root->right,value);
    }
    return root;
    
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root-> left);
        printf(" %d ",root-> data);
        inorder(root-> right);

    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf(" %d ",root-> data);
        preorder(root-> left);
        preorder(root-> right);

    }
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root-> left);
        postorder(root-> right);
        printf(" %d ",root-> data);

    }
}

void search(struct node* root, int key ){
         if(root== NULL){
            printf("NULL");
            return ;
         }
         if ( root->data== key){
          printf ("Found");}
        else if(key < root-> data){
             search(root->left,key);
            
        }
        else{
             search(root->right,key);
           
        }
        
}
 int main(){
    struct node* root= NULL;
    int n,value,key;
    
    printf("enter node values(-1 to stop): \n");
    while(1){
        scanf("%d",&value);
        if(value==-1)
         break;
         root= insert(root,value);
    }
 
 
  printf("\n Inorder traversal: ");
  inorder(root);
   printf("\n Preorder traversal: ");
preorder(root);
   printf("\n postorder traversal: ");
  postorder(root);
  printf("\nenter value to search");
  scanf("%d\n",& key);
  search(root,key);
  return 0;
 }

