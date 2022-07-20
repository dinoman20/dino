// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <map>
#include <fstream>
#include <wx/listbox.h>
#include <wx/defs.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif;

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyHome : public wxFrame {
public:
    MyHome();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnButtonClicked2(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl* box;
    wxTextCtrl* box1; //made public so that other function could acess it
    std::map<std::string, int> marks;
    std::map<int, std::string> check;
    int x;
};
enum
{
    ID_Hello = 1
};
enum
{
    ID_Button = 2
};
enum
{
    ID_BOX = 2
};
enum
{
    ID_Button1 = 3
};

class MyChat : public wxFrame {
public:
    MyChat();
private:
    void OnButtonClicked(wxCommandEvent& event);
    void OnButtonClicked2(wxCommandEvent& event);
    void Enter_Key(wxKeyEvent& event);
    DECLARE_EVENT_TABLE();
private:
    wxListBox* users;
    wxTextCtrl* tag;
    wxListBox* Chat;
    wxTextCtrl* box1;
};


// wsdinsd
wxIMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MyHome,wxFrame)
EVT_BUTTON(ID_Button, MyHome::OnButtonClicked)
EVT_BUTTON(ID_Button1, MyHome::OnButtonClicked2)
wxEND_EVENT_TABLE() //specified events like paint and button

wxBEGIN_EVENT_TABLE(MyChat, wxFrame)
EVT_BUTTON(101, MyChat::OnButtonClicked)
EVT_BUTTON(102, MyChat::OnButtonClicked2)
wxEND_EVENT_TABLE() //specified events like paint and button