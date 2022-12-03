//Interfejs
//Celowo napisany nieefektywnie
#include <iostream>

class Ilist
{
    public:
        __property int Count = {read = GetCount};
        virtual int Add(void* Data) = 0;
        virtual void Del(int Index) = 0;
        virtual int IndesxOf(void* Data) = 0;
    protected:
        virtual int GetCount(void) = 0;
};


struct TlistItem
{
    void* Data;
    TlistItem* Next;
};

class TOneDirList : public Ilist
{
    private:
        TlistItem* FFirst;
    protected:
        int GetCount(void);
    public:
        int Add(void* Data);
        void Del(int Index);
        int IndexOf(void* Data);
        TOneDirList(void);
        ~TOneDirList(void);
};

TOneDirList::TOneDirList(void)
{
    FFirst = NULL;
}

TOneDirList::~TOneDirList(void)
{
    while( GetCount()) Del(0);
}

int TOneDirList::Add(void* Data)
{
    TlistItem* NewItem = new TlistItem();
    NewItem->Next = FFirst;
    NewItem->Data = Data;
    FFirst=NewItem;
    return GetCount();
}

void TOneDirList::Del(int Index)
{
    TlistItem* Item = FFirst;
    TlistItem* Prev = NULL;
    while(Index--){
        Prev = Item;
        Item = Item->Next;
    }

    delete Item;

    if(Prev)
        Prev->Next=Item -> Next;
    else {
        FFirst = Item -> Next;
    }

    delete Item;
}

int TOneDirList::GetCount(void)
{
    int LCount=0;
    TlistItem* Item = FFirst;
    while(Item)
    {
        ++LCount;
        Item = Item->Next;
    }
    return LCount;
}

int main(void)
{
    using std::cout;
    Ilist* L = new TOneDirList();

    //L->Add(?);
    L->Del(0);
    cout << L->Count;
    L->Count = 3; // Błąd kompilacji
}
