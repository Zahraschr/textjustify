#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> // for color

using namespace std;

//---------global---------
ifstream in_File;
ofstream out_File;
fstream temp_file1;
fstream temp_file2;
string inname;
string outname;

//---------function-------
void openin();
void open_out();
void open_temp1();
void open_temp2();
void Open_All();
void close_All();
void Dot_End_Paragraf();
void Fix_Paragraph();
bool serch(int a,string str); //Bray Yaftan Paragraph.
void Edit();
void capitalization();
void fix_spacing();
void Depression_paragraf();
void letters_count();
void Shomaresh();
void words_count ();
void sentens_count ();
void shomaresh_parageraf();
void Helo();
void My_show_befor();
void My_show_After();
void justify(int n,bool right = false);
void rang(int a=3);
//------------------------

int main()
{
    Helo();
    Open_All();
    Edit();
    My_show_After();
    Shomaresh();
    close_All();
    return 0;
}

void justify(int n,bool right)
{
    string line,word,out;
    int count = 0;
    temp_file1.open("temp2.txt",ios::out);
    temp_file2.open("temp1.txt",ios::in);
    while(getline(temp_file2,line))
    {
        out = "    ";
        count = 4;
        stringstream LINE (line);
        while(LINE >> word)
        {
            count += word.length() + 1;
            if (count < n) out += word + " ";
            else
            {
                if(right) for (int i = 0; i < n-out.length(); i++)
                {
                    temp_file1 << " ";
                    out_File << " ";
                }
                temp_file1 << out << '\n';
                out_File << out << '\n';
                out = "";
                out += word + " ";
                count = word.length();
            }
        }

        temp_file1 << out << endl;
        out_File << out << endl;
        count = 0;
    }
    temp_file1.close();
    temp_file2.close();
}

void openin()
{
    cout<<"please Enter Address of in file (for example: D:\\Project\\test.txt) :"<<endl;
    getline(cin,inname);
    in_File.open(inname,ios::in);
    while(!in_File)
    {
        rang();
        openin();

    }

}

void open_out()
{

    
    cout<<"please Enter Address of out file (for example: D:\\Project\\test.txt) :"<<endl;
    getline(cin,outname);
    out_File.open(outname,ios::out);
    while(!out_File)
    {
        rang();
        open_out();
    }
}

void Open_All()
{
    openin();
    open_out();
    open_temp1();
    open_temp2();
}

void close_All()
{
    in_File.close();
    out_File.close();
}

void open_temp1()
{
    temp_file1.open("./temp1.txt",ios::out);

    if(!in_File)
    {
        cout<<"error";
    }

}

void open_temp2()
{
    temp_file2.open("./temp2.txt",ios::out);
    if(!in_File)
    {
        cout<<"error";
    }

}

void Dot_End_Paragraf()
{
    My_show_befor();
    string str;
    while (getline(in_File,str))
    {
        cout<<str<<endl;          //braye namayesh code qabl az ejra zaman run barname.
        long int a;
        a=str.length();
        if(str[a-1]=='.')
        {
            str=str+'\n';                   // Akhar paragraph (.) darad pas edame midahad.
            temp_file1<<str;
        }

        else
        {
            if(serch(a,str)==1)
               {
                  str=str+'.'+'\n';        // Akhar paragraph (.) ndarad pas (.) gozashte va edame midahad.
                  temp_file1<<str;
               }
            else
            {
                str=str+'\n';              // Paragraf nist va edame midahad.
                temp_file1<<str;
            }

        }

    }
    temp_file1.close();


}

bool serch(int a,string str)
{
    string big ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string low ="abcdefghijklmnopqrstuvwxyz";

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(str[i]==big[j] || str[i]==low[j] )
                return 1;                                   //agar character dasht 1 return mikonad.
        }

    }
    return 0;

}

void Fix_Paragraph()
{
    temp_file1.open("./temp1.txt",ios::in);
    string str;
    while(getline(temp_file1,str))
    {
        long int a;
        a=str.length();
        if(serch(a,str)==0)
            continue;
        else
        {
            str=str+'\n';
            temp_file2<<str;
        }

    }
    temp_file2.close();
    temp_file1.close();

}

void Edit()
{
    cout << "Please Choose an Alignment Method:\n\n";
    cout << "1. Align Left        2. Align Right\n";
    cout << "  -----------               ------- \n";
    cout << "  ------                   -------- \n";
    cout << "  ---------             ----------- \n";
    cout << "  ----                     -------- \n";
    cout << "  -------                    ------ \n";
    string inp;
    string max;
    cin >> inp;
    cout << "Please Enter Max Characters of a line:\n";
    cin >> max;
    Dot_End_Paragraf();
    Fix_Paragraph();
    capitalization();
    fix_spacing();
    Depression_paragraf();
    if(inp == "2") justify(stoi(max),true);
    else justify(stoi(max));

}

