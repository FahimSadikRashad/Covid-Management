#include "Patient.h"
using namespace std;


    void  Patient::increment()
    {
        Patient_number++;
    }

    void Patient::check_symptoms()
    {
        float total=0.0;
        int  reply_;
        gotoxy(0, 3);
        cout << "\t\t Do you have fever(0/1)? -- ";
        cin >> reply_;
        total += reply_;
        cout << "\n\t\t Do you have cough(0/1)? -- ";
        cin >> reply_;
        total += reply_;
        cout << "\n\t\t Do you have tiredness(0/1)? -- ";
        cin >> reply_;
        total += reply_;
        cout << "\n\t\t Do you have loss of taste or smell(0/1)? -- ";
        cin >> reply_;
        total += reply_ * 0.5;
        cout << "\n\t\t Do you have sore throat(0/1)? -- ";
        cin>>reply_;
        total += reply_ * 0.5;
        cout << "\n\t\t Do you have headache(0/1)? --";
        cin>>reply_;
        total += reply_ * 0.5;

        system("cls");
        gotoxy(0, 1);
        cout << "\t     ******************************************************";
        gotoxy(0, 16);
        cout << "\t     ******************************************************";

        gotoxy(0, 2);
        cout << "\t     Do you have discolouration of fingers/toes(0/1)? -- ";
        cin>>reply_;
        total += reply_ * 0.5;
        cout << "\n\t     Do you have red/irritated eyes(0/1)? -- ";
        cin >> reply_;
        total += reply_ * 0.5;

        cout << "\n\t     Do you have difficulty/shortness of breath(0/1)? -- ";
        cin >> reply_;
        total += reply_ * 2;
        cout << "\n\t     Do you have loss of speech/mobility/confusion(0/1)? -- ";
        cin >> reply_;
        total += reply_ * 2;
        cout << "\n\t     Do you have chest pain(0/1)? -- ";
        cin >> reply_;
        total += reply_ * 2;
        percent=(total/9)*100;
        money_spent();
        vaccine();
    }

    void Patient::save_date()
    {
        d1.save_current_date();

    }
    void Patient::money_spent()
    {
        cout << "\n\t     Approx bills you spent/lost due to covid-19? -- ";
        cin >> money;
    }

    void Patient::vaccine()
    {
        cout << "\n\t     Do you vaccinated(0/1)? -- ";
        cin >> vaccinate;
    }

    void Patient::display()
    {
        save_date();
        gotoxy(23, 8);
        cout << "Percent " << percent << "% " << money << "$ " << d1.Convert_to_string() << " ";
        if(vaccinate)
            cout<<"vaccinated\n";
        else
            cout << "not vaccinated\n\n";
    }

    void  Patient::save_information_on_paitent(string s)
    {
       setFname("Paitien_info.txt");
       string temp=get_ID_based_user_name(s);

       add(temp);
       add(s);
       //set_user_name();
       add(to_string(percent));
       add(to_string(money));
       save_date();
       add(d1.Convert_to_string());
       add(to_string(vaccinate));
       add("");
    }

    void  Patient::save_req(string req_type, string update_type, string ID, string user_type)
    {
        transform(req_type.begin(), req_type.end(), req_type.begin(), ::tolower);
        setFname("Req_info.txt");
        add(ID);
        add(user_type);
        add(req_type);
        add(update_type);
        save_date();
        add(d1.Convert_to_string());
        add("");
    }

int Patient::Patient_number=0;
int Patient::percent=0;
int Patient::vaccinate=0;
int Patient::money=0;
Date Patient::d1;
