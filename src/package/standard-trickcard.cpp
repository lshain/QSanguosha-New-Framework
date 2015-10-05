/********************************************************************
    Copyright (c) 2013-2015 - Mogara

    This file is part of QSanguosha.

    This game engine is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 3.0
    of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    See the LICENSE file for more details.

    Mogara
*********************************************************************/

#include "gamelogic.h"
#include "serverplayer.h"
#include "standardpackage.h"
#include "standard-trickcard.h"

GodSalvation::GodSalvation(Card::Suit suit, int number)
    : GlobalEffect(suit, number)
{
    setObjectName("god_salvation");
}

bool GodSalvation::isNullifiable(const CardEffectStruct &effect) const
{
    return effect.to->isWounded() && TrickCard::isNullifiable(effect);
}

void GodSalvation::onEffect(GameLogic *logic, CardEffectStruct &effect)
{
    if (effect.to->isWounded()) {
        RecoverStruct recover;
        recover.card = this;
        recover.from = effect.from;
        recover.to = effect.to;
        logic->recover(recover);
    }
}

void StandardPackage::addTrickCards()
{
}
