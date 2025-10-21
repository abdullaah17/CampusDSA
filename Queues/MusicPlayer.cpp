#include<iostream>
#include<string>
using namespace std;

struct Song{
    string title;
    Song*next;
    Song(string title){
        this->title=title;
        this->next=NULL;
    }
};
class Playlist{
    Song* head;
    Song* tail;
    public:
    Playlist(){
        head = tail = NULL;
    }
    void addSong(string title){
        Song* newSong = new Song(title);
        if(head==NULL){
            head = tail = newSong;
            tail->next = head; // Circular Link
        }else{
            tail->next = newSong;
            tail = newSong;
            tail->next = head; // Attaches the new tail to head to maintain the Link
        }
        cout<<"Added: "<<title<<endl;
    }
    void removeSong(){
        if(head==NULL){ // For Empty playlist
            cout<<"Empty Playlist!"<<endl;
        }
        if(head == tail){
            cout<<"Removed:"<<head->title;
            delete head;
            head = tail = NULL;
        }
        else{
            Song*temp = head;
            cout << "Removed: " << temp->title << endl;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
void showPlaylist() {
    cout<<"Current Playlist:"<<endl;
    if (head == nullptr) {
        cout << "Empty Playlist\n";
        return;
    }

    Song* temp = head;
    do {
        cout << temp->title << endl;
        temp = temp->next;
    } while (temp != head);
}
};
int main(){
    Playlist P1;
    P1.addSong("Abd");
    P1.addSong("Abd");
    P1.addSong("Abd");
    P1.addSong("Abd");
    P1.showPlaylist();
    return 0;
}