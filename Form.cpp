#include <iostream>
#include <string>
#include <chrono>
#include <algorithm> 
#include <cctype>   
//#include"D:\new apps\smtp\send_mes.cpp"

struct KeyIndex
{
    std::string name_key;
    int number_key;

};

struct Forms {
    std::string user_Name;
    std::string user_NumberPhone;
    std::string user_Email; 
    std::string user_IndexNumberPassport; 
};

class DATA_USER_FORM {
public:
    Forms get_user_data() {
        Forms forms;
        forms.user_Name = get_user_name();
        forms.user_NumberPhone = get_user_phone_number();
        forms.user_Email = get_email();
        forms.user_IndexNumberPassport = get_user_pas();
        return forms;
    }
    KeyIndex get_data()
    {

        KeyIndex k_i;
        k_i.name_key = get_user_name();
        k_i.number_key = n_key();
    }

private:

    int n_key()
    {
        int key = 0;
        return key++;

    }

    std::string get_email() {
        std::string email;
        while (true) {
            std::cout << "������� ����� ����������� �����:";

            if (std::getline(std::cin, email) && email.length() >= 10) {
                if ("@gmail.com" == email) {
                    break;
                }
            }
            else {
                std::cout << "������� ��� ���:\n";
            }
        }
    }

    std::string get_user_name() {
        std::string userName;
        while (true) {
            std::cout << "������� ��� (��� ������ ����� 3 ���� ����� ��������):\n";
            std::getline(std::cin, userName);
            if (userName.length() >= 3) {
                userName[0] = std::toupper(userName[0]); 
                break;
            }
            else {
                std::cout << "��� ������ ��������� ������ 3 ��������.\n";
            }
        }
        n_key();
        return userName;
    }

    std::string get_user_phone_number() {
        std::string phoneNumber;
        while (true) {
            std::cout << "������� ����� ��������( ����� ������ ���������� � �����+):\n";
            std::getline(std::cin, phoneNumber);
            if (phoneNumber.length() > 0 && phoneNumber[0] == '+') {
                bool valid = true;
                for (size_t i = 1; i < phoneNumber.length(); ++i) {
                    if (!isdigit(phoneNumber[i])) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    break;
                }
                else {
                    std::cout << "�� ������ ������ ������ ��������.������� ��� ��� ����� ��������.\n";
                }
            }
            else {
                std::cout << "����� ������ �������� �� ����� '+'.\n";
            }
        }
        return phoneNumber;
    }

    //������� ��������
    std::string get_user_pas()
    {
        std::string pas;
        while (true) {
            std::cout << "������� ��������������� ����� ��������:";
            std::getline(std::cin, pas);

            if (pas.length() == 13) {
                break;
            }
            else {
                std::cout << "�� ������ ������ ����������������� �����. ��������� �������:";
            }
        }


        return pas;

    }
};


int main() {
    DATA_USER_FORM data_user_form;

    Forms user_data = data_user_form.get_user_data();

    std::cout << "��� ������������: " << user_data.user_Name << std::endl;
    std::cout << "����� ������������: " << user_data.user_NumberPhone << std::endl;
    std::cout << "����� ����������� �����: " << user_data.user_Email << std::endl;
    std::cout << "��������������� ����� ��������: " << user_data.user_IndexNumberPassport << std::endl;

    return 0;
}