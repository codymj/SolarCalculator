// =============================================================================
//
// AboutDlg.h
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#ifndef _ABOUTDLG_H_
#define _ABOUTDLG_H_

#include <QPixmap>
#include "ui_AboutDlg.h"

class AboutDlg : public QDialog, public Ui::AboutDlg {
    Q_OBJECT

public:
    AboutDlg();

private:

};

#endif // _ABOUTDLG_H_
