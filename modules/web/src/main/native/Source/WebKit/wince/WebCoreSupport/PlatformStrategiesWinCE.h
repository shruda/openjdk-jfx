/*
 * Copyright (C) 2010 Patrick Gansterer <paroga@paroga.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PlatformStrategiesWinCE_h
#define PlatformStrategiesWinCE_h

#include "CookiesStrategy.h"
#include "DatabaseStrategy.h"
#include "LoaderStrategy.h"
#include "PlatformStrategies.h"
#include "PluginStrategy.h"
#include "SharedWorkerStrategy.h"
#include "StorageStrategy.h"
#include "VisitedLinkStrategy.h"

class PlatformStrategiesWinCE : public WebCore::PlatformStrategies, private WebCore::CookiesStrategy, private WebCore::DatabaseStrategy, private WebCore::LoaderStrategy, private WebCore::PluginStrategy, private WebCore::SharedWorkerStrategy, private WebCore::StorageStrategy, private WebCore::VisitedLinkStrategy {
public:
    static void initialize();

private:
    PlatformStrategiesWinCE();

    // WebCore::PlatformStrategies
    virtual WebCore::CookiesStrategy* createCookiesStrategy() override;
    virtual WebCore::DatabaseStrategy* createDatabaseStrategy() override;
    virtual WebCore::LoaderStrategy* createLoaderStrategy() override;
    virtual WebCore::PasteboardStrategy* createPasteboardStrategy() override;
    virtual WebCore::PluginStrategy* createPluginStrategy() override;
    virtual WebCore::SharedWorkerStrategy* createSharedWorkerStrategy() override;
    virtual WebCore::StorageStrategy* createStorageStrategy() override;
    virtual WebCore::VisitedLinkStrategy* createVisitedLinkStrategy() override;

    // WebCore::CookiesStrategy
    virtual String cookiesForDOM(const WebCore::NetworkStorageSession&, const WebCore::URL& firstParty, const WebCore::URL&) override;
    virtual void setCookiesFromDOM(const WebCore::NetworkStorageSession&, const WebCore::URL& firstParty, const WebCore::URL&, const String&) override;
    virtual bool cookiesEnabled(const WebCore::NetworkStorageSession&, const WebCore::URL& firstParty, const WebCore::URL&) override;
    virtual String cookieRequestHeaderFieldValue(const WebCore::NetworkStorageSession&, const WebCore::URL& firstParty, const WebCore::URL&) override;
    virtual bool getRawCookies(const WebCore::NetworkStorageSession&, const WebCore::URL& firstParty, const WebCore::URL&, Vector<WebCore::Cookie>&) override;
    virtual void deleteCookie(const WebCore::NetworkStorageSession&, const WebCore::URL&, const String&) override;

    // WebCore::DatabaseStrategy
    // - Using default implementation.

    // WebCore::PluginStrategy
    virtual void refreshPlugins() override;
    virtual void getPluginInfo(const WebCore::Page*, Vector<WebCore::PluginInfo>&) override;

    // WebCore::VisitedLinkStrategy
    virtual bool isLinkVisited(WebCore::Page*, WebCore::LinkHash, const WebCore::URL&, const WTF::AtomicString&) override;
    virtual void addVisitedLink(WebCore::Page*, WebCore::LinkHash) override;
};

#endif // PlatformStrategiesWinCE_h
