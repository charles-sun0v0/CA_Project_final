from m5.SimObject import SimObject
from BaseEnergySM import BaseEnergySM
from m5.params import *
from m5.proxy import *

class Dfs_SM(BaseEnergySM):
    type = 'Dfs_SM'
    cxx_header = "engy/dfs_sm.hh"
    thres_conv = Param.Float(Parent.thres_conv, "convert threshold of energy state machine")
    thres_off = Param.Float(Parent.thres_off, "off threshold of energy state machine")