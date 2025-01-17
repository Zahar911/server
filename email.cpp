#include <iostream>
#include <string>
#include<cmail.h>

bool sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) {
    std::string command = "echo \"" + body + "\" | mail -s \"" + subject + "\" " + recipient;
    int result = system(command.c_str());
    return result == 0;
}

int main() {
    std::string recipientEmail = "zahargorlukovich@gmail.com"; // Замените на email получателя
    std::string subject = "Test Email from C++";
    std::string body = "This is a test email sent from C++ using system call.";

    if (sendEmail(recipientEmail, subject, body)) {
        std::cout << "Email sent successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to send email." << std::endl;
    }
    return 0;
}