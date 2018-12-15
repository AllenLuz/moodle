#include <cstring>
#include <iostream>

class String
{
private:
    char* _;
public:
    String(char const* c = "");
    String(String const& s);
    String& operator=(String const& s);
    std::ostream& show(std::ostream& o) const;
    ~String();
};

class Cd
{
private:
    String performers;
    String label;
    int selections;
    double playtime;
public:
    Cd(char const* s1, char const* s2, int n, double x);
    virtual void Report() const;
    Cd& operator=(Cd const& d);
};

class Classic : public Cd
{
private:
    String primaryWork;
public:
    Classic(char const* s0 = "", char const* s1 = "", char const* s2 = "", int n = 0, double x = 0);
    void Report() const;
    Classic& operator=(Classic const& d);
};

void Bravo(Cd const& disk);

std::ostream& operator<<(std::ostream& o, String const& s);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    std::cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    std::cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    std::cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

String::String(char const* c) : _(new char[std::strlen(c) + 1])
{
    strcpy(_, c);
}

String::String(String const& s) : _(new char[std::strlen(s._) + 1])
{
    strcpy(_, s._);
}

String& String::operator=(String const& s)
{
    if (this != &s)
    {
        delete[] _;
        _ = new char[std::strlen(s._) + 1];
        strcpy(_, s._);
    }
    return *this;
}

std::ostream& String::show(std::ostream& o) const
{
    return o << _;
}

String::~String()
{
    delete[] _;
}

Cd::Cd(char const* s1, char const* s2, int n, double x)
    : performers(s1), label(s2), selections(n), playtime(x)
{
}

void Cd::Report() const
{
    std::cout << performers << "," << label << "," << selections << "," << playtime << "\n";
}

Cd& Cd::operator=(Cd const& d)
{
    performers = d.performers;
    label = d.label;
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(char const* s0, char const* s1, char const* s2, int n, double x)
    : Cd(s1, s2, n, x), primaryWork(s0)
{
}

void Classic::Report() const
{
    std::cout << primaryWork << ",";
    Cd::Report();
}

Classic& Classic::operator=(Classic const& d)
{
    Cd::operator=(d);
    primaryWork = d.primaryWork;
    return *this;
}

void Bravo(Cd const& disk)
{
    disk.Report();
}

std::ostream& operator<<(std::ostream& o, String const& s)
{
    return s.show(o);
}
