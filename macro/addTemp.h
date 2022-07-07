//
// Created by root on 22-7-7.
//

#ifndef LINUX_PROGRAMMING_ADDTEMP_H
#define LINUX_PROGRAMMING_ADDTEMP_H

#ifdef _T_
#ifdef __addname
_T_ __addname(_T_ a, _T_ b) {
    return (a + b);
}
#endif
#endif
#undef _T_
#undef __addname

#endif //LINUX_PROGRAMMING_ADDTEMP_H
