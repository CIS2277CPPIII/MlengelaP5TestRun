/*********************************************************************
* Program: Linked List
* Programmer: Daudi Mlengela(dmlengela@cnm.edu)
* Date: March 14th 2023
* Purpose: Program 5 linked list
**********************************************************************/

#include"PersonGen.h"
#include"PersonNode.h"
#include"ListMgr.h"
#include"ScriptReader.h"

void WriteHeader();
void GoodBye();
int main()
{
    WriteHeader();
    // create a new ListMgr object
    ListMgr* lm = new ListMgr();
    PersonGen pg;
    pg.UseFile("P5LinkedListPeopleNov6.txt");
    ScriptReader reader("P5TestScript.txt");

    string outputFileName("MyOutputFile.txt");
    std::ofstream out(outputFileName);

    if (!out)
    {
        std::cout << "Could not open: " << outputFileName << "\n";
        return(1);
    }
    do
    {
        int number = reader.GetNextInt();

        if (number < 1 || number > 12)
        {
            std::cout << "Invalid input: " << number << "\n";
            out << "Invalid input: " << number << "\n";
            continue;
        }

        out << "number: " << number << "\n";

        //bool doShow = true;

        if (number == 1)
        {
            lm->Show();
        }
        else if (number == 2)
        {
            lm->Push_front(pg.GetNewPerson());
        }
        else if (number == 3)
        {
            lm->Push_back(pg.GetNewPerson());
        }
        else if (number == 4)
        {
            lm->Pop_front();
        }
        else if (number == 5)
        {
            lm->Pop_back();
        }
        // When number is 6 ==>
        else if (number == 6)
        {
            lm->Remove(reader.GetNextString());
        }
        else if (number == 7)
        {
            Person* p = lm->Front();

            if (p)
            {
                std::cout << p->GetName() << "\n";
                out << p->GetName() << "\n";
            }
            else
            {
                std::cout << "N/A\n";
                out << "N/A\n";
            }

            //doShow = false;
        }
        else if (number == 8)
        {
            Person* p = lm->Back();

            if (p)
            {
                std::cout << p->GetName() << "\n";
                out << p->GetName() << "\n";
            }
            else
            {
                std::cout << "N/A\n";
                out << "N/A\n";
            }

            //doShow = false;
        }
        // When the number is 9 erase
        else if (number == 9)
        {
            int pos = reader.GetNextInt();
            // cout and output
            std::cout << "Erasing node at position" << pos;
            out << "Erasing node at position " << pos;
            lm->Erase(pos);
            lm->Erase(reader.GetNextInt());
        }
        // When the number is 10 - Clear the list
        else if (number == 10)
        {
            lm->Clear();
            lm->Show();
            out << lm->ShowString();
        }
        // When the number is 11 we need to get the size of the list
        else if (number == 11)
        {
            std::cout << "size: " << lm->Size() << "\n";
            out << "size: " << lm->Size() << "\n";

            //doShow = false;
        }
        else
        {
            break;
        }

        //if (doShow)
        //out << lm->ShowString() << "\n";
    } while (true);
    GoodBye();
    return 0;
}

void WriteHeader()
{
    std::cout << "---------------------------------------\n";
    std::cout << "C++ Program Five, Part Two\n";
    std::cout << "---------------------------------------\n\n";
}

void GoodBye()
{
    std::cout << "\n\nThanks for watching my Program\n";

}
