/*
 * IRoc.cpp
 *
 *  Copyright (c) 2019 hikyuu.org
 *
 *  Created on: 2019-5-18
 *      Author: fasiondog
 */

#include "IRoc.h"

#if HKU_SUPPORT_SERIALIZATION
BOOST_CLASS_EXPORT(hku::IRoc)
#endif

namespace hku {

IRoc::IRoc() : IndicatorImp("ROC", 1) {
    setParam<int>("n", 10);
}

IRoc::~IRoc() {}

bool IRoc::check() {
    return getParam<int>("n") >= 0;
}

void IRoc::_calculate(const Indicator& ind) {
    size_t total = ind.size();
    int n = getParam<int>("n");

    m_discard = ind.discard() + n;
    if (m_discard >= total) {
        m_discard = total;
        return;
    }

    if (0 == n) {
        price_t pre_price = ind[m_discard];
        if (pre_price != 0.0) {
            _set(0.0, m_discard);
            for (size_t i = m_discard + 1; i < total; i++) {
                _set((ind[i] / pre_price - 1.0) * 100, i);
            }
        } else {
            for (size_t i = m_discard; i < total; i++) {
                _set(0.0, i);
            }
        }
        return;
    }

    for (size_t i = m_discard; i < total; i++) {
        price_t pre_price = ind[i - n];
        if (pre_price != 0.0) {
            _set(((ind[i] / pre_price) - 1.0) * 100, i);
        } else {
            _set(0.0, i);
        }
    }
}

void IRoc::_dyn_run_one_step(const Indicator& ind, size_t curPos, size_t step) {
    size_t start = 0;
    if (0 == step) {
        start = ind.discard();
    } else if (curPos < ind.discard() + step) {
        return;
    } else {
        start = curPos - step;
    }

    _set(ind[start] != 0.0 ? ((ind[curPos] / ind[start]) - 1.0) * 100 : 0.0, curPos);
}

Indicator HKU_API ROC(int n) {
    IndicatorImpPtr p = make_shared<IRoc>();
    p->setParam<int>("n", n);
    return Indicator(p);
}

Indicator HKU_API ROC(const IndParam& n) {
    IndicatorImpPtr p = make_shared<IRoc>();
    p->setIndParam("n", n);
    return Indicator(p);
}

} /* namespace hku */
