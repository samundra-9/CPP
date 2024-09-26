#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// unordered_set<int>idSet;
class TodoItem{
    private:
    int id;
    string description;
    bool completed;
    public:
    TodoItem(): id{0},description(""),completed(false) {}
    int create(string desc){
        description=desc;

        while(true){
        cout<<"provide priority of your task in number(1-20): ";
        // cin.clear();
        // cin.ignore();

        cin>>id;
        // if(idSet.find(id) == idSet.end()){
        //     idSet.insert(id);
        //     break;
        // }
        // else cout<<"Id already Taken \n";
        // }
        // return true;

        if(id >=1 && id <= 20){
            break;
        }
        else{
            cout<<"in between (1-20)"<<endl;

        }

    }
    return id;
    }
    void setCompleted(bool val) {completed =val;}
    int getId(){return id;}
    string getDescription(){return description;}
    bool isCompleted(){return completed;}
};

int main() {
    list<TodoItem>todoItems;
    char choice;
    int input_id;
    string input_description;

    todoItems.clear();
   // TodoItem test;
    //test.create("This is a test");
    //todoItems.push_back(test);

    while(true){
        system("clear"); //if clear not working try cls
        cout << "\t    -------TODO-LIST-MAKER-------" << endl<<endl;
        cout << "ID\tDescription\t\t\tCompleted"<<endl;
        cout<<"***************************************************"<<endl;

        if(choice != 's'){
        for(auto it=todoItems.begin(); it != todoItems.end(); it++){
            string completed = it->isCompleted() ? "Done" : "Not Done";
            cout<< it->getId() <<"\t"<<it->getDescription() << "\t\t\t"
             << completed <<endl;
        }
        }

        else{
            for(auto it=todoItems.begin(); it != todoItems.end(); it++){
            string completed = it->isCompleted() ? "Done" : "Not Done";
            if(it->isCompleted())
            cout<< it->getId() <<"\t"<<it->getDescription() << "\t\t\t"
             << completed <<endl;
        }

        }



        if(todoItems.empty()) cout<<"Add your first todo!\n";
        cout << "[a]dd Todo" << endl;
        cout << "[c]omplete Todo" << endl;
        cout << "[d]elete  Todo" << endl;
        cout << "[s]ee completeted Todo" << endl;
        cout << "[q]uit " <<endl;

        cout<<"Choice: ";
        
        cin>>choice;
        if ( choice == 'q') break;

        if (choice == 'a'){
            cout << "Add a description: ";
            cin.clear();
            cin.ignore();
            getline(cin,input_description);
            TodoItem newTodo;
            bool added=false;
           int id = newTodo.create(input_description);
            if(todoItems.empty()){
            todoItems.push_back(newTodo);
            added=true;
            }
            
            else{

                for(auto it=todoItems.begin(); it != todoItems.end(); it++){
            if(it->getId() >= id){
                todoItems.insert(it,newTodo);
                added=true;
            }
            }
            }
            if(!added) todoItems.push_back(newTodo);
        }
        if ( choice == 'c' ){
            cout<<"Enter Id to mark completed: ";
            cin >> input_id;

            for(auto it=todoItems.begin(); it != todoItems.end(); it++){
            if(it->getId() == input_id){
                it->setCompleted(true);
            }
        }
        }
        if( choice == 'd'){
             cout<<"Enter Id to delete task: ";
            cin >> input_id;

            for(auto it=todoItems.begin(); it != todoItems.end(); ){
            if(it->getId() == input_id){
               it =  todoItems.erase(it);
                // idSet.erase(input_id);
                break;
            }
            else it++;

        }
        }

        // break;
        
    }
    
    return 0;
    
}