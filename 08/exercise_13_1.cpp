#include <cstring>
#include <iostream>

class Cd
{
private:
    char performers[50];
    char label[20];
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
    char primaryWork[40];
public:
    Classic(char const* s0 = "", char const* s1 = "", char const* s2 = "", int n = 0, double x = 0);
    void Report() const;
    Classic& operator=(Classic const& d);
};

void Bravo(Cd const& disk);

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

Cd::Cd(char const* s1, char const* s2, int n, double x)
    : selections(n), playtime(x)
{
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
}

void Cd::Report() const
{
    std::cout << performers << "," << label << "," << selections << "," << playtime << "\n";
}

Cd& Cd::operator=(Cd const& d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(char const* s0, char const* s1, char const* s2, int n, double x)
    : Cd(s1, s2, n, x)
{
    std::strcpy(primaryWork, s0);
}

void Classic::Report() const
{
    std::cout << primaryWork << ",";
    Cd::Report();
}

Classic& Classic::operator=(Classic const& d)
{
    Cd::operator=(d);
    std::strcpy(primaryWork, d.primaryWork);
    return *this;
}

void Bravo(Cd const& disk)
{
    disk.Report();
}
