#include <iostream>
#include <string>

struct Node{
    std::string data;
    Node *link;
};

class Lilist{
    public: 
    Lilist(){head = NULL;}
    void add(std::string item);
    void show();
    Node* search(std::string target);
    void move_front_to_back();

    private:
    Node *head;
};

void Lilist::add(std::string item){
    Node * tmp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> link = NULL;
    }else{
        for(tmp = head; tmp -> link != NULL; tmp = tmp -> link);  //advances pointer to last node in list
        tmp ->link = new Node;
        tmp = tmp -> link;
        tmp -> data = item;
        tmp -> link = NULL;
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> link)
        std::cout<<tmp->data<<"    ";
}
Node* Lilist::search(std::string target){
    Node * temp;
    std::string searching;
    for(temp = head; temp != NULL; temp = temp -> link){
        searching = temp -> data;
        if(searching.find(target) < std::string::npos){
            return temp;
        }
    }
    return NULL;
}

void Lilist::move_front_to_back(){
    Node * temp;
    Node * temp2;
    temp = head;
    head = head -> link;
    for(temp2 = head; temp2 -> link != NULL; temp2 = temp2 -> link);
    temp2 -> link = temp;
    temp2 = temp2 -> link;
    temp2 -> link = NULL;

}