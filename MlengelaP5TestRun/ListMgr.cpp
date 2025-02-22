/*********************************************************************
* Program: Linked List
* Programmer: Daudi Mlengela(dmlengela@cnm.edu)
* Date: March 14th 2023
* Purpose: Program 5 linked list
**********************************************************************/

#include "ListMgr.h"

void deletePersonNode(PersonNode *node)
{
   std::cout << "deleting PersonNode ...\n";
   Person *thePerson = node->GetPerson();
   delete(node);
   delete(thePerson);
}

ListMgr::ListMgr() : first{nullptr}, last{nullptr}{}
void ListMgr::Push_front(Person *p)
{
   ++count;
   PersonNode *ptr = new PersonNode();
   ptr->SetPerson(p);

   if(first == nullptr)
   {
      first = last = ptr;
   }
   else if(first == last)
   {
      last->SetPrev(ptr);
      ptr->SetNext(last);
      first = ptr;
   }
   else
   {
      first->SetPrev(ptr);
      ptr->SetNext(first);
      first = ptr;
   }
}

void ListMgr::Push_back(Person *p)
{
   ++count;
   PersonNode *ptr = new PersonNode();
   ptr->SetPerson(p);

   if(first == nullptr)
   {
      first = last = ptr;
   }
   else if(first == last)
   {
      first->SetNext(ptr);
      ptr->SetPrev(first);
      last = ptr;
   }
   else
   {
      last->SetNext(ptr);
      ptr->SetPrev(last);
      last = ptr;
   }
}
// Remove the first PersonNode

void ListMgr::Pop_front()
{
    // check if the list is empty
    if (Empty()) {
        return;
    }
   --count;
   if(first == last)
   {
      deletePersonNode(first);
      first = last = nullptr;
      return;
   }

   PersonNode *next = first->GetNext();
   next->SetPrev(nullptr);
   deletePersonNode(first);
   first = next;
}

void ListMgr::Pop_back()
{
    if (Empty()) {
        return;
    }
   --count;
   if(first == last)
   {
      deletePersonNode(last);
      first = last = nullptr;
      return;
   }

   PersonNode *prev = last->GetPrev();
   prev->SetNext(nullptr);
   deletePersonNode(last);
   last = prev;
}

Person *ListMgr::Front()
{
   if(first == nullptr)
      return(nullptr);

   return(first->GetPerson());
}

Person *ListMgr::Back()
{
   if(last == nullptr)
      return(nullptr);

   return(last->GetPerson());
}

bool ListMgr::Empty()
{
    if (count == 0) {
        return true;
    }
    return false;
}

void ListMgr::Remove(string n)
{
   if (Empty()) {
		return;
	}
    
    bool go = true;

   while(go)
   {
      int position = 1;
      bool found   = false;

      PersonNode *ptr = first;

      while(ptr)
      {
         if(ptr->GetPerson()->GetName().find(n) != string::npos)
         {
            //std::cout << n << " found in " << ptr->GetPerson()->GetName() << "\n";
            found = true;
            Erase(position);
            break;
         }

         ptr = ptr->GetNext();
         position++;
      }

      if(!found)
         go = false;
   }
}

void ListMgr::Erase(int pos)
{
   //std::cout << "Erase(" << pos << ")\n";

   if(pos > count)
      return;

   if(pos == 1)
   {
      Pop_front();
      return;
   }

   if(pos == count)
   {
      Pop_back();
      return;
   }

   PersonNode *ptr = first;
   int position    = 1;

   while(ptr)
   {
      if(position == pos)
         break;

      position++;
      ptr = ptr->GetNext();
   }

   // ptr points at the node to remove

   PersonNode *prev = ptr->GetPrev();
   PersonNode *next = ptr->GetNext();

   prev->SetNext(next);
   next->SetPrev(prev);

   deletePersonNode(ptr);
   --count;
}

void ListMgr::Clear()
{
   PersonNode *ptr = first;

   while(ptr)
   {
      PersonNode *next = ptr->GetNext();
      deletePersonNode(ptr);
      ptr = next;
   }

   first = last = nullptr;
   count = 0;
}

void ListMgr::Show()
{
   std::cout << ShowString() << "\n";
}

string ListMgr::ShowString()
{
   std::ostringstream out;

   out << "number in list: " << Size() << "\n";

   PersonNode *ptr = first;
   int i = 0;

   while(ptr)
   {
      if(i % 3 != 0)
         out << "::";

      out << ptr->GetPerson()->GetName();
      ptr = ptr->GetNext();

      if(ptr == nullptr || i % 3 == 2)
         out << "\n";

      i++;
   }

   return(out.str());
}

ListMgr::~ListMgr()
{
   Clear();
}
