#include <iostream>
#include <string>

using namespace std;

class HelpfulMath
{
    private:
        string A;
    public:
        HelpfulMath(string s)
        {
            A = s;
        }
        //~HelpfulMath();
        string Rearrange();
};
string HelpfulMath::Rearrange()
{
    int *numbers = new int [A.length()];
    int index = 0;
    for(char c : A)
    {
        if(c != '+')
            numbers[index++] = c - '0'; 
    }
    for(int j = 0; j < index - 1; j++)
    {
        for(int k = j+1; k < index; k++ )
        {
            if(numbers[j] > numbers[k])
            {
                int tmp = numbers[j];
                numbers[j] = numbers[k];
                numbers[k] = tmp;
            }
        }
    }
    string new_sum;
    for (int i = 0; i < index; i++)
    {
        new_sum += to_string(numbers[i]);
        if (i != index - 1)
        {
            new_sum += '+';
        }
    }
    delete[] numbers;
    return new_sum;
}
int main()
{
    string s;
    cin >> s;
    HelpfulMath hm(s);
    string result = hm.Rearrange();
    cout << result << endl;
}