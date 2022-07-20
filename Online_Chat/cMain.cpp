#include "main.h"


bool MyApp::OnInit()
{
    MyHome* frame = new MyHome();
    frame->Show(true);
    return true; //what runs the function 
}
MyHome::MyHome() : wxFrame(NULL, wxID_ANY, "Sign In", wxDefaultPosition, wxSize(500,500))
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar); //random set menau bar exaple
    Bind(wxEVT_MENU, &MyHome::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyHome::OnExit, this, wxID_EXIT);
    wxString  text = wxT("Sign In"); // string and input text
    wxStaticText* st = new wxStaticText(this, wxID_ANY, text, wxPoint(235, 10), wxDefaultSize, wxALIGN_CENTRE);
    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, L"Username: ", wxPoint(40, 40), wxDefaultSize, wxALIGN_CENTRE);
    wxStaticText* st2 = new wxStaticText(this, wxID_ANY, L"Password: ", wxPoint(40, 100), wxDefaultSize, wxALIGN_CENTRE);
    box = new wxTextCtrl(this, ID_BOX,L"",wxPoint(100, 40), wxSize(200, 50));
    box1 = new wxTextCtrl(this, wxID_ANY, L"", wxPoint(100, 100), wxSize(200, 50));
    wxButton* button = new wxButton(this, ID_Button, L"Sign in", wxPoint(100, 160), wxSize(50, 25)); //butons
    wxButton* button1 = new wxButton(this, ID_Button1, L"Create Account", wxPoint(100, 200), wxSize(88, 25));
}
void MyHome::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyHome::OnHello(wxCommandEvent& event)
{   

    MyChat* frame = new MyChat();
    Close(true);
    frame->Show(true);
}

void MyHome::OnButtonClicked(wxCommandEvent& event)
{
    wxString yourStr;
    wxString yourStr1;
    yourStr = box->GetValue();
    yourStr1 = box1->GetValue();
    std::fstream file;
    std::string user;
    int u;
    file.open("username.txt", std::ios::in);
    if (file.is_open()) {
        std::string tp;
        std::string st;
        int x = 0;
        int p = 0;
        while (std::getline(file, tp)) {
            if (p % 2 == 1) {
                x = std::stoi(tp);
                p++;
               
            }
            else {
                st = tp;
                p++;
            }
            marks[st] = x;
        }
        file.close();
    }
    file.open("password.txt", std::ios::in);
    if (file.is_open()) {
        std::string tp;
        std::string st;
        int x = 0;
        int p = 0;
        while (std::getline(file, tp)) {
            if (p % 2 == 0) {
                x = std::stoi(tp);
                p++;

            }
            else {
                st = tp;
                p++;
            }
            check[x] = st;
        }
        file.close();
    }
    user = yourStr;
    u = marks[user];
    if (yourStr.size() == 0 || yourStr1.size() == 0) {
        wxMessageBox(wxT("Input a username or password"));
    }
    else if (check[u] == yourStr1) {
        wxMessageBox(wxT("CORRECT"));
        MyChat* frame = new MyChat();
        Close(true);
        frame->Show(true);
    }
    else {
        wxMessageBox(wxT("Account information wroung"));
    }
}
void MyHome::OnButtonClicked2(wxCommandEvent& event)
{
    int max = 1000;
    int x;
    wxString yourStr;
    wxString yourStr1;
    yourStr = box->GetValue();
    yourStr1 = box1->GetValue();
    std::string ystr;
    ystr = yourStr;
    srand(time(0));
    x = rand() % max;
    std::ofstream file;
    if (yourStr.size() == 0 || yourStr1.size() == 0) {
        wxMessageBox(wxT("Username or Password Invalid"));
    }
    else {
        file.open("username.txt", std::ios::app);
        file << ystr << std::endl;
        file << std::to_string(x) << std::endl;
        file.close();
        file.open("password.txt", std::ios::app);
        file << std::to_string(x) << std::endl; 
        file << yourStr1 << std::endl;
        file.close();
        wxMessageBox(wxT("Created"));
    }

}


MyChat::MyChat() : wxFrame(NULL, wxID_ANY, "Chat", wxDefaultPosition, wxSize(1000, 600))
{
    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, L"Users: ", wxPoint(20, 0), wxSize(35, 20), wxALIGN_CENTRE);
    box1 = new wxTextCtrl(this, wxID_ANY, L"", wxPoint(300, 480), wxSize(400, 80));
    users = new wxListBox(this, wxID_ANY, wxPoint(5, 30), wxSize(80, 400));
    wxStaticText* st2 = new wxStaticText(this, wxID_ANY, L"Input a Tag: ", wxPoint(900, 5), wxSize(80, 20), wxALIGN_CENTRE);
    tag = new wxTextCtrl(this, wxID_ANY, L"",wxPoint(900, 26), wxSize(80, 50));
    wxButton* button = new wxButton(this, 101, L"Input", wxPoint(915, 80), wxSize(50, 25));
    Chat = new wxListBox(this, wxID_ANY, wxPoint(120, 50), wxSize(750, 400));
    wxButton* button1 = new wxButton(this, 102, L"Enter", wxPoint(700, 500), wxSize(60, 60));
}


void MyChat::OnButtonClicked(wxCommandEvent& event)
{
    wxString tags;
    tags = tag->GetValue();
    if (tags.size() < 2) {
        wxMessageBox(wxT("Input a tag with more characters"));
    }
    else {
        users->AppendString(tags);
    }

}
void MyChat::OnButtonClicked2(wxCommandEvent& event) {
    wxString tags;
    wxString message;
    tags = tag->GetValue();
    message = box1->GetValue();
    if (tags.size() == 0) {
        wxMessageBox(wxT("Input a tag"));
    }
    if (message.size() == 0) {
        wxMessageBox(wxT("Input a message"));
    }
    else {
        Chat->AppendString(tags +"- " + message);
    }
}