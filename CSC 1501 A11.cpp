

#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string; 
using std::vector;
int main()
{
    int num, rem, count, bin = 0;
    count = 0;
    vector<int> arr;


    string ham; string message;
    string s1, s2, s4;
    int parity;

    while (count < 5) {
        cin >> num;
        cout << num << endl;
        //decimal to binary. for loop to add 1's,0's to a vector then taking those values and changing my hamming message by adding 3 0's.
        while (arr.size() != 4) {
            if (num % 2 != 0) {
                while ((num % 2) != 0) {
                    rem = num % 2;
                    arr.push_back(rem);
                    num = num / 2;
                }
            }
            else {
                rem = num % 2;
                if (rem == 0) {
                    while (rem == 0) {
                        arr.push_back(0);
                        rem = num % 2;
                        num /= 2;
                    }
                }
                else {
                    while (rem > 0) {
                        rem = num % 2;
                        arr.push_back(rem);
                        num /= 2;
                    }
                }
            }
            arr.insert(arr.begin(), 0);
            bin++;
        }
        

        for (int i : arr) {
            if (arr[i] == 0) {
                ham += '0';
            }
            else {
                ham += '1';
            }
        }
        //giving my binary number some security
        ham.insert(ham.begin(), '0'); ham.insert(ham.begin()+1, '1'); ham.insert(3, "1");
        cout << "The message recieved is: ";
        cout << ham << endl;
        //hamming code cracker
        int checker = 0;
        s1 = ham[0]; s1 += ham[2]; s1 += ham[4]; s1 += ham[6];
        s2 = ham[1]; s2 += ham[2]; s2 += ham[5]; s2 += ham[6];
        s4 = ham[3]; s4 += ham[4]; s4 += ham[5]; s4 += ham[6];
        //First Parity
        for (int i = 0; i < s1.length(); i++) {
            checker += (int(s1.at(i)) - 48);
        }
        if (checker % 2 == 0) {
            parity = 0;
        }
        else {
            parity = 1;
        }
        checker = 0;
        //Second Parity
        for (int i = 0; i < s2.length(); i++) {
            checker += int(s2.at(i)) - 48;
        }
        if (checker % 2 == 0) {
            parity += 0;
        }
        else {
            parity += 2;
        }
        checker = 0;
        //Fourth Parity
        for (int i = 0; i < s4.length(); i++) {
            checker += int(s4.at(i)) - 48;
        }
        if (checker % 2 == 0) {
            parity += 0;
        }
        else {
            parity += 4;
        }
        if (parity > 0) {
            cout << "There is an incorrect message at index " << parity << endl;
            if (ham[parity - 1] == 0) {
                ham[parity - 1] = '1';
            }
            else {
                ham[parity - 1] = '0';
            }
        }
        else {
            cout << "Message is correct: ";
        }
        message.push_back(ham[2]); message.push_back(ham[4]); message.push_back(ham[5]); message.push_back(ham[6]);
        cout << message << endl;
        count++;
        ham.clear(); message.clear(); s1.clear(); s2.clear(); s4.clear(); arr.clear();
    }
}
