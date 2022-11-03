#include <iostream>
#include "BSTudents.h"
#include "GestaoHor.h"
#include <queue>
/**
 * Menu para user mode
 * @param requests
 * @param students
 * @param h
 */
void menuUsr(queue<vector<string>> *requests, BSTudents students, GestaoHor h,queue<vector<string>> *failedr) {
    bool canRun = true, changing = true;
    vector<string> temp;
    while(canRun) {
        string str, modo, tempuc;
        int input, id;
        cout << "What do you want to do?\n"
                "1: Remove UC\n"
                "2: Add UCs\n"
                "3: Change Classes\n"
                "4: Remove all UCs\n"
                "5: Check schedule of an UC\n"
                "6: Check full schedule\n"
                "0: Go back\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "What do you want to do?\n"
                    "1: Remove UC\n"
                    "2: Add UCs\n"
                    "3: Change Classes\n"
                    "4: Remove all UCs\n"
                    "5: Check schedule of an UC\n"
                    "6: Check full schedule\n"
                    "0: Go back\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                modo = "removeUC";
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                while(changing) {
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
                    cout << "Insert the UC you want to remove\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        cout << "Invalid UC\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);

                    requests->push(temp);
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep removing UCs?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep removing UCs?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }
                changing = true;
                break;
            case 2:
                modo = "addUC";
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                while(changing){
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
                    cout << "Insert the UC you want to join\n";
                    cin>>str;
                    tempuc = str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        cout << "Invalid UC\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);
                    cout << "Insert the class in the Uc you want to join\n";
                    cin>>str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidTurma(tempuc, str)){
                        cout << "Invalid Class\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);
                    requests->push(temp);
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep adding UCs?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep adding UCs?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }
                changing = true;
                break;
            case 3:
                modo = "changeTurma";
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                while(changing) {
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
                    cout << "Insert the UC of the class you want to change\n";
                    cin >> str;
                    tempuc = str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        temp.clear();
                        cout << "Invalid UC \n";
                        break;
                    }
                    temp.push_back(str);

                    cout << "Insert the class you want to change to\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidTurma(tempuc, str)){
                        temp.clear();
                        cout << "Invalid class \n";
                        break;
                    }
                    temp.push_back(str);
                    requests->push(temp);
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep changing classes?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep changing classes?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }
                changing = true;
                break;
            case 4:
                str = "removeAllUC";
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                temp.push_back(to_string(id));
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                requests->push(temp);
                temp.clear();
                cout << "Request registered!\n\n";
                break;
            case 5:
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert the UC you want to check the schedule of\n";
                cin>>str;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                if(!h.isValidUC(str)){
                    cout << "Invalid UC! \n";
                    break;
                }
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
                break;
            case 6:
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                students.showStudentHorario(id, h.getHorarios());
                break;
        }
    }
}
/**
 * Menu para ver as listagens
 * @param students
 * @param h
 */
void menuAdm(BSTudents students, GestaoHor h){
    bool canRun = true;
    int n;
    while(canRun){
        int input;
        cout << "Choose want you want to do: \n"
                "1: Show Student...\n"
                "2: Show every UCs, class and respective schedule\n"
                "3: \n"
                "0: Return\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose want you want to do: \n"
                   "1: Show Student...\n"
                   "2: Show every UCs, class and respective schedule\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                cout << "How do you want to see?\n"
                        "1: Every student ordered by Student ID\n"
                        "2: Every student ordered by Name\n"
                        "3: With more than n UCs\n";
                while(!(cin >> input)){
                    cout << "Invalid input!\n\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout <<"How do you want to see?\n"
                           "1: Every student ordered by Student ID\n"
                           "2: Every student ordered by Name\n"
                           "3: With more than n UCs\n";
                }
                if(input == 1) students.showAllStudentCodes();
                else if(input == 2) students.showAllStudentNames();
                else if(input == 3){
                    cout << "Input n: ";
                    cin >> n;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    students.showStudentsNUCs(n);
                    cout << "\n";
                }
                else cout << "Invalid input";
                break;
            case 2:
                h.showUCTandHorario();
                break;
            case 3:
                break;
        }
    }
}
/**
 * Menu para processar os pedidos relativos a mudanças de turmas, etc.
 * @param requests
 * @param students
 * @param h
 * @param failedr
 */
void processrequests(queue<vector<string>>*requests,BSTudents *students,GestaoHor *h,queue<vector<string>>*failedr){
    int size=requests->size();
    vector<string> temp;
    for(int it=0;it<size;it++){
        if(requests->front().front()=="removeUC"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            students->removeUC(id, Uccode, h);
        }
        else if(requests->front().front()=="addUC"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            string turma = requests->front()[3];
            if(!students->addUC(id, Uccode,turma, h)){
                cout << "Error while adding UC: " << Uccode << " in class " << turma << " to user: " << requests->front()[1] << ", " << students->getStudentName(id) << "\nRequest saved!\n\n";
                temp.push_back(requests->front().front());
                temp.push_back(requests->front()[1]);
                temp.push_back(requests->front()[2]);
                temp.push_back(requests->front()[3]);
                failedr->push(temp);
            }
        }
        else if(requests->front().front()=="changeTurma"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            string novaTurma = requests->front()[3];
            if(!students->changeTurma(id, Uccode, novaTurma, h)){
                cout << "Error while trying to change user " << requests->front()[1] << ", " << students->getStudentName(id) << " to class" << novaTurma << " in UC: " << Uccode << "\nRequest saved!\n\n";
                temp.push_back(requests->front().front());
                temp.push_back(requests->front()[1]);
                temp.push_back(requests->front()[2]);
                temp.push_back(requests->front()[3]);
                failedr->push(temp);
            }
        }
        else if(requests->front().front()=="removeAllUC"){
            int id = stoi(requests->front()[1]);
            students->removeAllUC(id, h);
        }
        requests->pop();
    }
}
/**
 * Menu principal. Inicializa as BSTs e outros objetos
 * @return
 */
int main() {
    GestaoHor h = GestaoHor();
    h.insertTurmas();
    h.insertSchedule();
    //cout<<"Insert File name with extension:";
    //string file;
    //cin>>file;
    string file="students_classes.csv";
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(&h,file); // insere todos os students
    queue<vector<string>> requests;
    queue<vector<string>> failedr;
    vector<string> temp;

    string str;
    int input1;
    bool canRun = true;
    while(canRun){
        cout << "Choose usage mode: \n"
                "1: User\n"
                "2: Listings\n"
                "3: Process requests\n"
                "0: Leave menu\n" << flush;
        while(!(cin >> input1)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose usage mode: \n"
                   "1: User\n"
                   "2: Listings\n"
                   "3: Process requests\n"
                   "0: Leave menu\n"<< flush;
        }
        switch(input1){
            case 0:
                canRun= false;
                break;
            case 1:
                menuUsr(&requests, students, h,&failedr);
                break;
            case 2:
                menuAdm(students, h);
                break;
            case 3:
                processrequests(&failedr,&students,&h,&failedr);
                processrequests(&requests,&students,&h,&failedr);
                students.output();
                break;
            default:
                cout << "Invalid input!\n\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
        }
    }


    return 0;
}

/*Falta:
 * Ordenação de Listagens
 * debug
 * */