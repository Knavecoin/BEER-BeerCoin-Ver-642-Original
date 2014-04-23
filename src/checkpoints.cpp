// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 BeerCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
//(0, uint256("0x"))
(0,      uint256("0x1fa5fbc2bb19fe4b2bde0952d379ba49656eb87a1b9e4eddc00001e7166760d8"))
(8797,   uint256("0x70045bd87f3501d1f95a82b49a6f4cc780c3bcbab50f8e9eb0c011bcf5901ae4"))
(20347,  uint256("0x876d253acdaf20ecd1762a92c26715a6cad1bfcce28f50d11ebcb675782eb7c4"))
(49683,  uint256("0x1a810a1b38591a461fe108774fab63c78327c1645d44d81c5710df69dcbd524c"))
(85402,  uint256("0x447c7ea7e88b59449fad6da9497903620e91a413a7c365b5e6dd161e70ec4759"))
(146406, uint256("0x2785e70b3fd1f8a6daee4005bbb52fdb9c002e07c39f030a2bb631b4711c7106"))
(224062, uint256("0xa7d54d3f63ac28273bf67b2a27660af5fc1e79390286497387d673bcdd5a5f32"))
(275833, uint256("0xb8a5fa0f61a5f0554e2bb5e8226a206bfa1bfa577c70b552c8989fb7a1d54669"))
(301495, uint256("0x69f7a337b714ca63bc0f256313749edd089c1014bb163e67d85e764309b68366"))
(334852, uint256("0x8c447d9cc8e7d3523ed3a162d8e48c9832a836fab5c5bf53fb68cb14802271d3"))
(350676, uint256("0xe804c7cb80c876d9abca757dbf46b6608bb2f92cfba25b9ce37519e872292156"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
