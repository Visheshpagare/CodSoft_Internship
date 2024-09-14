#include<iostream>
using namespace std;
#include<ctime>
int main()
{
    std::srand(std::time(0));
    int randomnumber = std::rand()%100+1;
    int userGuesse =0;
    cout<<"Guesse the number between 1 to 100):";
    while (true) {
        cin>>userGuesse;
        if(userGuesse > randomnumber )
        {
            cout<<"Too high Try again: ";
        }
        else if(userGuesse < randomnumber )
        {
            cout<<"Too low ! Try again :";
        } else {
            cout<<"Congratulations ! You guessed The correct number"<<endl;
            break;
        }
    }
    return 0;
}