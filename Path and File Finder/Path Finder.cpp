#include<iostream>
#include <dirent.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

typedef struct Node *ptr;
struct Node{
    string data;
    ptr left;
    ptr right;
};

Node* create_node(char n[]){
    ptr node=new Node;
    node->data=n;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void insert_node(char data[], ptr *current, ptr parent){
    if(*current==NULL && parent==NULL){
        *current=create_node(data);
        return;
    }
    if((*current)!=NULL && (*current)->data==data){
        return;
    }
    if((*current)==NULL && parent!=NULL){
            *current=create_node(data);
            return;
    }
    if(data<(*current)->data){
            insert_node(data, &(*current)->left, *current);
            return;
        }
    else{
            insert_node(data, &(*current)->right, *current);
            return;
    }
}

void print_tree(ptr tree){
    if(tree==NULL){
        return;
    }
    cout<<tree->data<<endl;
    print_tree(tree->left);
    print_tree(tree->right);
}

void preorder_tra(ptr tree){
    if(tree==NULL){
        return;
    }
   cout<<tree->data<<endl;
    print_tree(tree->left);
    print_tree(tree->right);
}

void postorder_tra(ptr tree){
    if(tree==NULL){
        return;
    }
    print_tree(tree->left);
    print_tree(tree->right);
    cout<<tree->data<<endl;
}

bool search_element(char key[], ptr tree){
        if(tree==NULL)
            return false;
        if (tree->data == key)
            return true;
        if (search_element(key, tree->left))
            return true;
        if (search_element(key, tree->right))
            return true;
        return false;
}

int count_files=0;
//ent->d_type == DT_DIR
//struct stat s;/*stat(".",&st)==0 && S_ISDIR(st.st_mode)*/
void listFiles(char* path, ptr *tree){
DIR* file;
struct dirent *e;
  if((file=opendir(path)) != NULL){
        while (( e = readdir(file)) != NULL){
            if(/*stat(path,&s)==0 && S_ISDIR(s.s_mode) && */strcmp(e->d_name, ".") !=0 && strcmp(e->d_name, "..") != 0){
                count_files++;
                //cout<<e->d_name<<endl;
                insert_node(e->d_name,&(*tree), NULL);
                path=e->d_name;
                listFiles(path, &(*tree));
            }
        }
        closedir(file);
    }
}

int main(){
    ptr tree=NULL;
    tree=create_node(".");
    int choice;
    char path[30], filename[10];
    cout<<"Please select one : \n\n1)Counting all file in a Path.\n2)Searching for a file in a Path.\n3)Exit.\n";
    cin>>choice;
    switch (choice){
    case 1:{
        cout<<"Please enter a path :\n";
        cin>>path;
        system("cls");
        listFiles(path, &tree);
        preorder_tra(tree);
        //postorder_tra(tree);
        cout<<"\nTotal Files in this path are : "<<count_files<<endl;
    break;
    }
    case 2:{
        cout<<"Please enter a path :\n";
        cin>>path;
        cout<<"Now enter the file :\n";
        cin>>filename;
        listFiles(path, &tree);
        if(search_element(filename, tree)==1)
            cout<<"\nFile found.."<<endl;
        else
            cout<<"\nFile not found!!"<<endl;
        break;
    }
    case 3:
        exit(1);
    default:
        cout<<"Invalid Input!!"<<endl;
        break;
    }

    return 0;
}
