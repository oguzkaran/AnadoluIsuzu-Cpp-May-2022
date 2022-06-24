#ifndef ALERTDIALOG_HPP_
#define ALERTDIALOG_HPP_

enum class AlertDialogButton {None, YesNo, YesNoCancel, Ok};
enum class AlertDialogIcon {None, Information, Warning, Critical, Question};

class AlertDialog {
private:
    char m_title[512]{};
    char m_text[1024]{};
    AlertDialogButton m_button{AlertDialogButton::Ok};
    AlertDialogIcon m_icon{AlertDialogIcon::None};
public:
    AlertDialog &setTitle(const char *title);
    AlertDialog &setText(const char *text);
    AlertDialog &setButton(AlertDialogButton button);
    AlertDialog &setIcon(AlertDialogIcon icon);
    void show() const;
};


#endif //ALERTDIALOG_HPP_
