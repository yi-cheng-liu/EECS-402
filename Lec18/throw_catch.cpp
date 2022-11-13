const int TOO_LOW_TYPE = 1;
const int TOO_HIGH_TYPE = 2;
class IndexExcepClass
{
public:
    IndexExcepClass(int inType)
    {
        excepType = inType;
    }
    void print()
    {
        if (excepType == TOO_LOW_TYPE)
        {
            cout << "Index too low!";
        }
        else if (excepType == TOO_HIGH_TYPE)
        {
            cout << "Index too high!";
        }
    }

private:
    IndexExcepClass()
    {
        ;
    }
    int excepType;
};
void decrAryElem(int ary[], int ind)
{
    if (ind < MINARY)
        throw IndexExcepClass(TOO_LOW_TYPE);
    if (ind > MAXARY)
        throw IndexExcepClass(TOO_HIGH_TYPE);
    ary[ind]--;
}
From main : for (i = -1; i <= MAXARY + 1; i++)
{
    try
    {
        decrAryElem(myAry, i);
    }
    catch (IndexExcepClass iex)
    {
        iex.print();
        cout << endl;
    }
    cout << "Continuing!" << endl;
}