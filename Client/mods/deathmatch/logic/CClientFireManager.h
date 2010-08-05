/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CClientFireManager.h
 *  PURPOSE:     Fire entity manager class
 *  DEVELOPERS:  Fedor Sinev
 *
 *****************************************************************************/

class CClientFireManager;

#pragma once

#include "CClientManager.h"
#include "CClientFire.h"

class CClientFireManager
{
    friend class CClientManager;
    friend class CClientFire;

public:
    inline unsigned int Count(void) { return static_cast<unsigned int>(m_List.size()); };
    static CClientFire* Get(ElementID ID);

    void DeleteAll(void);
    bool Exists(CClientFire* pFire);

    inline std::list<CClientFire*>::const_iterator IterBegin(void) { return m_List.begin(); };
    inline std::list<CClientFire*>::const_iterator IterEnd(void) { return m_List.end(); };

private:
    CClientFireManager(CClientManager* pManager);
    ~CClientFireManager(void);

    void AddToList(CClientFire* pFire) { m_List.push_back(pFire); };
    void RemoveFromList(CClientFire* pFire)
    {
        if (!m_bDontRemoveFromList)
            if (!m_List.empty())
                m_List.remove(pFire);
    };

    CClientManager* m_pManager;

    std::list<CClientFire*> m_List;
    bool                    m_bDontRemoveFromList;
};
