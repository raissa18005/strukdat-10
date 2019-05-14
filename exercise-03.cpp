/*
Nama      : Raissa Amini
NPM       : 140810180073
Deskripsi : Exercise 3
*/
#include <iostream>

using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createTree(Tree& Root){
    Root=NULL;
}

void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout << "Masukkan satu angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left,pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right,pBaru);
    else
        cout<<"sudah ada";
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
     if (Root != NULL){
          inOrder(Root->left);
          cout<< Root->info <<endl;
          inOrder(Root->right);
     }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}

void notasiKurung(Tree Root){
    if(Root!=NULL){
        cout << "(";
        cout << Root->info;
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout << ")";
    }
}

int main()
{
    Tree Root;
    pointer pBaru;
    int pil;
    createTree(Root);
    int n;
    cout<<"Masukkan Banyak elemen : ";cin>>n;
    for(int i=0; i<n; i++)
    {
            CreateSimpul(pBaru);
            insertBST(Root,pBaru);
    }
    notasiKurung(Root);
    system("pause");
     do{
      system("cls");
      cout << "1. Insert" << endl;
      cout << "2. Preorder" << endl;
      cout << "3. Inorder" << endl;
      cout << "4. Postorder "<< endl;
      cout << "5. Exit "<<endl;
      cout << "Masukkan pilihan anda : "; cin >> pil;
      switch(pil){
           case 1:
            CreateSimpul(pBaru);
            insertBST(Root,pBaru);
            notasiKurung(Root);
            system("pause");
           break;
           case 2:
            preOrder(Root);
            system("pause");
           break;
           case 3:
            inOrder(Root);
            system("pause");
            break;
           case 4:
            postOrder(Root);
            system("pause");
           break;
           case 5:
            return 0;
           break;
          }
    }while(pil!=5);

    return 0;
}
