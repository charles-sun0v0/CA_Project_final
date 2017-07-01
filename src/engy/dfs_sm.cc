//
// Created by sunc 2017-6-30.
//

#include "dfs_sm.hh"
#include "debug/EnergyMgmt.hh"

Dfs_SM::Dfs_SM(const Params *p)
    : BaseEnergySM(p), state(Dfs_SM::State::STATE_INIT),
      thres_conv(p->thres_conv), thres_off(p->thres_off)
{

}

void Dfs_SM::init()
{
    state = Dfs_SM::State::STATE_POWEROFF;
    EnergyMsg msg;
    msg.val = 0;
    msg.type = MsgType::POWEROFF;
    broadcastMsg(msg);
}

void Dfs_SM::update(double _energy)
{
    EnergyMsg msg;
    msg.val = 0;

    if (state == STATE_INIT) {
        state = STATE_HIGHFREQ;
    } else if (state == STATE_LOWFREQ && _energy < thres_off) {
        DPRINTF(EnergyMgmt, "State change: low_freq->off state=%d, _energy=%lf, thres_off=%lf\n", state, _energy, thres_off);
        state = STATE_POWEROFF;
        msg.type = MsgType::POWEROFF;
        broadcastMsg(msg);
    } else if (state == STATE_LOWFREQ && _energy>= thres_conv) {
        DPRINTF(EnergyMgmt, "State change: low_freq->high_freq  state=%d, _energy=%lf, thres_convert=%lf\n", state, _energy, thres_conv);
        state = STATE_HIGHFREQ;
        msg.type = MsgType::HIGHFREQ;
        broadcastMsg(msg);
    } else if (state == STATE_HIGHFREQ && _energy< thres_conv){
        DPRINTF(EnergyMgmt, "State change: high_freq->low_freq  state=%d, _energy=%lf, thres_convert=%lf\n", state, _energy, thres_conv);
        state = STATE_LOWFREQ;
        msg.type = MsgType::LOWFREQ;
        broadcastMsg(msg);
    } 
}

Dfs_SM *
Dfs_SMParams::create()
{
    return new Dfs_SM(this);
}
