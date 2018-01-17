#include <iostream>
using namespace std;

struct Mlist{
    int a;
    Mlist *next;
};

void print( Mlist *head ,Mlist *tail) {
    int b,c;
    cout<<"введите количесвто желаемых объектов "<<endl;
    cin>>b;
    for (int i=0 ; i<b ; i++){
        cin>>c;
        Mlist *node = new Mlist {c,nullptr};
        if(tail==nullptr){
            tail=node;
            head=tail;
            continue;
        }
        tail->next=node;
        tail=node;
    }
    Mlist *curr=head;

    while(  curr!= nullptr) {
        cout <<curr->a<<" ";
        curr = curr->next;
    }
}

void add(Mlist *head){
    int value,pos;
    cout<<" введите то,что вы хотите записать и позицию"<<endl;
    cin>>value>>pos;
    Mlist * newnode=new Mlist{0,nullptr};
    newnode->a=value;
    if (head== nullptr){
        newnode->next=newnode;
        head=newnode;
    }
    else {
        newnode->a=value;
        newnode->next=node->next;
        node->next=newnode;

    }

}
void Delete(){}

void Find(){}

void Replace(){}

void Sort(){}

void Menu()
{
    cout << "операции:" << endl;
    cout << "1. вывести" << endl;
    cout << "2. добавить элементы" << endl;
    cout << "3. удалить элементы" << endl;
    cout << "4. Найти позиции элементов" << endl;
    cout << "5. Заменить элемент на другой" << endl;
    cout << "6. Отсортировать элементы списка" << endl;
    cout << "7. Завершить работу программы" << endl;
}

int main() {
    int ch;
    Mlist *head=nullptr;
    Mlist *tail=nullptr;
    Menu();
    cin >> ch;
    switch(ch)
    {
        case 1:
            print(head ,tail);
            break;
        case 2:
            Add(&head);
            break;
        case 3:
            Delete();
