#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    
    int l1[] = {941, 913, 16, 882, 94, 96, 794, 742, 442, 209, 734, 43};
    int l2[] = {869, 13, 315, 343, 477, 420, 244, 702, 944, 829, 86, 44};
    int l3[] = {981, 971, 728, 82, 546,152, 230,184,102, 21,174, 178};

    linkedList L1, L2, L3, L;

    for(int i = 0; i < sizeof(l1)/sizeof(l1[0]); i++){
        L1.insertBack(l1[i]);
        L2.insertBack(l2[i]);
        L3.insertBack(l3[i]);
    }

    int i = 0;
    struct node* h1 = L1.getHead();
    struct node* h2 = L2.getHead();
    struct node* h3 = L3.getHead();

    while(h1 != NULL && h2 != NULL && h3 != NULL){
        int a = h1->data, b = h2->data, c = h3->data;
        if(i%2 == 0){
            int min = a < b? (a < c ? a: c):(b < c ? b : c);
            L.insertBack(min);
        } else{
            int max = a > b? (a > c ? a: c):(b > c ? b : c);
            L.insertBack(max);
        }
        h1 = h1->next;
        h2 = h2->next;
        h3 = h3->next;
        i++;
    }

    L.printList();

    return 0;
}