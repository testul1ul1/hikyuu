/*
 * export.cpp
 *
 *  Created on: 2013-4-29
 *      Author: fasiondog
 */

#include "../config.h"

#if HKU_SUPPORT_SERIALIZATION

#if HKU_SUPPORT_XML_ARCHIVE
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#endif /* HKU_SUPPORT_XML_ARCHIVE */

#if HKU_SUPPORT_TEXT_ARCHIVE
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#endif /* HKU_SUPPORT_TEXT_ARCHIVE */

#if HKU_SUPPORT_BINARY_ARCHIVE
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#endif /* HKU_SUPPORT_BINARY_ARCHIVE */

#include <boost/serialization/export.hpp>

#include "TradeManager.h"
#include "imp/TradeCostStub.h"
#include "imp/FixedATradeCost.h"
#include "imp/ZeroTradeCost.h"
#include "imp/FixedA2015TradeCost.h"
#include "imp/FixedA2017TradeCost.h"

BOOST_CLASS_EXPORT(hku::TradeManager)
BOOST_CLASS_EXPORT(hku::TradeManagerBase)
BOOST_CLASS_EXPORT(hku::TradeCostStub)
BOOST_CLASS_EXPORT(hku::FixedATradeCost)
BOOST_CLASS_EXPORT(hku::ZeroTradeCost)
BOOST_CLASS_EXPORT(hku::FixedA2015TradeCost)
BOOST_CLASS_EXPORT(hku::FixedA2017TradeCost)

#endif /* HKU_SUPPORT_SERIALIZATION */
