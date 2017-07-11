#ifndef __PARAMS__Dfs_SM__
#define __PARAMS__Dfs_SM__

class Dfs_SM;

#include <cstddef>
#include <cstddef>

#include "params/BaseEnergySM.hh"

struct Dfs_SMParams
    : public BaseEnergySMParams
{
    Dfs_SM * create();
    double thres_conv;
    double thres_off;
};

#endif // __PARAMS__Dfs_SM__
