/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi <drf@kdemod.ath.cx>                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef MTPINTERFACE_H
#define MTPINTERFACE_H

#include "AbstractDeviceInterface.h"

#include <QVariant>

class MtpInterface : public AbstractDeviceInterface
{
    Q_OBJECT

public:
    MtpInterface(QObject *parent, const QVariantList&);
    virtual ~MtpInterface();

    virtual void init();

    void scan();

public slots:
    void startWatching();
    void stopWatching();

    AbstractDevice *forceDeviceConnection();

private slots:
    void deviceAdded(const QString &udi);
    void deviceRemoved(const QString &udi);

private:
    bool isMtp(const QString &udi);
};

#endif /* MTPINTERFACE_H */
