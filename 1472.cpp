#include <iostream>
#include <vector>

using namespace std;

class HomePage{
public:
    // attributes
    string homepage;
    HomePage *next;
    HomePage *prev;

    // constructor
    HomePage(string homepage){
        this->homepage = homepage;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class BrowserHistory {
public:
    // attributes
    HomePage* head;
    HomePage* current;
    // HomePage* tail;
    
    // constructor
    BrowserHistory(string homepage) {
        head = new HomePage("dummy");
        // tail = new HomePage("dummy");
        current = new HomePage(homepage);

        head->next = current;
        current->prev = head;
        // current->next = tail;
        // tail->prev = current;
    }
    
    void visit(string url) {
        HomePage *newNode = new HomePage(url);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
        // tail->previous->next = newNode;
        // newNode->previous = tail->previous;
        // newNode->next = tail;
        // tail->previous = newNode; 
    }
    
    string back(int steps) {
        while (current->prev != head && steps>0){
            if (steps == 0){
                return current->homepage;
            }
            current = current->prev;
            steps -= 1;
        }
        return current->homepage; // because when we reach here, current=head.
    }
    
    string forward(int steps) {
        while (current->next != nullptr && steps>0){
            if (steps == 0){
                return current->homepage;
            }
            current = current->next;
            steps -= 1;
        }
        return current->homepage; // because when we reach here, current=head.
    }

    void printAll(){
        HomePage *cur = head->next;
        while (cur != nullptr){
            std::cout << cur->homepage << "->";
            cur = cur->next;
        }
        std::cout << "\n";
    }
    void printCurrent(){
        std::cout << current->homepage << "\n";
    }
};

int main(){
    BrowserHistory *browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");       
    browserHistory->visit("facebook.com");     
    browserHistory->visit("youtube.com"); 
    browserHistory->printAll();

    browserHistory->back(1); 
    browserHistory->printCurrent();   
    browserHistory->back(1);  
    browserHistory->printCurrent();  

    browserHistory->forward(1);     
    
    std::cout << "\n";

    browserHistory->visit("linkedin.com");   


    browserHistory->forward(2);
    browserHistory->forward(5);   
          
    browserHistory->back(2);   
    browserHistory->back(7);

    return 0;
}