#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack <string> history, redo_stack;
    string final_text = "", text="";
    int choice;

    do{
        start:
            cout << "SIMPLE TEXT EDITOR:\n1. Write text\n2. Delete text\n3. Undo changes\n4. Redo changes\n5. Exit Program" << endl;
            cin >> choice;

            switch(choice){
                case 1:
                    history.push(final_text);
                    cout << "Insert text >>>" << final_text;
                    cin.ignore();
                    getline(cin, text);
                    final_text.append(text);
                    break;
                case 2:
                    if(final_text.size() == 0){
                        cout << "There is nothing to be deleted." << endl;
                    }
                    else{
                        history.push(final_text);
                        final_text.erase(final_text.size()-1);
                        cout << final_text << endl;
                    }
                    break;
                case 3:
                    if(history.size() == 0){
                        cout << "There are no changes." << endl;
                    }
                    else{
                        redo_stack.push(final_text);
                        final_text = history.top();
                        history.pop();
                        cout << final_text << endl;
                    }
                    break;
                case 4:
                    if(redo_stack.size() == 0){
                        cout << "There are no changes." << endl;
                    }
                    else
                    {
                        final_text = redo_stack.top();
                        redo_stack.pop();
                        cout << final_text << endl;
                    }

        }
    }while(choice != 5);
    return 0;
}
