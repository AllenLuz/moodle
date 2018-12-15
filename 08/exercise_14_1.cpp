#include <iostream>
#include <valarray>

class Wine
{
    typedef std::valarray<int> ArrayInt;
    typedef std::pair<ArrayInt, ArrayInt> PairArray;
private:
    std::string name;
    PairArray yearCounts;
public:
    Wine(char const* l, int y);
    Wine(char const* l, int y, int const* yr, int const* bot);
    void GetBottles();
    std::string const& Label() const;
    void Show() const;
    int sum() const;
};

int main()
{
    std::cout << "Enter name of wine: \n";
    char lab[50];
    std::cin.getline(lab, 50, '\r');
    std::cin.get();
    std::cout << "Enter number of years: \n";
    int yrs;
    std::cin >> yrs;
    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();
    int const YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    std::cout << "Total bottles for " << more.Label()
              << ": " << more.sum() << "\nBye\n";
    return 0;
}

Wine::Wine(char const* l, int y) : name(l), yearCounts(ArrayInt(y), ArrayInt(y))
{
}

Wine::Wine(char const*l, int y, int const* yr, int const* bot)
    : name(l), yearCounts(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

void Wine::GetBottles()
{
    int size = yearCounts.first.size();
    std::cout << "Enter " << name << " data for " << size << " year(s): \n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter year: \n";
        std::cin >> yearCounts.first[i];
        std::cout << "Enter bottles for that year: \n";
        std::cin >> yearCounts.second[i];
    }
}

std::string const& Wine::Label() const
{
    return name;
}

void Wine::Show() const
{
    std::cout << "Wine: " << name << "\n        Year    Bottles\n";
    for (size_t i = 0; i < yearCounts.first.size(); ++i)
    {
        std::cout << "        " << yearCounts.first[i] << "    "
                  << yearCounts.second[i] << "\n";
    }
}

int Wine::sum() const
{
    return yearCounts.second.sum();
}
