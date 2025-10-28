#include <bits/stdc++.h>
using namespace std;

class converter
{
    private:
    vector<pair<char,string>> codes = {
            {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
            {'E', "."},    {'F', "..-."}, {'G', "--."},  {'H', "...."},
            {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
            {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."},
            {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
            {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
            {'Y', "-.--"}, {'Z', "--.."},
            {'0', "-----"},{'1', ".----"},{'2', "..---"},{'3', "...--"},
            {'4', "....-"},{'5', "....."},{'6', "-...."},{'7', "--..."},
            {'8', "---.."},{'9', "----."},
            {'.', ".-.-.-"},{',', "--..--"},{'?', "..--.."},{'\'', ".----."},
            {'!', "-.-.--"},{'/', "-..-."},{'(', "-.--."},{')', "-.--.-"},
            {'&', ".-..."},{':', "---..."},{';', "-.-.-."},{'=', "-...-"},
            {'+', ".-.-."},{'-', "-....-"},{'_', "..--.-"},{'"', ".-..-."},
            {'$', "...-..-"},{'@', ".--.-."},
            {' ', "/"}
        };

    public:
            void string_to_morse()
            {
                string sentence;
                cout<<"============================= (String to Morse Converter) ============================="<<endl;
                cout<<"Enter the string => "<<endl;
                if(!(getline(cin,sentence)))
                return;

                transform(sentence.begin(),sentence.end(),sentence.begin(), :: toupper);

                string s = "";

                for (int i = 0; i < sentence.size(); i++)
                {
                    for(auto p : codes)
                    {
                        if(sentence[i]==p.first)
                        {
                            s+=p.second + " ";
                            break;
                        }
                    }
                }
                cout << " Original Text: " << sentence << endl;
                cout << " Morse Output : " << s << endl;
            }

            void morse_to_string()
            {
                string morse;
                cout<<"============================= (Morse to string converter) ============================="<<endl;
                cout<<"Enter the Morse code => ";
                if(!(getline(cin,morse)))
                return;

                string s = "",temp = "";

                for(int i = 0; i<=morse.size(); i++)
                {
                    if(i<morse.size() and morse[i]!=' ')
                    temp+=morse[i];

                    else
                    {
                        if(temp.empty()) continue;
                        if(temp == "/")
                        s+=' ';
                        else{
                            bool found = false;
                            for(auto p : codes)
                            {
                                if(temp==p.second)
                                {
                                    s+=p.first;
                                    found = true;
                                    break;
                                }
                            }
                            if(!found)
                            s+="?";
                        }
                        temp = "";
                    }
                }

                cout << " Morse         : " << morse << endl;
                cout << " String Output : " << s << endl;
            }

            void file_morse_to_string()
            {
                ifstream fin("input.txt");
                ofstream fout("output_string.txt");

                if(!fin or !fout)
                {
                    cout<<"No file input detected "<<endl;
                    return;
                }

                string morse;
                getline(fin,morse);

                transform(morse.begin(), morse.end(), morse.begin(), ::toupper);

                string s ="",temp ="";

                for (int i = 0; i <= morse.size(); i++)
                {
                    if(i<morse.size() and morse[i]!=' ')
                    temp+=morse[i];

                    else
                    {
                        if(temp=="/")
                        s+=' ';
                        else
                        {
                            bool ok = false;
                                for(auto p : codes)
                                {
                                    if(temp == p.second)
                                    {
                                        s+=p.first;
                                        ok = true;
                                        break;
                                    }
                                }
                                if(!ok)
                                s+='?';
                            }
                        temp = "";
                    }
                }
                fout<<s<<endl;
                cout<<"File is decoded in output_string.txt"<<endl;
                cout<<endl;
            }

            void string_to_morse_file()
            {
                ifstream fin("input1.txt");
                ofstream fout("output.txt");

                if(!fin or !fout)
                {
                    cout<<"Invalid File"<<endl;
                    return;
                }

                string sentence;
                
                getline(fin,sentence);

                transform(sentence.begin(),sentence.end(),sentence.begin(),::toupper);

                string s ="";

                for (int i = 0; i < sentence.size(); i++)
                {
                    for(auto p : codes)
                    {
                        if(sentence[i]==p.first)
                        {
                            s+=p.second +" ";
                            break;
                        }
                    }
                }
                fout<<s<<endl;
                cout<<"Decoded file at output.txt"<<endl;
                cout<<endl;
            }

            void showHelp() 
            {
                cout << " Morse Code Legend:"<<endl;
                cout << " Letters separated by spaces"<<endl;;
                cout << " Words separated by '/'"<<endl;
                cout << " Unknown tokens will show as '?'"<<endl;
                cout << " Example: .... . .-.. .-.. --- / .-- --- .-. .-.. -.."<<endl;
            }

};

int main()
{
    converter a;

    while (true)
    {
        cout << "\n=====================================" << endl;
        cout << "        Morse Code Converter        " << endl;
        cout << "=====================================\n" << endl;
        cout<<"Choose Operation                     "<<endl;
        cout<<"(1) Morse to string                  "<<endl;
        cout<<"(2) String to Morse                  "<<endl;
        cout<<"(3) Morse to string (file)           "<<endl;
        cout<<"(4) String to morse (file)           "<<endl;
        cout<<"(5) Help                             "<<endl;
        cout<<"(6) Exit                             "<<endl;
        
        int choose;
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
        case 1:
            a.morse_to_string();
            break;
        case 2:
            a.string_to_morse();
            break;
        case 3:
            cout<<"============================= (Morse to string converter (File) ) ============================="<<endl;
            a.file_morse_to_string();
            break;
        case 4:
            cout<<"============================= (String to Morse converter (File) ) ============================="<<endl;
            a.string_to_morse_file();
            break;
        case 5:
            a.showHelp();
            break;
        case 6:
            break;
        default:
            break;
        }
    }

}
