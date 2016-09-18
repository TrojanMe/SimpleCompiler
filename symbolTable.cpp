
/* Offline 01 : HashTable */

#include<cstdio>
#include<cstdlib>
#include<iostream>

#include<fstream>
#include<cstring>

using namespace std;

const int TABLE_SIZE = 128;

/* class symbolInfo */

class symbolInfo
{
    public:

        string  key;
        string value;

        symbolInfo* next;

        symbolInfo(string key, string value)
        {
            this->key = key;
	        this->value = value;
	        this->next = NULL;
        }
};


/* class symbolTable */

class SymbolTable
{
    private:
        symbolInfo** hashT;

    public:

        SymbolTable()
        {
            int i;
            hashT = new symbolInfo*[TABLE_SIZE];
            for (i = 0; i < TABLE_SIZE; i++)
            {
                hashT[i] = NULL;
            }

        }

        ~SymbolTable()
         {
            int i;
            for (i = 0; i < TABLE_SIZE; ++i)
	        {
                symbolInfo* entry = hashT[i];
                while (entry != NULL)
	            {
                    symbolInfo* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] hashT;
         }

/* Hash function */

    int HashFunction(string key)
    {
        int current =0 ;
        int sum=0 ;

        while(key[current]!='\0')
        {
            sum+= key[current]-'0';
            current++;
        }
        return sum % TABLE_SIZE;
    }

/* Insert Elements  */

    void Insert(string key, string value)
    {
        int hashValue = HashFunction(key);
        symbolInfo* prev = NULL;
        symbolInfo* entry = hashT[hashValue];

        while (entry != NULL)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL)
        {
            entry = new symbolInfo(key, value);
            if (prev == NULL)
            {
                hashT[hashValue] = entry;
            }
            else
            {
                prev->next = entry;
            }
        }

    }

/* Delete Elements  */

    void Delete(string key)
    {
        int hashValue = HashFunction(key);
        symbolInfo* entry = hashT[hashValue];
        symbolInfo* prev = NULL;
        if (entry == NULL )
        {
            return;
        }
        while (entry != NULL)
        {
            if(entry->key == key)
            {
               break;
            }
            prev = entry;
            entry = entry->next;
        }

        if(prev != NULL)
        {
            prev->next = entry->next;
            cout << "Deleted" << endl;
            delete entry;
            delete prev;
            return;
        }
        else
        {
            hashT[hashValue] = entry->next;
            cout << "Deleted" << endl;
            delete entry;
            delete prev;
            return;
        }

        delete entry;
        delete prev;

        cout << "Element could not be deleted" << endl;
        return;
    }

/*  Look Up an element */

    bool LookUp(string key)
    {
        bool flag = false;
        int hashValue = HashFunction(key);
        symbolInfo* entry = hashT[hashValue];

        while (entry != NULL)
        {
            if (entry->key == key)
            {
                cout<<entry->value<<" ";
                flag = true;
            }
            entry = entry->next;

        }
            return flag;
    }

/* Print Symbol Table */

    void Print()
    {
        for(int i=0; i < TABLE_SIZE ; i++)
        {
            symbolInfo* current_node = hashT[i];
            if(current_node == NULL)
                {
                    continue;
                }

            else
               {
                cout << i << " --> " ;

                while(current_node != NULL)
                {
                    cout << "<" <<  current_node->key << "," << current_node->value << ">" << "  " ;
                    current_node = current_node->next;
                }
                cout << endl;
               }
        }
     }
};

 /* int main() function */

int main()
{
    string inputs[10000];

    ifstream file;
    file.open("input.txt");
    if(!file.is_open())
    {
      cout << "Error : 404 Can't open file";
    }

    else
    {
        int i=0;
        string in;
        while(file >> in)
            inputs[i++]=in;

        SymbolTable* s = new SymbolTable();

        int j;
        for(j=0; j<i ; j++)
        {
            if(inputs[j]=="L")
            {
                if(s->LookUp(inputs[j+1]))
                    cout << "Exists in symbol table" << endl;
                else
                    cout << "Doesn't exist in symbol table" << endl;

                j++;
            }

            if(inputs[j]=="I")
            {
                s->Insert(inputs[j+1] , inputs[j+2]);
                j = j+2 ;
            }

            if(inputs[j]=="P")
            {
                s->Print();
            }

            if(inputs[j]=="D")
            {
                s->Delete(inputs[j+1]);
                j++;
            }
        }

    }
  return 0;
}
