// =============================================================================
//
// AboutDlg.cpp
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#include "AboutDlg.h"

AboutDlg::AboutDlg() {
    setupUi(this);

    QPixmap icon("icon/qt.png");
    this->iconLabel->setPixmap(icon);
}
