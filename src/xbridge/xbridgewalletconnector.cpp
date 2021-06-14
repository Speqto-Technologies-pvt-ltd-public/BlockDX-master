//*****************************************************************************
//*****************************************************************************

#include "xbridgewalletconnector.h"
#include "xbridgetransactiondescr.h"

//*****************************************************************************
//*****************************************************************************
namespace xbridge
{

//*****************************************************************************
//*****************************************************************************
namespace wallet
{

//*****************************************************************************
//*****************************************************************************
std::string UtxoEntry::toString() const
{
    std::ostringstream o;
    o << txId << ":" << vout << ":" << amount << ":" << address;
    return o.str();
}

} // namespace wallet

//*****************************************************************************
//*****************************************************************************
WalletConnector::WalletConnector()
{

}

//******************************************************************************
//******************************************************************************
double WalletConnector::getWalletBalance() const
{
    std::vector<wallet::UtxoEntry> entries;
    if (!getUnspent(entries))
    {
        LOG() << "getUnspent failed " << __FUNCTION__;
        return -1.;//return negative value for check in called methods
    }

    double amount = 0;
    for (const wallet::UtxoEntry & entry : entries)
    {
        amount += entry.amount;
    }

    return amount;
}

} // namespace xbridge
