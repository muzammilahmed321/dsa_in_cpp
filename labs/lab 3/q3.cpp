#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

class Call {
public:
    int id;
    int arrivalTime;
    string customerName;

    Call(int _id, int _arrivalTime, string _name)
        : id(_id), arrivalTime(_arrivalTime), customerName(_name) {}
};

class CallCenter {
private:
    queue<Call> callQueue;
    int numCSRs;
    vector<bool> csrAvailable;

public:
    CallCenter(int numCSRs) {
        this->numCSRs = numCSRs;
        csrAvailable = vector<bool>(numCSRs, true);
    }

    void addCall(const Call& call) {
        cout << "New call added: " << call.customerName << " (ID: " << call.id << ")\n";
        callQueue.push(call);
    }

    void processCalls() {
        while (!callQueue.empty()) {
            for (int i = 0; i < numCSRs; ++i) {
                if (csrAvailable[i] && !callQueue.empty()) {
                    Call call = callQueue.front();
                    callQueue.pop();
                    csrAvailable[i] = false;

                    cout << "CSR #" << i + 1 << " is handling call from "
                         << call.customerName << " (ID: " << call.id << ")\n";

                    thread t(&CallCenter::completeCall, this, i, call);
                    t.detach();
                }
            }


            this_thread::sleep_for(chrono::seconds(1));
        }
    }

private:
    void completeCall(int csrIndex, Call call) {
        this_thread::sleep_for(chrono::seconds(3));
        csrAvailable[csrIndex] = true;

        cout << "CSR #" << csrIndex + 1 << " completed call from "
             << call.customerName << " (ID: " << call.id << ")\n";
    }
};
int main() {
    CallCenter center(3);

    center.addCall(Call(1, 0, "muzafar"));
    center.addCall(Call(2, 1, "uzair"));
    center.addCall(Call(3, 2, "tafseer"));
    center.addCall(Call(4, 3, "muzammil"));
    center.addCall(Call(5, 4, "saad"));

    center.processCalls();

    return 0;
}

