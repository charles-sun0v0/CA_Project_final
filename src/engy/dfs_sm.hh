//
// created by sunc in 2017/06/30
//

#ifndef GEM5_DFS_SM_HH
#define GEM5_DFS_SM_HH

#include "state_machine.hh"
#include "params/Dfs_SM.hh"

class Dfs_SM : public BaseEnergySM
{

public:
    typedef Dfs_SMParams Params;
    const Params *params() const
    {
        return reinterpret_cast<const Params *>(_params);
    }
    Dfs_SM(const Params *p);
    ~Dfs_SM() {}
    virtual void init();
    virtual void update(double _energy);

    enum State {
        STATE_INIT = 0,
        STATE_POWEROFF = 1,
        STATE_LOWFREQ = 2,
        STATE_HIGHFREQ = 3,
    };

    enum MsgType {
        CONSUMEENERGY = 0,
        POWEROFF = 1,
        LOWFREQ = 2,
        HIGHFREQ = 3,
    };

protected:
    State state;
    double thres_conv;
    double thres_off;

};
#endif //GEM5_DFS_SM_HH_
