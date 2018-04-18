//
// Created by jachfili on 18.04.18.
//

#include "Comparable.h"

namespace academia
{

    bool StudentComparator::operator()(const Student &left, const Student &right)
    {
        return IsLess(left,right);
    }


    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) {
        return left.FirstName()<right.FirstName();
    }

    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) {
        return left.FirstName()>right.FirstName();
    }
    bool academia::ByLastNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
        return left.LastName()<right.LastName();
    }

    bool academia::ByLastNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
        return left.LastName()>right.LastName();
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) {
        if(left.Program()=="")
        {
            return false;
        }
        if(right.Program()=="")
        {
            return true;
        }
        return left.Program()<right.Program();
    }
    bool ByProgramAscendingEmptyFirst::IsLess(const academia::Student &left, const academia::Student &right) {
        return left.Program()<right.Program();
    }
}
