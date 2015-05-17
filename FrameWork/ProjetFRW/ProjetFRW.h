#ifndef PROJETFRW_H
#define PROJETFRW_H

#include <iostream>

#include "core\Expression.h"
#include "core\BinaryExpression.h"
#include "core\UnaryExpression.h"
#include "core\ValueModel.h"
#include "fuzzy\AndMin.h"
#include "fuzzy\AndMult.h"
#include "core\UnaryExpressionModel.h"
#include "core\BinaryExpressionModel.h"
#include "fuzzy\IsTriangle.h"
#include "fuzzy\IsTrapeze.h"
#include "fuzzy\NotMinus1.h"
#include "fuzzy\AggMax.h"
#include "fuzzy\AggPlus.h"
#include "fuzzy\CogDefuzz.h"
#include "fuzzy\OrMax.h"
#include "fuzzy\OrPlus.h"
#include "fuzzy\ThenMin.h"
#include "fuzzy\ThenMult.h"

typedef core::UnaryExpressionModel<NUMERIC> UnaryExpression;
typedef core::ValueModel<NUMERIC> ValueModel;
typedef core::BinaryExpressionModel<NUMERIC> BinaryExpression;
typedef fuzzy::AndMin<NUMERIC> AndMin;
typedef fuzzy::AndMult<NUMERIC> AndMult;
typedef fuzzy::AggMax<NUMERIC> AggMax;
typedef fuzzy::AggPlus<NUMERIC> AggPlus;
typedef fuzzy::CogDefuzz<NUMERIC> CogDefuzz;
typedef fuzzy::IsTrapeze<NUMERIC> IsTrapeze;
typedef fuzzy::IsTriangle<NUMERIC> IsTriangle;
typedef fuzzy::NotMinus<NUMERIC> NotMinus;
typedef fuzzy::OrMax<NUMERIC> OrMax;
typedef fuzzy::OrPlus<NUMERIC> OrPlus;
typedef fuzzy::ThenMin<NUMERIC> ThenMin;
typedef fuzzy::ThenMult<NUMERIC> ThenMult;

#endif