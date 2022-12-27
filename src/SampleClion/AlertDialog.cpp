#include <iostream>
#include <cstring>
#include "AlertDialog.hpp"

AlertDialog &AlertDialog::setTitle(const char *title)
{
    std::strcpy(m_title, title);
    return *this;
}

AlertDialog &AlertDialog::setText(const char *text)
{
    std::strcpy(m_text, text);
    return *this;
}
AlertDialog &AlertDialog::setButton(AlertDialogButton button)
{
    m_button = button;
    return *this;
}

AlertDialog &AlertDialog::setIcon(AlertDialogIcon icon)
{
    m_icon = icon;
    return *this;
}

void AlertDialog::show() const
{
    static const char *buttons[] {"None", "YesNo", "YesNoCancel", "Ok"};
    static const char *icons[]{"None", "Information", "Warning", "Critical", "Question"};

    if (m_title[0] != '\0')
        std::cout << "Title:" << m_title << '\n';

    if (m_text[0] != '\0')
        std::cout << "Text:" << m_text << '\n';

    if (m_button != AlertDialogButton::None)
        std::cout << "Button:" << buttons[static_cast<int>(m_button)] << '\n';

    if (m_icon != AlertDialogIcon::None)
        std::cout << "Icon:" << icons[static_cast<int>(m_icon)] << '\n';
}