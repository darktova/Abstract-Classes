#include "Cell.h"
#include "BaseEl.h"
#include "DerivedEl.h"
#include "InhomList.h"

int main()
{
    if (static_cast<const std::string&>("1") > static_cast<const std::string&>("12"))
        return 1;
}
