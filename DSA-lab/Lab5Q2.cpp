#include <iostream>
#include <string>
using namespace std;

class PrintJob {
public:
    int jobId;
    string documentName;
    int pages;
    string owner;

    PrintJob() : jobId(0), pages(0) {}

    PrintJob(int jobId, string documentName, int pages, string owner)
    : jobId(jobId), documentName(documentName), pages(pages), owner(owner) {}

};

// ======== PrintQueue CLASS ========
class PrintQueue {
private:
    struct Node {
        PrintJob data;
        Node* next;
        Node(PrintJob job) {
            data = job;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;
    static int nextJobId;
    public:
    PrintQueue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    // Add a new job to queue
    void enqueue(const string& docName, int pages, const string& owner) {
        PrintJob job;            // Step 1: Create an empty object
        job.jobId = nextJobId++; // Step 2: Assign fields manually
        job.documentName = docName;
        job.pages = pages;
        job.owner = owner;

        Node* newNode = new Node(job);
        if (isEmpty())
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << " Job " << job.jobId << " (" << job.documentName << ") added to queue.\n";
    }

    // Remove front job (simulate printing)
    void processNext(double pagesPerMin = 10.0) {
        if (isEmpty()) {
            cout << " No jobs to print.\n";
            return;
        }

        Node* temp = front;
        PrintJob job = temp->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;

        cout << "Printing Job " << job.jobId << " (" << job.documentName
             << ")... completed (" << job.pages << " pages)\n";
    }

    // Remove job from middle by ID
    bool removeById(int id) {
        if (isEmpty()) return false;

        Node* temp = front;
        Node* prev = nullptr;

        while (temp && temp->data.jobId != id) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return false; // not found

        if (temp == front) front = front->next;
        else prev->next = temp->next;

        if (temp == rear) rear = prev;

        delete temp;
        return true;
    }

    // Display queue contents
    void display() const {
        if (isEmpty()) {
            cout << " Queue is empty.\n";
            return;
        }

        cout << "\n--- Pending Print Jobs ---\n";
        cout << "JobID | Document | Pages | Owner\n";
        cout << "----------------------------------\n";

        Node* cur = front;
        while (cur!=NULL) {
            cout << cur->data.jobId << " | " 
                 << cur->data.documentName << " | "
                 << cur->data.pages << " | "
                 << cur->data.owner << endl;
            cur = cur->next;
        }
    }

    // Calculate total pages in queue
    int totalPages() const {
        int total = 0;
        Node* cur = front;
        while (cur) {
            total += cur->data.pages;
            cur = cur->next;
        }
        return total;
    }
};

// initialize static job counter
int PrintQueue::nextJobId = 100;

// ======== UNIT TEST STYLE MAIN ========
int main() {
    PrintQueue pq;

    cout << "=== Test 1: Enqueue jobs ===\n";
    pq.enqueue("Thesis.pdf", 25, "Ali");
    pq.enqueue("Invoice.docx", 5, "Sara");
    pq.enqueue("Resume.pdf", 2, "Hassan");
    pq.display();

    cout << "\n=== Test 2: Total pages ===\n";
    cout << "Total pages in queue: " << pq.totalPages() << "\n";

     cout << "\n=== Test 3: Remove middle job (Invoice.docx) ===\n";
    bool removed = pq.removeById(101);
    cout << (removed ? " Job 101 removed successfully.\n" : " Job not found.\n");
    pq.display();

    cout << "\n=== Test 4: Process (print) next job ===\n";
    pq.processNext();
    pq.display();

    cout << "\n=== Test 5: Process remaining jobs ===\n";
    pq.processNext();
    pq.processNext();
    pq.display();

    cout << "\n=== Test 6: Remove non-existent job ===\n";
    bool removed2 = pq.removeById(999);
    cout << (removed2 ? "Unexpected: job removed!" : "Correct: job not found.") << endl;

    cout << "\n=== Test 7: Queue after all jobs processed ===\n";
    pq.display();

    cout << "\n=== Test Complete  ===\n";
    return 0;
}