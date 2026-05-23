// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <QDialog>

namespace Ui {
class DiscordLinkDialog;
}

class DiscordLinkDialog : public QDialog {
    Q_OBJECT
public:
    explicit DiscordLinkDialog(QWidget* parent = nullptr);
    ~DiscordLinkDialog();

    static void showIfNeeded(QWidget* parent);

private slots:
    void onLinkClicked();
    void onDismiss();

private:
    Ui::DiscordLinkDialog* ui;
};
