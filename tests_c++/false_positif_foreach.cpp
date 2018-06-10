#include "nsAccessible.h"

class nsAccessibleWrap : public nsAccessible
{
  public: // construction, destruction
    nsAccessibleWrap(nsIDOMNode*, nsIWeakReference *aShell);
    virtual ~nsAccessibleWrap();

  protected:
     virtual nsresult FirePlatformEvent(nsIAccessibleEvent *aEvent) {
      return NS_OK;
    }
};
