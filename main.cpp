#include <iostream>
using namespace std;

struct Mlist{
    int a;
    Mlist *next;
};

void print(Mlist *head){
    while(head!=nullptr){
        cout<<head->a<<" ";
        head=head->next;
    }
}

void add( Mlist *&head ,Mlist *&tail) {
    int b,c;
    cout<<"введите количесвто желаемых объектов "<<endl;
    cin>>b;
    Mlist *p=head;
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
        cout <<curr->a<<"->";
        curr = curr->next;
    }
    cout<<"end"<<endl;
}

void Delete(Mlist *&head,Mlist *&tail){
    int n;
    cout<<"введите элемент,который хоотите удалить";
    cin>>n;
    Mlist *curr=head;
    Mlist *prev;
    while(curr!=nullptr){
        if(curr->a==n && curr==head){
            head=curr->next;
            delete curr;
            return;
        }
        prev=curr;
        curr=curr->next;
        if(curr->a==n && curr!=head && curr!=tail)
        {
            prev->next=curr->next;
            delete curr;
            return;
        }
        if(curr->a==n && curr==tail)
        {
            tail=prev;
            tail->next=nullptr;
            delete curr;
            return;
        }
    }
}

void Find(Mlist *&head){
    Mlist *curr = head;
    int a = 0;
    int c = 0;
    cout << "введите элемент ,который хотите найти: ";
    cin >> a;
    while (curr != nullptr)
    {
        if (curr->a == a)
        {
            cout << "позиция: " << c << " ";
        }
        else cout<<"error"<<endl;
        c++;
        curr = curr->next;
    }
    cout << endl;
}

void Replace(Mlist *&head){
    Mlist *curr = head;
    int value=0;
    int pos=0;
    int c=0;
    cout<<" введите то,на что выхотите поменять и позицию";
    cin>>value>>pos;
    while (curr != nullptr)
    {
        c++;
        if (pos==c){
            curr->a=value;
            return;
        }
        curr=curr->next;

    }
    cout<<endl;
}

void Sort(Mlist *&head){
    for(Mlist *curr=head; curr!=nullptr; curr=curr->next) {
        for(Mlist *curr1=head; curr1!=nullptr; curr1=curr1->next) {
            if((curr->a)<(curr1->a)) {
                swap(curr->a,curr1->a);

            }
        }
    }
}

void deleteList(Mlist *head){
    if (head!= nullptr){
        deleteList(head->next);
        delete head;
    }
}

void Menu()
{
    cout << "операции:" << endl;
    cout << "1. вывести" << endl;
    cout << "2. добавить элементы" << endl;
    cout << "3. удалить элементы" << endl;
    cout << "4. Найти позиции элементов"<< endl;
    cout << "5. Заменить элемент на другой"<< endl;
    cout << "6. Отсортировать элементы списка"<< endl;
    cout << "7. удаление списка"<<endl;
    cout << "8. Завершить работу программы" << endl;
}

int main() {
    int ch;
    Mlist *head = nullptr;
    Mlist *tail = nullptr;
    while (true) {
        Menu();
        cin >> ch;
        switch (ch) {
            case 1:
                print(head);
                break;
            case 2:
                add(head, tail);
                break;
            case 3:
                Delete(head, tail);
                break;
            case 4:
                Find(head);
                break;
            case 5:
                Replace(head);
                break;
            case 6:
                Sort(head);
                break;
            case 7 :
                deleteList(head);
                break;
            case 8:
                return 0;
            default:
                cout<<"error comand"<<endl;

        }
    }
    return 0;
}