void capitalization()
{
    temp_file1.open("./temp1.txt",ios::out);
    temp_file2.open("./temp2.txt",ios::in);
    string str;
    while (getline(temp_file2,str))
    {
        int a;
        string str1 = "abcdefghijklmnopqrstuvwxyz";
        string str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        a=str.length();
        for(int i=0; i<26; i++)
        {
            if (str[0]==str1[i])
            {
                str[0]=str2[i];
            }
        }
        str=str+'\n';
        temp_file1<<str;

    }
    temp_file1.close();
    temp_file2.close();
}

void fix_spacing()
{
    temp_file1.open("temp1.txt",ios::in);
    temp_file2.open("temp2.txt",ios::out);
    string r,s;
    while(getline(temp_file1,s))
    {
        for (int i = 0; i < s.length() - 1; i++)    //barresie kalamate jomle
        {
            if (s[i] == ' ' && (s[i+1] == '.' || s[i+1] == ',' || s[i+1] == ';' || s[i+1] == '!' || s[i+1] == '?' || s[i+1] == ' '))
                continue; //hazfe space ezafe ghabl az punctuations
            r += s[i];
            if (s[i+1] != ' ' && (s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == '!' || s[i] == '?'))
                r += ' '; // ijade space baad az punctuations
        }
        r += s[s.length() - 1];
        r=r+'\n';
    }

    temp_file2<<r;

    temp_file1.close();
    temp_file2.close();


}

void Depression_paragraf()
{
    temp_file1.open("temp2.txt",ios::in);
    temp_file2.open("temp1.txt",ios::out);
    string str;
    for(int i=1;!temp_file1.eof();i++)
    {
         getline(temp_file1,str);
         str.insert(0,"   ");
         str=str+'\n';
         temp_file2<<str;
        //  out_File<<str;
    }
    temp_file1.close();
    temp_file2.close();
}

void Shomaresh()
{
    letters_count();
    words_count ();
    sentens_count ();
    shomaresh_parageraf();
}

void letters_count()                     //shomaresh harf
{
    ifstream temp ("temp2.txt");
    long long int majmooe=0;
    string s;
    while(temp >> s) 
    {
        majmooe += s.length();
    }
    out_File<<"Tedad Horoof="<<majmooe<<endl;
    cout<<"Tedad Horoof="<<majmooe<<endl;
    temp_file1.close();
    temp.close();
}

void  words_count ()                   //shamaresh kalame
{
    temp_file1.open("temp2.txt",ios::in);
    string str;
    long long int majmooe=0;
    while(temp_file1 >> str) if(str.length()>1) majmooe ++;
    out_File<<"Tedad Kalamat="<<majmooe<<endl;
    cout<<"Tedad Kalamat="<<majmooe<<endl;
    temp_file1.close();
}

void sentens_count ()                  //shomaresh jomle
{
    temp_file1.open("temp1.txt",ios::in);
    string snt;
    long long int majmooe=0;
    while(getline(temp_file1,snt))
    {
        int s_count=0;
        for(int i=0; i<=snt.length() ;i++)
        {
            if(snt[i]=='.')
                s_count++;
        }
        majmooe=majmooe+s_count;
    }
     out_File<<"Tedad Jomalat="<<majmooe<<endl;
     cout<<"Tedad Jomalat="<<majmooe<<endl;
     temp_file1.close();
}

void shomaresh_parageraf()              //shomaresh paragraph
{
    temp_file1.open("temp1.txt",ios::in);
    string str;
    long long int majmooe=0;
    while(getline(temp_file1,str))
    {
        int num=0;
        num++;
        majmooe=majmooe+num;
    }
    majmooe=majmooe-1;
    out_File<<"Tedad Paragraph="<<majmooe<<endl;
    cout<<"Tedad Paragraph="<<majmooe<<endl;
    temp_file1.close();
}

void Helo()
{
    Sleep(700);
    cout<<"     Hello. Welcome to Project c++ in Group G24 ."<<endl;
    Sleep(1500);
    cout<<"     Names of Group's Members : 1- Alireza Rahimi  2- Mohammad Reza Salim Khani"<<endl;
    cout<<"     3- Sarina Davoodi  4- Zahra Siah Chehre. "<<endl;
    Sleep(3000);
    cout<<"     Please wait for the program to run"<<endl;
    Sleep(2000);
    system("color f1");
    Sleep(2000);
}

void My_show_befor()
{
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"-------------------------Befor-------------------------"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
}

void My_show_After()
{
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"-------------------------After-------------------------"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    temp_file1.open("temp2.txt",ios::in);
    string str;
    while(getline(temp_file1,str))
        cout<<str<<endl;

}

void rang(int a)
{
    cout<<"Error"<<endl;
    for(int i=0;i<a ;i++)
    {
        system("color 4f");
        Sleep(500);
        system("color f4");
        Sleep(500);
    }
    system("color f1");
}

